# New ports collection Makefile for:	kfreerings
# Date created:				2004-02-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kfreerings
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	games kde
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b./beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small puzzle game

LIB_DEPENDS=	kdegames.3:${PORTSDIR}/games/kdegames3

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
