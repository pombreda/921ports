# Created by: Pedro Garcia Freitas <sawp@sawp.com.br>
# $FreeBSD$

PORTNAME=	mahotas
PORTVERSION=	0.9.6
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sawp@sawp.com.br
COMMENT=	Computer vision and image processing library for Python

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	freeimage:${PORTSDIR}/graphics/freeimage

USE_GCC=	4.6+
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
