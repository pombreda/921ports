# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	phat
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	phat

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of GTK+ widgets geared toward pro-audio apps

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=        pathfix
USE_GNOME=	gtk20 libgnomecanvas gnomehack
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
		-e 's|-Werror||g' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
