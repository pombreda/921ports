# Created by: Brian Minard <bminard@flatfoot.ca>
# $FreeBSD$

PORTNAME=	Test-Warn
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to test methods for warnings

BUILD_DEPENDS=	p5-Carp>=1.22:${PORTSDIR}/devel/p5-Carp \
		p5-Sub-Uplevel>=0.12:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-Tree-DAG_Node>=1.02:${PORTSDIR}/devel/p5-Tree-DAG_Node
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Warn.3

.include <bsd.port.mk>
