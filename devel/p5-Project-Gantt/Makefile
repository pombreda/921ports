# New ports collection makefile for:	devel/p5-Project-Gantt
# Date created:				Thu Oct 21 16:46:26 CST 2004
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Project-Gantt
PORTVERSION=	1.03
PORTREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create Gantt charts to manage project scheduling

BUILD_DEPENDS=	p5-Class-Date>=0:${PORTSDIR}/devel/p5-Class-Date \
		convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/Gantt

MAN3=		Project::Gantt.3

.include <bsd.port.mk>
