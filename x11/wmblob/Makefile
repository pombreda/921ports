# New ports collection makefile for:	wmblob
# Date created:				Thu Feb  6 12:24:23 MSK 2003
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	wmblob
PORTVERSION=	1.0.3
PORTREVISION=	8
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.dockapps.org/files/155/541/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Showing moving blobs

USE_XORG=	xpm
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes

MAN1=		wmblob.1
PLIST_FILES=	bin/wmblob

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmblob ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/wmblob.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
