# Created by: Martin Matuska <martin@tradex.sk>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.2.15
PORTEPOCH=	1
CATEGORIES=	devel linux
MASTER_SITES=	http://www.libsdl.org/release/ \
		CRITICAL/rpm
DISTNAME=	${PORTNAME:U}-${PORTVERSION:S/.1$/-1/}-1

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (linux version)

CONFLICTS=	linux-f8-sdl12-[0-9]* linux-f10-sdl12-[0-9]*

# EXPIRATION_DATE is the EoL of the last 7.x release
EXPIRATION_DATE=2013-02-28
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	4
INSTALL_SHLIB=	yes

ONLY_FOR_ARCHS=	i386 amd64
DIST_SUBDIR=	rpm
PLIST=		${MASTERDIR}/pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	SDLVER=${PORTVERSION}

.include <bsd.port.mk>
