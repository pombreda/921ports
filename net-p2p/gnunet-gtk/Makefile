# ex:ts=8
# Ports collection makefile for:	gnunet-gtk
# Date created:				Dec. 19, 2011
# Whom:					bf
#
# $FreeBSD$
#

PORTNAME=		gnunet-gtk
DISTVERSION=		0.9.3
CATEGORIES=		net-p2p ipv6 security
MASTER_SITES=		GNU
MASTER_SITE_SUBDIR=	gnunet

MAINTAINER=	bf@FreeBSD.org
COMMENT=	GTK interface to GNUnet

LICENSE=	GPLv3

LIB_DEPENDS=	gladeui-1:${PORTSDIR}/devel/glade3 \
		gnunetutil:${PORTSDIR}/net-p2p/gnunet

INSTALLS_ICONS =	yes
USE_AUTOTOOLS=		libltdl libtool
USE_GMAKE=		yes
USE_GNOME=		gnomehack
USE_ICONV=		yes
USE_LDCONFIG=		yes

CONFIGURE_ARGS =	--with-extractor=${LOCALBASE} \
			--with-gnunet=${LOCALBASE} \
			--with-libiconv-prefix=${LOCALBASE}

MAN1=	gnunet-fs-gtk.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name 'Makefile.in' -print0 | \
	${XARGS} -0 ${REINPLACE_CMD} -e \
	'/^[[:blank:]]*mkinstalldirs[[:blank:]]*=/s/=.*/= $$(mkdir_p)/'

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
