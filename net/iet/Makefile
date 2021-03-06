# New ports collection makefile for:	iet
# Date created:		2011-02-25
# Whom:			Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iet
PORTVERSION=	1.4.20.2
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/iscsitarget/iscsitarget/${PORTVERSION}/
DISTNAME=	iscsitarget-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	delphij
PATCHFILES=	${PORTNAME}-${PORTVERSION}.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	The iSCSI Enterprise Target

LICENSE=	GPLv2

BUILD_WRKSRC=	${WRKSRC}/freebsd
INSTALL_WRKSRC=	${BUILD_WRKSRC}

MAN5=		ietd.conf.5
MAN8=		ietadm.8 ietd.8
MANCOMPRESSED=	maybe

USE_RC_SUBR=	ietd

KMODDIR=	${PREFIX}/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR} DATADIR=${DATADIR} SYSDIR="${SRC_BASE}/sys"

IET_CONF_FILES=	ietd.conf initiators.allow initiators.deny targets.allow

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel sources to build
.endif

.if ${OSVERSION} < 800107
BROKEN=		requires 8.0-RELEASE or higher
.endif

pre-install:
	${MKDIR} ${DATADIR} ${KMODDIR} ${ETCDIR}

post-install:
.for f in ${IET_CONF_FILES}
	@[ -f ${ETCDIR}/${f} ] || ${CP} ${DATADIR}/${f} ${ETCDIR}/
.endfor

.include <bsd.port.post.mk>
