# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Set-Object
PORTVERSION=	1.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manage sets of objects

LICENSE=	ART10

PERL_CONFIGURE=	yes

MAN3=		Set::Object.3 Set::Object::Weak.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes.pod README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
