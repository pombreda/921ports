# New ports collection makefile for:	drivel
# Date created:			Thu Feb 26 23:13:12 CET 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	drivel
PORTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/Drivel%20%28stable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog editor for GNOME

LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup

OPTIONS_DEFINE=	GTKSPELL
OPTIONS_DEFAULT=	GTKSPELL
GTKSPELL_DESC=	Enable GtkSpell support

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_GNOME=	gconf2 gnomedocutils gnomevfs2 gtksourceview2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--disable-error-on-warning

GCONF_SCHEMAS=	drivel.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-g2/s|^|#|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|make -C|$$(MAKE) -C|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/-ldl/s|^|#|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
