# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libsigc++20/Makefile,v 1.17 2011/07/25 09:19:14 kwm Exp $

PORTNAME=	libsigc++
PORTVERSION=	2.2.10
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool
USE_XZ=		yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
LATEST_LINK=	libsigc++20
USE_LDCONFIG=	yes
USES=	pathfix
GNU_CONFIGURE=	yes

PLIST_SUB=	VERSION="2.0" API_VERSION="2.0"

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-documentation=no
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||; \
		/^SUBDIRS =/s|examples||" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
