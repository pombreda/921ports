# New ports collection makefile for:	POE-Component-Client-SMTP
# Date created:	   24 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-SMTP
PORTVERSION=	0.22
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SMTP client POE component

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Filter-Transparent-SMTP>=0:${PORTSDIR}/mail/p5-POE-Filter-Transparent-SMTP
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		POE::Component::Client::SMTP.3

.include <bsd.port.mk>
