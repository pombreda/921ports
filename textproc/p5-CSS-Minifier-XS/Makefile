# New ports collection makefile for:	CSS-Minifier-XS
# Date created:	   18 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	CSS-Minifier-XS
PORTVERSION=	0.08
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS based CSS minifier

PERL_CONFIGURE=	yes

MAN3=		CSS::Minifier::XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Module-Build>=0.3500:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
