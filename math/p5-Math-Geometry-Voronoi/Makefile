# New ports collection makefile for:	Math-Geometry-Voronoi
# Date created:				12 July, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Math-Geometry-Voronoi
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to compute Voronoi diagrams from sets of points

BUILD_DEPENDS=	p5-Class-Accessor>=0.18:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::Geometry::Voronoi.3

.include <bsd.port.mk>
