# New ports collection makefile for:	HTTPD::Log::Filter
# Date created:		15 Feb 2002
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTPD-Log-Filter
PORTVERSION=	1.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWRIGLEY
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module to filter entries out of an httpd log

BUILD_DEPENDS=	p5-IO-Zlib>=0:${PORTSDIR}/archivers/p5-IO-Zlib
RUN_DEPENDS=	p5-IO-Zlib>=0:${PORTSDIR}/archivers/p5-IO-Zlib

PERL_CONFIGURE=	yes
MAN1=		exclude_robots.1
MAN3=		HTTPD::Log::Filter.3

.include <bsd.port.mk>
