# Created by: KANOU Hiroki <kanou@mil.allnet.ne.jp>
# $FreeBSD$

PORTNAME=	autotrace
PORTVERSION=	0.31.1
PORTREVISION=	23
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/AutoTrace/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert bitmap to vector graphics

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	IMAGEMAGICK MING PSTOEDIT
OPTIONS_DEFAULT=	IMAGEMAGICK PSTOEDIT
MING_DESC=	Enable swf interface
PSTOEDIT_DESC=	Convert postscript to other formats

USES=	pathfix
USE_PKGCONFIG=	build
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE= yes
CPPFLAGS+=	$$(libpng-config --I_opts) ${PTHREAD_CFLAGS}
LDFLAGS+=	$$(libpng-config --L_opts) ${PTHREAD_LIBS}

MAN1=		autotrace.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	MagickWand:${PORTSDIR}/graphics/ImageMagick
.else
CONFIGURE_ARGS+=	--without-magick
.endif

.if ${PORT_OPTIONS:MMING}
LIB_DEPENDS+=	ming:${PORTSDIR}/graphics/ming
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ming
.else
CONFIGURE_ENV+=	ac_cv_header_ming_h=no
.endif

.if ${PORT_OPTIONS:MPSTOEDIT}
LIB_DEPENDS+=	pstoedit:${PORTSDIR}/graphics/pstoedit
.else
CONFIGURE_ARGS+=	--without-pstoedit
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|Magick-config|MagickWand-config|g ; \
		/$$PSTOEDIT_CONFIG/s|--version|--modversion| ; \
		s|$$PSTOEDIT_CONFIG $$pstoedit_args|pkg-config pstoedit| ; \
		/^PSTOEDIT_CONFIG=/s|=.*$$|=pkg-config|' ${WRKSRC}/configure

.include <bsd.port.mk>
