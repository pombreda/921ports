# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	IO-Async-SSL
PORTVERSION=	0.08
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use SSL/TLS with IO::Async

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Async>=0.54:${PORTSDIR}/devel/p5-IO-Async\
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Mozilla-CA>=0:${PORTSDIR}/www/p5-Mozilla-CA
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	${LOCALBASE}/bin/socat:${PORTSDIR}/net/socat \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=		IO::Async::SSL.3 \
		IO::Async::SSLStream.3

.include <bsd.port.mk>
