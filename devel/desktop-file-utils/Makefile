# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$
#   $MCom: ports/devel/desktop-file-utils/Makefile,v 1.8 2007/09/07 20:22:45 mezz Exp $

PORTNAME=	desktop-file-utils
PORTVERSION=	0.18
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A couple of command line utilities for working with desktop entries

USE_GNOME=	glib20
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lispdir
CONFIGURE_ENV=	EMACS="no"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		desktop-file-install.1 desktop-file-validate.1 \
		update-desktop-database.1

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PORT_MIMEDIRS=	${LOCALBASE}/share/applications

MIMEDIRS=	${PORT_MIMEDIRS}

RMDIRS=		${PORT_MIMEDIRS}

post-patch:
	@${SED} -e 's|%%MIMEDIRS%%|${MIMEDIRS}| ;\
		s|%%RMDIRS%%|${RMDIRS}| ; \
		s|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SED} -e 's|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/desktop-entry-mode.el \
	    	${PREFIX}/share/emacs/site-lisp/desktop-entry-mode.el
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
