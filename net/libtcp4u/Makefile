# New ports collection makefile for:	libtcp4u
# Date created:				27 November 2001
# Whom:					Juraj Lutter <otis@sk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libtcp4u
PORTVERSION=	3.3.1
CATEGORIES=	net devel
MASTER_SITES=	http://membres.lycos.fr/phjounin/zip/ \
		ftp://ftp.wilbury.sk/pub/FreeBSD/local/distfiles/
DISTNAME=	tcp4u331

MAINTAINER=	otis@freebsd.sk
COMMENT=	TCP interface library

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/tcp4u.331/src
PATCH_WRKSRC=	${WRKDIR}/tcp4u.331

USE_ZIP=	yes

PLIST_FILES=	include/udp4u.h include/tcp4u.h \
		include/smtp4u.h include/http4u.h \
		lib/libtcp4ux.a

do-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/../Unix/Makefile
	${CP} ${WRKSRC}/../Unix/Makefile ${WRKSRC}

.include <bsd.port.mk>
