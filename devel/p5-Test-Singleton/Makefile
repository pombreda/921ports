# New ports collection makefile for:	p5-Test-Singleton
# Date created:		2006-07-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Singleton
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TPG
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Test for Singleton classes

RUN_DEPENDS=	p5-Class-Singleton>=0:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Singleton.3

.include <bsd.port.mk>
