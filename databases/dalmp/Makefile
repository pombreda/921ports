# Created by: Nicolas de Bari Embriz <nbari@dalmp.com>
# $FreeBSD$

PORTNAME=	dalmp
PORTVERSION=	2.1
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nbari@dalmp.com
COMMENT=	Database Abstraction Layer for MySQL using PHP

LICENSE=	BSD

USE_BZIP2=	YES

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

NO_BUILD=	YES
USE_PHP=	pcre mysql mysqli session memcache sqlite3 curl

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/ ${DATADIR}

.include <bsd.port.mk>
