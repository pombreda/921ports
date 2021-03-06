# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sablot
PORTVERSION=	0.5.2
PORTREVISION=	9
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubycolor.org/arc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Ruby interface to the Sablotron XSLT processor

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron \
		expat.6:${PORTSDIR}/textproc/expat2

USE_ICONV=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sablot-lib="${LOCALBASE}" \
		--with-iconv="${LOCALBASE}" \
		--with-expat="${LOCALBASE}"
INSTALL_TARGET=	site-install

DOCS_EN=	README	\
		doc/sablot.html \
		doc/sablot.rd
DOCS_JA=	doc/sablot_ja.html \
		doc/sablot.rd.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
