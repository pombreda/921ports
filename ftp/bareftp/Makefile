# Created by: Chris Petrik (chris@officialunix.com)
# $FreeBSD$

PORTNAME=	bareftp
PORTVERSION=	0.3.9
CATEGORIES=	ftp
MASTER_SITES=	http://www.bareftp.org/release/

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Ftp client made in C sharp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir="${PREFIX}/share" --libdir="${PREFIX}/lib" \
		--localedir="${PREFIX}/share/locale" --includedir="${LOCALBASE}/include"

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtksharp20 gnomesharp20
USE_GMAKE=	yes

USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

MAN1=		bareftp.1

OPTIONS_DEFINE=	GNOMEKEYRING
OPTIONS_DEFAULT=	GNOMEKEYRING

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOMEKEYRING}
KEYRING_DETECT=	${LOCALBASE}/libdata/pkgconfig/gnome-keyring-sharp-1.0.pc
BUILD_DEPENDS+=	${KEYRING_DETECT}:${PORTSDIR}/security/gnome-keyring-sharp
RUN_DEPENDS+=	${KEYRING_DETECT}:${PORTSDIR}/security/gnome-keyring-sharp
.else
CONFIGURE_ARGS+=	--without-gnomekeyring
.endif

# TODO
# Ugly way but configure ignore "--localedir=" fu* ;/
pre-build:
	@${REINPLACE_CMD} -e 's|$$(prefix)/$$(DATADIRNAME)|${PREFIX}/share|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
