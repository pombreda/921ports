# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Compress-Lzf
PORTVERSION=	2.060
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write lzf files / buffers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-LZF>=0:${PORTSDIR}/archivers/p5-Compress-LZF \
		p5-IO-Compress>=2.060:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=		IO::Compress::Lzf.3 IO::Uncompress::UnLzf.3

.include <bsd.port.mk>
