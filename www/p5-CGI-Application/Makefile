# New ports collection makefile for:	CGI-Application
# Date created:				Mon Jan  1 10:52:22 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	CGI-Application
PORTVERSION=	4.50
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module intended to make it easier to create reusable web apps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA

PERL_CONFIGURE=	yes

MAN3=		CGI::Application.3 CGI::Application::Mailform.3

.include <bsd.port.mk>
