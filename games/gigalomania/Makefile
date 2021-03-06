# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gigalomania
PORTVERSION=	0.25
CATEGORIES=	games
MASTER_SITES=	https://launchpadlibrarian.net/130757462/
DISTNAME=	${PORTNAME}src

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Open source 2D real time strategy god game

USE_ZIP=	yes
USE_SDL=	image mixer sdl

PORTDOCS=	readme.html

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CC=g++|CC=${CXX}|' \
		-e '/^CCFLAGS/ s|-O2|${CXXFLAGS}|; s|-O2||' \
		-e 's|/usr/X11R6|${LOCALBASE}|' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -exec ${GREP} -q "__linux" {} \; \
		-exec ${REINPLACE_CMD} 's|__linux|__FreeBSD__|' {} \;
	@${REINPLACE_CMD} 's|/opt/gigalomania/||g' \
		${WRKSRC}/gigalomania.desktop \
		${WRKSRC}/gigalomania_fullscreen.desktop
	@${REINPLACE_CMD} 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/game.cpp \
		${WRKSRC}/gamestate.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for dir in gfx islands sound
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR}
.endfor
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_fullscreen.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}64.png ${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
