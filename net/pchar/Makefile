# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	pchar
PORTVERSION=	1.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.kitchenlab.org/www/bmah/Software/pchar/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bmah

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sandia Internet path characterization tool

GNU_CONFIGURE=	yes
MAN8=		pchar.8

.include <bsd.port.pre.mk>

CONFIGURE_ARGS= --with-pcap

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} README CHANGES FAQ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
