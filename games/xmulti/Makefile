# New ports collection makefile for:   xmulti
# Date created:        4 Jun 1998
# Whom:                Toru YANO <toru@s-fine.co.jp>
#
# $FreeBSD$
#

PORTNAME=	xmulti
PORTVERSION=	2.00b4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.denpa.org/~go/xmulti/
DISTFILES=	xmul200b4.tgz

MAINTAINER=	toru@tenchi.ne.jp
COMMENT=	A X11 mascot based on gal-game "To Heart"

WRKSRC=		${WRKDIR}/xmulti200beta4

USE_IMAKE=	yes
USE_XORG=	x11 xext xaw xmu xt xpm sm ice

MAN1=		xmaid.1
NO_MANCOMPRESS=	yes
DOCSDIR=	${PREFIX}/share/doc/ja/{PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in MODULE.jp README.jp STYLESHEET.jp XMULTI.jp
	${INSTALL_MAN} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
