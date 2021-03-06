# New ports collection makefile for:	pwcbsd
# Date created:				17 Feb 2006
# Whom:					Raaf <freebsd@luna.afraid.org>
#
# $FreeBSD$
#

PORTNAME=	pwcbsd
PORTVERSION=	1.4.1
PORTREVISION=	9
CATEGORIES=	multimedia sysutils kld
MASTER_SITES=	http://raaf.atspace.org/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi

MAINTAINER=	lme@FreeBSD.org
COMMENT=	The Linux pwc webcam driver ported to FreeBSD

CONFLICTS=	pwcview-[0-9]*

MAN4=		pwc.4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS=	PROGRAMS	"Build the programs"			on \
		MMAP		"Enable mmap support (MAY CRASH YOUR SYSTEM)"	off

.include <bsd.port.pre.mk>

.if (${OSVERSION} > 800063) && (${OSVERSION} < 800094)
BROKEN=		Please update to a newer version of FreeBSD 8
.endif

.if ${OSVERSION} >= 800094
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.kld \
		${FILESDIR}/extra-patch-pwc-ctrl.c \
		${FILESDIR}/extra-patch-pwc-v4l.c \
		${FILESDIR}/extra-patch-pwc.c \
		${FILESDIR}/extra-patch-pwc.h
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if defined(WITH_MMAP)
ALL_TARGET=	mmap
.else
ALL_TARGET=	all
.endif
.if !defined(WITHOUT_PROGRAMS)
ALL_TARGET+=	pwcview
PROGRAMS=	pwcview
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
MAN1=		pwcview.1
USE_SDL=	sdl
PLIST_SUB+=	PROGRAMS=""
.else
PLIST_SUB+=	PROGRAMS="@comment "
.endif

post-patch:
.if !defined(WITHOUT_PROGRAMS)
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
.endif

post-install:
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if !defined(WITHOUT_PROGRAMS)
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${PREFIX}/man/man1
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
