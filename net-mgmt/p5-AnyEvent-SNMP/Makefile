# New ports collection makefile for:	p5-AnyEvent-SNMP
# Date created:		2011-06-24
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-SNMP
PORTVERSION=	6.0
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Adaptor to integrate Net::SNMP into AnyEvent

RUN_DEPENDS=	p5-AnyEvent>=5.23:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Net-SNMP>=6.0.1:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-common-sense>=3.4:${PORTSDIR}/devel/p5-common-sense
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=	AnyEvent::SNMP.3

.include <bsd.port.mk>
