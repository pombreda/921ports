# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xorriso
PORTVERSION=	1.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTNAME=	libisoburn-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	ISO image manipulation tool based on Libburnia

LICENSE=	GPLv2

BUILD_DEPENDS=	libburn>=1.1.0:${PORTSDIR}/devel/libburn \
		libisofs>=1.1.2:${PORTSDIR}/devel/libisofs
RUN_DEPENDS=	libburn>=1.1.0:${PORTSDIR}/devel/libburn \
		libisofs>=1.1.2:${PORTSDIR}/devel/libisofs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
WANT_GNOME=	yes

INFO=		xorrecord xorriso xorrisofs
MAN1=		xorrecord.1 xorriso.1 xorrisofs.1

.include <bsd.port.mk>
