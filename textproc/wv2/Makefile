# New ports collection makefile for:    wv2
# Date created:         Do 28 Aug 2003 15:50:37 CEST
# Whom:                 lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	wv2
PORTVERSION=	0.4.2
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/wvware/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A library providing routines to access Microsoft Word files

USE_GNOME=	libgsf
USE_ICONV=	yes
USE_BZIP2=	yes
USES=		cmake
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|glib/giochannel.h|glib.h|g' \
		${WRKSRC}/src/olestream.h

.include <bsd.port.mk>
