# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Mount remote ftp directories

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USES=		fuse
USE_GNOME=	glib20
USE_PKGCONFIG=	build
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/curlftpfs

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk> 
