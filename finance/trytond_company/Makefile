# New ports collection makefile for:	trytond_company
# Date created:		12 August, 2012
# Whom:			Matthias Petermann<matthias@petermann.it>
#
# $FreeBSD$
#

PORTNAME=	trytond_company
PORTVERSION=	2.4.0
CATEGORIES=	finance python
MASTER_SITES=	http://downloads2.tryton.org/${PORTVERSION:R}/

MAINTAINER=	matthias@petermann.it
COMMENT=	The Company Module for Tryton

LICENSE=	GPLv3

RUN_DEPENDS=	trytond>=2.4.0:${PORTSDIR}/finance/trytond \
		trytond_party>=2.4.0:${PORTSDIR}/finance/trytond_party \
		trytond_currency>=2.4.0:${PORTSDIR}/finance/trytond_currency

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
