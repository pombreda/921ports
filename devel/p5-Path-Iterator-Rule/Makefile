# $FreeBSD$

PORTNAME=	Path-Iterator-Rule
PORTVERSION=	0.012
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for iterative, recursive file finder

RUN_DEPENDS=	\
	p5-Data-Clone>0:${PORTSDIR}/devel/p5-Data-Clone \
	p5-Number-Compare>=0.02:${PORTSDIR}/math/p5-Number-Compare \
	p5-Text-Glob>0:${PORTSDIR}/textproc/p5-Text-Glob \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-File-pushd>0:${PORTSDIR}/devel/p5-File-pushd \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Path-Tiny>0:${PORTSDIR}/devel/p5-Path-Tiny \
	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep \
	p5-Test-Filename>0:${PORTSDIR}/devel/p5-Test-Filename

PERL_CONFIGURE=	yes

MAN3=	PIR.3 \
	Path::Iterator::Rule.3

.include <bsd.port.mk>
