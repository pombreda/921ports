# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	typo3
PORTVERSION=	6.0.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	Open Source content management system

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PHP=	ctype filter json mysql pcre session xml
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=52

TYPO3WWW=	www
TYPO3RELEASE=
TYPO3SITE=	${TYPO3WWW}/${PORTNAME}
TYPO3PKG=	${PORTNAME}-${PORTVERSION}
TYPO3SRC=	${PORTNAME}_src-${PORTVERSION}
TYPO3DUMMY=	dummy-${PORTVERSION}

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX} ${TYPO3DUMMY}${EXTRACT_SUFX}

OPTIONS_DEFINE=	APC CURL GD IMAGICK MBSTRING MYSQL ZLIB
APC_DESC=	Alternative PHP Cache
CURL_DESC=	cURL supprt
GD_DESC=	GDlib/freetype support
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MBSTRING_DESC=	${MULTIBYTE_DESC}
MYSQL_DESC=	Install MySQL Server
ZLIB_DESC=	zlib support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPC}
USE_PHP+=	apc
.endif

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	server
IGNORE_WITH_MYSQL=	41 50
.endif

.if ${PORT_OPTIONS:MZLIB}
USE_PHP+=	zlib
.endif

pre-install:
	${MV} ${WRKDIR}/${TYPO3DUMMY}/typo3conf/LocalConfiguration.php ${WRKDIR}/${TYPO3DUMMY}/typo3conf/LocalConfiguration.php.dist

do-install:
	${CP} -R ${WRKDIR}/${TYPO3DUMMY}/ ${PREFIX}/${TYPO3SITE}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${PREFIX}/${TYPO3WWW}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3SITE}
	${RM} ${PREFIX}/${TYPO3SITE}/typo3_src && \
		cd ${PREFIX}/${TYPO3SITE} && \
		${LN} -s ../${TYPO3SRC} typo3_src
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3WWW}/${TYPO3SRC}

.include <bsd.port.post.mk>
