# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compiz-plugins-main
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugins for Compiz Composite Window Manager

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		pangocairo-1.0:${PORTSDIR}/x11-toolkits/pango
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
		${LOCALBASE}/libdata/pkgconfig/bcop.pc:${PORTSDIR}/devel/compiz-bcop
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GL=		yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=        pathfix
USE_GNOME=	intltool
USE_XORG=	glproto
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

GCONF_SCHEMAS=	compiz-animation.schemas \
		compiz-colorfilter.schemas \
		compiz-expo.schemas \
		compiz-ezoom.schemas \
		compiz-imgjpeg.schemas \
		compiz-kdecompat.schemas \
		compiz-mag.schemas \
		compiz-mousepoll.schemas \
		compiz-neg.schemas \
		compiz-opacify.schemas \
		compiz-put.schemas \
		compiz-resizeinfo.schemas \
		compiz-ring.schemas \
		compiz-staticswitcher.schemas \
		compiz-session.schemas \
		compiz-snap.schemas \
		compiz-text.schemas \
		compiz-thumbnail.schemas \
		compiz-wall.schemas \
		compiz-winrules.schemas \
		compiz-workarounds.schemas \
		compiz-scaleaddon.schemas \
		compiz-titleinfo.schemas \
		compiz-vpswitch.schemas \
		compiz-shift.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-schemas

.include <bsd.port.mk>
