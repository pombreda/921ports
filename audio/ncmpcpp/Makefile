# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	ncmpcpp
PORTVERSION=	0.5.10
CATEGORIES=	audio
MASTER_SITES=	http://unkart.ovh.org/ncmpcpp/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A ncurses mpd client, clone of ncmpc with some new features

LIB_DEPENDS=	mpdclient:${PORTSDIR}/audio/libmpdclient \
		fftw3:${PORTSDIR}/math/fftw3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_NCURSES=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	automake aclocal libtool
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=	ncmpcpp.1
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	CURL CLOCK UTF8 TAGLIB OUTPUTS VISUALIZER
OPTIONS_DEFAULT=	CURL CLOCK OUTPUTS VISUALIZER
CURL_DESC=	Enable fetching lyrics from the Internet
CLOCK_DESC=	clock-screen support
TAGLIB_DESC=	taglib support
OUTPUTS_DESC=	Enable outputs screen
VISUALIZER_DESC=	Enable music visualizer screen

.include <bsd.port.options.mk>

.if defined(WITH_NCURSES_BASE)
# no need to use ncurses-config if we use ncurses from the base system
CONFIGURE_ARGS+=	NCURSES_CONFIG=/usr/bin/true
.endif

PLIST_FILES=	bin/ncmpcpp \
		%%DOCSDIR%%/config \
		%%DOCSDIR%%/keys \
		%%DOCSDIR%%/NEWS \
		%%DOCSDIR%%/AUTHORS \
		%%DOCSDIR%%/COPYING
PLIST_DIRS=	%%DOCSDIR%%

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl
.else
CONFIGURE_ARGS+=	--with-curl=no
.endif

.if ${PORT_OPTIONS:MCLOCK}
CONFIGURE_ARGS+=	--enable-clock
.else
CONFIGURE_ARGS+=	--disable-clock
.endif

.if ${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--disable-unicode
.endif

.if ${PORT_OPTIONS:MTAGLIB}
LIB_DEPENDS+=	tag:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--with-taglib
.else
CONFIGURE_ARGS+=	--with-taglib=no
.endif

.if ${PORT_OPTIONS:MOUTPUTS}
CONFIGURE_ARGS+=	--enable-outputs
.else
CONFIGURE_ARGS+=	--disable-outputs
.endif

.if ${PORT_OPTIONS:MVISUALIZER}
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
CONFIGURE_ARGS+=	--enable-visualizer
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/AUTHORS
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/doc/config ${DOCSDIR}/config
	${INSTALL_DATA} ${WRKSRC}/doc/keys ${DOCSDIR}/keys
.endif

	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
