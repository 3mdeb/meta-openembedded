require nut.inc

# the git build fals at:
# SYSTEMD_SERVICE_nut value nut-driver.service does not exist

DEFAULT_PREFERENCE = "-1"

BRANCH= "master"

SRC_URI = "git://github.com/networkupstools/nut.git;protocol=https;branch=${BRANCH}"

SRCREV = "e24b9a8412d4032cf7557f86a04748081ec249d5"

S = "${WORKDIR}/git"

do_configure_prepend() {
     ( cd ${S}; ./autogen.sh )
}
