# New ports collection makefile for:	dynamite
# Date Created:				10 January 2005
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	libdynamite
PORTVERSION=	0.1.1
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/Dynamite/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decompress data compressed with PKWARE Data Compression Library

MAKE_JOBS_SAFE=	yes

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USES=	pathfix
USE_LDCONFIG=	yes

MAN1=		dynamite.1

.include <bsd.port.mk>
