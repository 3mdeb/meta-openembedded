SUMMARY = "ddcutil"

HOMEPAGE = "http://www.ddcutil.com"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

BRANCH = "master"

SRCREV = "bad10076ef3e5a1963be3cfab5b7d6f5a3bd5e51"

PV = "0.8.4+${SRCPV}"

SRC_URI = " \
    gitsm://git@github.com/rockowitz/ddcutil.git;branch=${BRANCH};protocol=ssh \
    "

# disable trying to fetch from mirrors
PREMIRRORS = ""
MIRRORS = ""

# ddcutil dependencies
# sudo apt-get install build-essential autoconf libtool libglib2.0-dev \
#     libglib2.0-dev i2c-tools libi2c-dev libusb-dev libdrm-dev libx11-dev \
#     libxrandr-dev libxrandr2 libdrm2 libusb-1.0 libudev-dev libgudev-1.0-0 \
#     libgudev-1.0-dev

DEPENDS += "\
    i2c-tools \
    libusb1 \
    libdrm \
    libgudev \
    "

RDEPENDS_${PN} += "\
    i2c-tools \
    i2c-tools-misc \
    libdrm \
    "

S = "${WORKDIR}/git/"

EXTRA_OECONF += "\
    --enable-drm --disable-usb --enable-lib --disable-doxygen \
    "

inherit autotools pkgconfig
