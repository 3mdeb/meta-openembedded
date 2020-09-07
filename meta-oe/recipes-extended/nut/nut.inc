DESCRIPTION = "Network UPS Tools is a collection of programs which provide a \
 common interface for monitoring and administering UPS, PDU and SCD hardware."
HOMEPAGE = "https://networkupstools.org"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${S}/LICENSE-GPL2;md5=751419260aa954499f7abaabaa882bbe"

inherit autotools pkgconfig systemd useradd

NUT_USER = "nut"
NUT_GROUP = "${NUT_USER}"

USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM_${PN} = "-r ${NUT_GROUP}"
USERADD_PARAM_${PN} = "-r -g ${NUT_USER} -d ${localstatedir}/state/nut \
    -s /sbin/nologin -c \"Network UPS Tools\" ${NUT_USER}"

EXTRA_OECONF = " \
    --with-user=${NUT_USER} \
    --with-group=${NUT_GROUP} \
    --with-statepath=${localstatedir}/state/nut \
    --with-pidpath=${localstatedir}/state/nut \
    --with-altpidpath=${localstatedir}/state/nut \
    --with-systemdsystemunitdir=${systemd_unitdir}/system \
    "

PACKAGECONFIG ??= "serial usb"

PACKAGECONFIG[serial] = "--with-serial, --without-serial, , "
PACKAGECONFIG[usb] = "--with-usb, --without-usb, libusb1 libusb-compat, libusb1 libusb-compat"
PACKAGECONFIG[snmp] = "--with-snmp, --without-snmp, net-snmp, "
PACKAGECONFIG[neon] = "--with-neon, --without-neon, neon, "
# it depends on freeipmi - there seem to be no Yocto recipe for it
PACKAGECONFIG[ipmi] = "--with-ipmi, --without-ipmi, , "
PACKAGECONFIG[powerman] = "--with-powerman, --without-powerman, , "
PACKAGECONFIG[cgi] = "--with-cgi, --without-cgi, , "
PACKAGECONFIG[dev] = "--with-dev, --without-dev, , "
PACKAGECONFIG[avahi] = "--with-avahi, --without-avahi, avahi, "
PACKAGECONFIG[i2c] = "--with-linux_i2c, --without-linux_i2c, , "
PACKAGECONFIG[doc] = "--with-doc, --without-doc, , "

PACKAGES =+ " \
    ${PN}-driver-al175 \
    ${PN}-driver-apcsmart \
    ${PN}-driver-apcsmart-old \
    ${PN}-driver-apcupsd-ups \
    ${PN}-driver-bcmxcp \
    ${PN}-driver-bcmxcp-usb \
    ${PN}-driver-belkin \
    ${PN}-driver-belkinunv \
    ${PN}-driver-bestfcom \
    ${PN}-driver-bestfortress \
    ${PN}-driver-bestuferrups \
    ${PN}-driver-bestups \
    ${PN}-driver-blazer-ser \
    ${PN}-driver-blazer-usb \
    ${PN}-driver-clone \
    ${PN}-driver-clone-outlet \
    ${PN}-driver-dummy-ups \
    ${PN}-driver-etapro \
    ${PN}-driver-everups \
    ${PN}-driver-gamatronic \
    ${PN}-driver-genericups \
    ${PN}-driver-isbmex \
    ${PN}-driver-ivtscd \
    ${PN}-driver-liebert \
    ${PN}-driver-liebert-esp2 \
    ${PN}-driver-masterguard \
    ${PN}-driver-metasys \
    ${PN}-driver-mge-shut \
    ${PN}-driver-mge-utalk \
    ${PN}-driver-microdowell \
    ${PN}-driver-netxml-ups \
    ${PN}-driver-nutdrv-atcl-usb \
    ${PN}-driver-nutdrv-qx \
    ${PN}-driver-oldmge-shut \
    ${PN}-driver-oneac \
    ${PN}-driver-optiups \
    ${PN}-driver-powercom \
    ${PN}-driver-powerpanel \
    ${PN}-driver-rhino \
    ${PN}-driver-richcomm-usb \
    ${PN}-driver-riello-ser \
    ${PN}-driver-riello-usb \
    ${PN}-driver-safenet \
    ${PN}-driver-skel \
    ${PN}-driver-snmp-ups \
    ${PN}-driver-solis \
    ${PN}-driver-tripplite \
    ${PN}-driver-tripplitesu \
    ${PN}-driver-tripplite-usb \
    ${PN}-driver-usbhid-ups \
    ${PN}-driver-victronups \
    "

