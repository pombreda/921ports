# Created by: ijliao
# $FreeBSD$

PORTNAME=	truevision
PORTVERSION=	0.5.5.2
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/0.5.5
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNOME 3D modeler

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USES=        pathfix
USE_GNOME=	gnomeprefix intlhack libgnomeui
USE_GL=		gl
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		truevision.1

CPPFLAGS+=	-I${LOCALBASE}/include \
		`pkg-config --cflags gtkglext-1.0`
LDFLAGS+=	-L${LOCALBASE}/lib \
		`pkg-config --libs gtkglext-1.0`

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS=""||g ; \
		 s|-I/usr/include/gtkglext-1.0/||g ; \
		 s|-I/usr/local/include/gtkglext-1.0/||g ; \
		 s|-I/usr/lib/gtkglext-1.0/include/||g ; \
		 s|-I/usr/local/lib/gtkglext-1.0/include/||g ; \
		 s|-I/usr/local/include ||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-I/usr/include||g ; \
		 s|-I/usr/local/include||g ; \
		 s|-I/usr/X11R6/include||g ; \
		 s|-L/usr/lib||g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-L/usr/X11R6/lib||g ; \
		 s|-O2||g ; \
		 s|^truevisiondoc|#truevisiondoc|g'

.include <bsd.port.mk>
