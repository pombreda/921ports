# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	gctpc
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	misc geography
MASTER_SITES=	http://edcftp.cr.usgs.gov/pub/software/gctpc/
DISTNAME=	gctpc
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USGS General Cartographic Transformation Package (GCTP)

WRKSRC=		${WRKDIR}/${PORTNAME}/source

.include <bsd.port.options.mk>

USE_GMAKE=	yes
ALL_TARGET=	libgctpc.so.1

USE_LDCONFIG=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libgctpc.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libgctpc.so.1 ${PREFIX}/lib
	${LN} -sf libgctpc.so.1 ${PREFIX}/lib/libgctpc.so
	${MKDIR} ${PREFIX}/include/gctpc
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/gctpc
	${INSTALL_DATA} ${FILESDIR}/*.h ${PREFIX}/include/gctpc
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/* ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../README ${DOCSDIR}/README.main
.endif

.include <bsd.port.mk>
