# Created by: bms@FreeBSD.org
# $FreeBSD$

PORTNAME=		afaapps
PORTVERSION=		2.7
PORTREVISION=		4
CATEGORIES=		sysutils linux
MASTER_SITES=		ftp://ftp.us.dell.com/scsi-raid/
PKGNAMEPREFIX=		linux-
DISTNAME=		aacraid-util-rh8.0-${LINUX_RPM_ARCH}
DIST_SUBDIR=		rpm

MAINTAINER=		ports@FreeBSD.org
COMMENT=		DELL PowerEdge Raid Controller 2 (apps)

RESTRICTED=		binary redistribution license needs clarification

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	arts
ONLY_FOR_ARCHS=	i386 amd64
BRANDELF_FILES=	usr/sbin/afacli
SRC_DISTFILES=	# empty, no sources available

EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
EXTRACT_SUFX=		.tar.gz

RPMFILE=	${PORTNAME}-${PORTVERSION}-2.${LINUX_RPM_ARCH}.rpm

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKDIR} && ${RPM2CPIO} ${RPMFILE} | ${CPIO} -id --quiet && \
	    ${RM} ${RPMFILE} readme
	${RM} -rf ${WRKDIR}/dev
	${RM} ${WRKDIR}/usr/sbin/afacli
	${MV} ${WRKDIR}/usr/sbin/afacli.bin ${WRKDIR}/usr/sbin/afacli

.include <bsd.port.post.mk>
