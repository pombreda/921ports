# New ports collection makefile for:	ubh
# Date created:			1 January 2002
# Whom:				John Holland <john@zoner.org>
#
# $FreeBSD$
#

PORTNAME=	ubh
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	news graphics
MASTER_SITES=	http://ubh.sourceforge.net/download/

MAINTAINER=	john@zoner.org
COMMENT=	Perl script to download and decode binaries posted to Usenet

RUN_DEPENDS=	\
	p5-News-Newsrc>=0:${PORTSDIR}/news/p5-News-Newsrc \
	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
	p5-String-CRC32>=0:${PORTSDIR}/devel/p5-String-CRC32

NO_BUILD=	YES
USE_PERL5=	YES

pre-patch:
	@${MV} ${WRKSRC}/ubh ${WRKSRC}/ubh.old
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		${WRKSRC}/ubh.old > ${WRKSRC}/ubh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ubh ${PREFIX}/bin
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/ubh
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ubh
	${INSTALL_DATA} ${WRKSRC}/doc/ubh.html ${PREFIX}/share/doc/ubh
.endif

.include <bsd.port.mk>
