# $FreeBSD$
#

PORTNAME=	Term-Clui
PORTVERSION=	1.66
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl module offering a Command-Line User Interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Term-Size>=0:${PORTSDIR}/devel/p5-Term-Size \
		p5-Term-ReadKey>=2.14:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Term::Clui.3 \
		Term::Clui::FileSelect.3


.include <bsd.port.mk>
