# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libbonobo/Makefile,v 1.84 2010/09/26 20:57:33 kwm Exp $

PORTNAME=	libbonobo
PORTVERSION=	2.32.0
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A component and compound document system for GNOME2

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USES=		bison pathfix
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_GNOME=	intlhack libxml2 orbit2 referencehack
USE_PKGCONFIG=	build
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread
MAKE_ENV=	gnomelocaledir=${PREFIX}/share/locale

MAN1=		bonobo-activation-server.1

.include <bsd.port.mk>

.endif
