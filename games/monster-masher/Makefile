# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	monster
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	http://people.iola.dk/olau/monster-masher/source/
PKGNAMESUFFIX=	-masher
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gnomemm puzzle game where you have to clean the caves of monsters

LIB_DEPENDS=	gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		gconfmm-2.6:${PORTSDIR}/devel/gconfmm26 \
		glademm-2.4:${PORTSDIR}/devel/libglademm24

USE_BZIP2=	yes
USES=		pathfix
USE_GNOME=	gnomeprefix intlhack libgnome esound
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lesd

GCONF_SCHEMAS=	monster-masher.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/pixbuf-drawing.hpp

.include <bsd.port.mk>
