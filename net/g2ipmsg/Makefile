# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	g2ipmsg
PORTVERSION=	0.9.3
PORTREVISION=	7
CATEGORIES=	net gnome
MASTER_SITES=	http://www.ipmsg.org/archive/ \
		${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~nork/distfiles/
MASTER_SITE_SUBDIR=	nork
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A popup style message communication tool for GNOME2

USE_GETTEXT=	yes
USE_GMAKE=	yes
USES=        pathfix
USE_GNOME=	gnomeprefix intlhack intltool \
		libgnomeui libbonobo desktopfileutils gnomepanel
USE_GSTREAMER=	vorbis
USE_PKGCONFIG=	build
USE_ICONV=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-systray --with-ssl=${OPENSSLBASE}

GCONF_SCHEMAS=	g2ipmsg.schemas

LDFLAGS+=	"-L${LOCALBASE}/lib"

post-install:
	@update-desktop-database

.include <bsd.port.mk>
