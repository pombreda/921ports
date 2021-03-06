# $FreeBSD$

PORTNAME=	photoprint
DISTVERSION=	0.4.2-pre2
CATEGORIES=	print graphics
MASTER_SITES=	http://www.blackfiveimaging.co.uk/photoprint/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Utility to print multiple images per sheet

LICENSE=	GPLv2

LIB_DEPENDS=	cups:${PORTSDIR}/print/cups-client \
		expat:${PORTSDIR}/textproc/expat2 \
		gdk_pixbuf-2.0:${PORTSDIR}/graphics/gdk-pixbuf2 \
		gutenprint:${PORTSDIR}/print/gutenprint \
		lcms:${PORTSDIR}/graphics/lcms \
		netpbm:${PORTSDIR}/graphics/netpbm \
		pcre:${PORTSDIR}/devel/pcre \
		pixman:${PORTSDIR}/x11/pixman \
		png15:${PORTSDIR}/graphics/png \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		tiff:${PORTSDIR}/graphics/tiff \
		xcb:${PORTSDIR}/x11/libxcb

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	desktopfileutils pango
USE_XORG=	x11 xau xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
INSTALLS_ICONS=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gstrfuncs.h|glib.h|g' \
		${WRKSRC}/gp_cppsupport/gprinter.cpp

post-install:
		-@update-desktop-database

.include <bsd.port.mk>
