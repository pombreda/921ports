# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	synce-gvfs
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE-GNOME/0.14

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GVFS module for access Windows Mobile devices

EXTRACT_DEPENDS=${NONEXISTENT}:${GVFS_PORTDIR}:patch
LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USES=        pathfix
USE_GNOME=	gnomeprefix gvfs
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

GVFS_PORTDIR=	${PORTSDIR}/devel/gvfs
GVFS_WRKSRC_CMD=cd ${GVFS_PORTDIR} && ${MAKE} -V WRKSRC


post-extract:
.for dir in common daemon
	${CP} `${GVFS_WRKSRC_CMD}`/${dir}/*.[ch] ${WRKSRC}/gvfs/${dir}
.endfor

.include <bsd.port.mk>
