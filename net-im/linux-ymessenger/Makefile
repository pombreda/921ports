# New ports collection makefile for:	linux-ymessenger
# Date created:		23 December 2003
# Whom:			Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	ymessenger
PORTVERSION=	1.0.6.1
CATEGORIES=	net-im
MASTER_SITES=	http://public.yahoo.com/%7Emmk/
PKGNAMEPREFIX=	linux-
DISTNAME=	rh9.${PORTNAME}-${PORTVERSION:C/\.([^\.]+)$/-\1/}.i386
DISTFILES=	${DISTNAME}.rpm ymessenger.bin
EXTRACT_ONLY=	${DISTNAME}.rpm

MAINTAINER=	sethk@meowfishies.com
COMMENT=	An RPM of Yahoo! Messenger instant messaging client

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgdk_pixbuf.so.2:${PORTSDIR}/graphics/linux-gdk-pixbuf \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386 amd64
STRIP=

SHARE_FILES=	yahoo_gnome.png yahoo_kde.xpm ymessenger.desktop\
		ymessenger.kdelnk

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for rpm in ${EXTRACT_ONLY}; do\
	    (cd ${WRKDIR} &&\
	    rpm2cpio.pl ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE}/$$rpm |\
	    ${CPIO} --quiet -idm);\
	done

pre-patch:
	${CP} -fp ${DISTDIR}/ymessenger.bin ${WRKDIR}/opt/ymessenger/bin

post-patch:
	${SED} -e 's:%%PREFIX%%:${PREFIX}:g' ${FILESDIR}/linux-ymessenger.sh >\
	    ${WRKDIR}/linux-ymessenger.sh

do-install:
	@${MKDIR} ${PREFIX}/libexec/linux-ymessenger
	@set -x; for share in ${SHARE_FILES}; do\
	    ${INSTALL_DATA} ${WRKDIR}/opt/ymessenger/bin/$$share\
	    ${PREFIX}/libexec/linux-ymessenger;\
	done
	${INSTALL_PROGRAM} ${WRKDIR}/opt/ymessenger/bin/ymessenger.bin\
	    ${PREFIX}/libexec/linux-ymessenger
	${INSTALL_SCRIPT} ${WRKDIR}/linux-ymessenger.sh\
	    ${PREFIX}/bin/linux-ymessenger
	@${MKDIR} ${PREFIX}/lib/linux-ymessenger
	${INSTALL_DATA} ${WRKDIR}/opt/ymessenger/lib/libgtkhtml.so.0\
	    ${PREFIX}/lib/linux-ymessenger

.include <bsd.port.mk>
