# New ports collection makefile for:	goffice
# Date created:				07 June 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/goffice/Makefile,v 1.32 2007/09/06 05:01:28 marcus Exp $
#

PORTNAME=	goffice
PORTVERSION=	0.4.3
PORTREVISION=	13
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre

NO_LATEST_LINK=	yes

DEPRECATED=    depends on libgsf_gnome which is going away, also no users for this port.
EXPIRATION_DATE=2013-04-12

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprint libglade2 \
		libgsf_gnome libgnomeui ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's, *UTF-8 support, *UTF-8 .*support,g' \
	${WRKSRC}/configure

.include <bsd.port.mk>
