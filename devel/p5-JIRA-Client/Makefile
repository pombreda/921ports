# New ports collection makefile for:	JIRA::Client
# Date created:		2009-04-28
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JIRA-Client
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/glarkin
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	An extended interface to JIRA's SOAP API

RUN_DEPENDS=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
PROJECTHOST=	jira-client

MAN3=		JIRA::Client.3

.include <bsd.port.mk>
