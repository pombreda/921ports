# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thingylaunch
PORTVERSION=	1.1.4
CATEGORIES=	x11
MASTER_SITES=	http://www.gahr.ch/${PORTNAME}/	\
   		${MASTER_SITE_LOCAL}/gahr/ \
		http://people.freebsd.org/~gahr/distfiles/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A lightweight tab-completing launcher for X

LICENSE=	MIT

USE_XORG=	x11 xproto
USE_GNOME=	pkgconfig
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
