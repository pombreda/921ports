# Created by: Jona Joachim <walkingshadow@grummel.net>
# $FreeBSD$

PORTNAME=	freealut
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	audio linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.fc${LINUX_DIST_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free implementation of OpenAL ALUT standard (Linux version)

CONFLICTS=	linux-f8-freealut-[0-9]* linux-f10-freealut-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	openal
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64
DIST_SUBDIR=	rpm
AUTOMATIC_PLIST=yes
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS

.include <bsd.port.mk>
