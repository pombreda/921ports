# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grafx2
PORTVERSION=	2.4.2035
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pixelart-oriented bitmap painting program

LIB_DEPENDS=	X11:${PORTSDIR}/x11/libX11 \
		png15:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_SDL=	sdl image
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}/src
CFLAGS+=	-DHAVE_SYS_PARAM_H -DHAVE_SYS_UCRED_H -DHAVE_SYS_MOUNT_H

OPTIONS_DEFINE=	TTF LUA
TTF_DESC=	True Type font support
OPTIONS_DEFAULT=TTF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTTF}
USE_SDL+=	ttf
.else
MAKE_ARGS+=	NOTTF=1
.endif

.if ${PORT_OPTIONS:MLUA}
USE_PKGCONFIG=	yes
USE_LUA=	5.1
.else
MAKE_ARGS+=	NOLUA=1
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^  prefix = .*$$|  prefix = ${PREFIX}|' \
		-e '/scripts\/libs/d' \
		-e 's/CC = gcc/CC ?= gcc/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|macosx|FreeBSD|g' \
		${WRKSRC}/mountlist.c ${WRKSRC}/init.c
	@${REINPLACE_CMD} \
		-e 's|Extract_path(program_dir, argv0);|strcpy(program_dir,"${PREFIX}/bin/");|' \
		${WRKSRC}/setup.c

.include <bsd.port.mk>
