# Created by: Matthias Petermann<matthias@petermann.it>
# $FreeBSD$

PORTNAME=	trytond_product_cost_history
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	Tryton Application Platform (Product Cost History Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_product>=2.4.0:${PORTSDIR}/finance/trytond_product

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
