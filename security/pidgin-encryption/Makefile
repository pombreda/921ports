# New ports collection Makefile for: pidgin-encryption
# Date created:		2004-05-01
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	pidgin
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}-encrypt/Releases/${PORTVERSION}
PKGNAMESUFFIX=	-encryption
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	perlfu@gmail.com
COMMENT=	Encryption Plugin for the Pidgin instant messenger client

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin
LIB_DEPENDS=	purple.10:${PORTSDIR}/net-im/libpurple \
		nss3:${PORTSDIR}/security/nss

USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-nspr-includes=${LOCALBASE}/include/nspr	\
		--with-nspr-libs=${LOCALBASE}/lib	\
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib/nss

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h"|glib.h"|g' ${WRKSRC}/rsa_nss.c

.include <bsd.port.mk>
