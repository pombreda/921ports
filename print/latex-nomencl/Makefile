# New ports collection makefile for:	latex-nomencl
# Date created:		31 July 2011
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	nomencl
PORTVERSION=	4.2.20050922
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ctan.org/tex-archive/%SUBDIR%/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/${PORTNAME}
PKGNAMEPREFIX=	latex-
DISTFILES=	${SRC_FILES} ${PORTDOCS}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package to generate a nomenclature using MakeIndex

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMF_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMF_LSR}:${PORTSDIR}/print/tex-texmflocal

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		TEXMFDIR=${TEXMFDIR}

TEXMFDIR=	share/texmf
TEXMF_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/etex
YES_CMD=	/usr/bin/yes
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	${SRC_FILES:S,^,${CLASSDIR}/,} \
		${CLASS_FILES:S,^,${CLASSDIR}/,}

SRC_FILES=	nomencl.dtx nomencl.ins
CLASS_FILES=	nomencl.sty
PORTDOCS=	README nomencl.pdf

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${YES_CMD} | ${TEX_BIN} nomencl.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${SRC_FILES} ${CLASS_FILES} \
		${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR} ${LOCALBASE}/${TEXMFDIR}

.include <bsd.port.mk>
