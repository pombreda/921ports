# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mydumper
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://code.launchpad.net/mydumper/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	gslin@gslin.org
COMMENT=	MySQL Data Dumper

LICENSE=	GPLv3

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}

FETCH_ARGS?=	-pRr
PLIST_FILES=	sbin/mydumper sbin/myloader
USE_GNOME=	glib20
USE_PKGCONFIG=	build
USE_MYSQL=	yes
USES=		cmake

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mydumper ${WRKSRC}/myloader ${PREFIX}/sbin

.include <bsd.port.mk>
