# Ports collection makefile for:  sarep
# Date created:                   Feb 18, 1999
# Whom:                           ache
#
# $FreeBSD$
#

PORTNAME=	sarep
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://sunsite.unc.edu/pub/linux/utils/text/
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line search and replace tool; written in Perl; handles regexps

RUN_DEPENDS=	p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS

EXTRACT_CMD=	$(SED)
EXTRACT_BEFORE_ARGS=	's=^\#!/usr/bin/perl =\#!${PERL} =' <
EXTRACT_AFTER_ARGS=	| ${TR} -d '\r' > ${WRKSRC}/sarep

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/sarep

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sarep ${PREFIX}/bin

.include <bsd.port.mk>
