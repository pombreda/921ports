# Created by: Jim Mock <jimFreeBSD.org>
# $FreeBSD$

PORTNAME=	erwn
PORTVERSION=	0.8
PORTREVISION=	12
CATEGORIES=	www editors
MASTER_SITES=	http://lisas.de/erwin/
DISTNAME=	erwin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK+-2 HTML editor

USES=        pathfix
USE_GNOME=	gnomeprefix gtksourceview gtkhtml3
USE_GMAKE=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes

MAN1=		erwin.1

post-patch:
	@${REINPLACE_CMD} -e "s|gtkhtml-3.6|gtkhtml-3.14|g" \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
