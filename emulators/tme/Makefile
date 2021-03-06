# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	tme
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://people.csail.mit.edu/fredette/tme/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for Sun 2/120, 3/150, and SPARCstation 2 machines

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

USE_GNOME=	gdkpixbuf2 gtk20
USE_PERL5=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool libltdl
CONFIGURE_ENV=	ac_cv_have_isinff=no
CONFIGURE_ARGS=	--datadir=${WRKDIR}/tmproot --disable-warnings
USE_PKGCONFIG=	build
USE_XORG=	pixman x11 xau xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
USE_LDCONFIG=	yes
MAKE_ENV=	LANG=C
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${WRKSRC}/ic/ieee754/.libs
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/misc_hosts/s|= no|= xno|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\.\./ieee754|$$(top_builddir)/ic/ieee754|g' \
		${WRKSRC}/ic/m68k/Makefile.in
	@${REINPLACE_CMD} -e 's|\.\./ieee754|$$(top_builddir)/ic/ieee754|g' \
		${WRKSRC}/ic/sparc/Makefile.in
	@${REINPLACE_CMD} -e '/^#ifdef/s|\*/||' \
		${WRKSRC}/libtme/misc.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/libtme/module.c

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKDIR}/tmproot/examples/tme \
		&& ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
