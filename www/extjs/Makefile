# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	extjs
PORTVERSION=	4.1.1
CATEGORIES=	www
MASTER_SITES=	http://cdn.sencha.io/ \
		http://extjs.cachefly.net/ \
		http://mirror.joehorn.idv.tw/extjs/
DISTNAME=	ext-${PORTVERSION}-gpl

MAINTAINER=	joehorn@gmail.com
COMMENT=	A JavaScript platform for rapid development of cross-browser web apps

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

WRKSRC=		${WRKDIR}/extjs-${PORTVERSION}

USE_ZIP=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

WWW_SUB=	"bootstrap.js build builds ext-all-debug-w-comments.js \
		 ext-all-debug.js ext-all-dev.js ext-all.js \
		 ext-debug-w-comments.js ext-debug.js ext-dev.js \
		 ext-neptune-debug-w-comments.js ext-neptune-debug.js \
		 ext-neptune.js	ext.js index.html license.txt locale \
		 pkgs release-notes.html resources src welcome"

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message

.if ${PORT_OPTIONS:MDOCS}
SUB_LIST+=	COMMENTDOCS=
.else
SUB_LIST+=	COMMENTDOCS="\# "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
SUB_LIST+=	COMMENTEXAMPLES=
.else
SUB_LIST+=	COMMENTEXAMPLES="\# "
.endif

do-install:
	@cd ${WRKSRC} && ${RM} -rf resources/sass/.sass-cache/*
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${WWW_SUB} ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
