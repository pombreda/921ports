# $FreeBSD$

PORTNAME=	gio
PORTVERSION=	0.12.4
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GIO

LICENSE=	LGPL21
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	glib>=0.12.0 mtl
USE_PKGCONFIG=	build

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
