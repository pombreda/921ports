# New ports collection makefile for:	p5-Amazon-SQS-Simple
# Date created:		2007-10-31
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Amazon-SQS-Simple
PORTVERSION=	1.06
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SWHITAKER
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	OO API for accessing the Amazon Simple Queue Service

BUILD_DEPENDS=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Amazon::SQS::Simple::Message.3 \
		Amazon::SQS::Simple::Queue.3 \
		Amazon::SQS::Simple::Base.3 \
		Amazon::SQS::Simple::SendResponse.3 \
		Amazon::SQS::Simple.3

SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
