# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-PatchPerl
PORTVERSION=	0.84
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to patch perl source

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-pushd>=1.00:${PORTSDIR}/devel/p5-File-pushd
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		patchperl.1
MAN3=		Devel::PatchPerl.3 \
		Devel::PatchPerl::Hints.3 \
		Devel::PatchPerl::Plugin.3

.include <bsd.port.mk>