FILES_${PN}-driver-al175 = "${bindir}/al175"
FILES_${PN}-driver-apcsmart = "${bindir}/apcsmart"
FILES_${PN}-driver-apcsmart-old = "${bindir}/apcsmart-old"
FILES_${PN}-driver-apcupsd-ups = "${bindir}/apcupsd-ups"
FILES_${PN}-driver-bcmxcp = "${bindir}/bcmxcp "
FILES_${PN}-driver-bcmxcp-usb = "${bindir}/bcmxcp_usb "
FILES_${PN}-driver-belkin = "${bindir}/belkin "
FILES_${PN}-driver-belkinunv = "${bindir}/belkinunv "
FILES_${PN}-driver-bestfcom = "${bindir}/bestfcom "
FILES_${PN}-driver-bestfortress = "${bindir}/bestfortress "
FILES_${PN}-driver-bestuferrups = "${bindir}/bestuferrups "
FILES_${PN}-driver-bestups = "${bindir}/bestups "
FILES_${PN}-driver-blazer-ser = "${bindir}/blazer_ser"
FILES_${PN}-driver-blazer-usb = "${bindir}/blazer_usb "
FILES_${PN}-driver-clone = "${bindir}/clone "
FILES_${PN}-driver-clone-outlet = "${bindir}/clone-outlet"
FILES_${PN}-driver-dummy-ups = "${bindir}/dummy-ups"
FILES_${PN}-driver-etapro = "${bindir}/etapro"
FILES_${PN}-driver-everups = "${bindir}/everups"
FILES_${PN}-driver-gamatronic = "${bindir}/gamatronic"
FILES_${PN}-driver-genericups = "${bindir}/genericups"
FILES_${PN}-driver-isbmex = "${bindir}/isbmex"
FILES_${PN}-driver-ivtscd = "${bindir}/ivtsdc"
FILES_${PN}-driver-liebert = "${bindir}/liebert"
FILES_${PN}-driver-liebert-esp2 = "${bindir}/liebert-esp2"
FILES_${PN}-driver-masterguard = "${bindir}/masterguard"
FILES_${PN}-driver-metasys = "${bindir}/metasys"
FILES_${PN}-driver-mge-shut = "${bindir}/mge-shut"
FILES_${PN}-driver-mge-utalk = "${bindir}/mge-utalk"
FILES_${PN}-driver-microdowell = "${bindir}/microdowell"
FILES_${PN}-driver-netxml-ups = "${bindir}/netxml-ups"
FILES_${PN}-driver-nutdrv-atcl-usb = "${bindir}/nutsrv_atcl_usb"
FILES_${PN}-driver-nutdrv-qx = "${bindir}/nutdrv_qx"
FILES_${PN}-driver-oldmge-shut = "${bindir}/oldmge-shut"
FILES_${PN}-driver-oneac = "${bindir}/oneac"
FILES_${PN}-driver-optiups = "${bindir}/optiups"
FILES_${PN}-driver-powercom = "${bindir}/powercom"
FILES_${PN}-driver-powerpanel = "${bindir}/powerpanel"
FILES_${PN}-driver-rhino = "${bindir}/rhino"
FILES_${PN}-driver-richcomm-usb = "${bindir}/richcomm_usb"
FILES_${PN}-driver-riello-ser = "${bindir}/riello_ser"
FILES_${PN}-driver-riello-usb = "${bindir}/riello_usb"
FILES_${PN}-driver-safenet = "${bindir}/safenet"
FILES_${PN}-driver-skel = "${bindir}/skel"
FILES_${PN}-driver-snmp-ups = "${bindir}/snmp-ups"
FILES_${PN}-driver-solis = "${bindir}/solis"
FILES_${PN}-driver-tripplite = "${bindir}/tripplite"
FILES_${PN}-driver-tripplitesu = "${bindir}/tripplitesu"
FILES_${PN}-driver-tripplite-usb = "${bindir}/tripplite_usb"
FILES_${PN}-driver-upsc = "${bindir}/upsc"
FILES_${PN}-driver-upscmd = "${bindir}/upscmd"
FILES_${PN}-driver-upscode2 = "${bindir}/upscode2"
FILES_${PN}-driver-upslog = "${bindir}/upslog"
FILES_${PN}-driver-upsrw = "${bindir}/upsrw"
FILES_${PN}-driver-upssched-cmd = "${bindir}/upssched-cmd"
FILES_${PN}-driver-usbhid-ups = "${bindir}/usbhid-ups"
FILES_${PN}-driver-victronups = "${bindir}/vitronups"

FILES_${PN}-doc += " \
    /usr/share/cmdvartab \
    /usr/share/driver.list \
    "

FILES_${PN} += " \
    ${libdir}/systemd/system-shutdown/nutshutdown \
    ${systemd_unitdir}/system/nut-server.service \
    ${systemd_unitdir}/system/nut-monitor.service \
    ${systemd_unitdir}/system/nut-driver.service \
    "

SYSTEMD_PACKAGES = " \
    ${PN} \
    "

SYSTEMD_SERVICE_${PN} = " \
    nut-server.service \
    nut-monitor.service \
    nut-driver.service \
    "

SYSTEMD_AUTO_ENABLE_${PN} = "enable"

do_install_append() {
    # create NUT state dir
    install -d -m 0770 -o root -g ${NUT_GROUP} ${D}${localstatedir}/state/nut
}
