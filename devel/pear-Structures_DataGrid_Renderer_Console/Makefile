# Ports collection makefile for:	pear-Structures_DataGrid_Renderer_Console
# Date created:				26 Jun 2008
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid_Renderer_Console
PORTVERSION=	0.1.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console_Table Renderer for pear-Structures_DataGrid

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table

CATEGORY=	Structures
FILES=		DataGrid/Renderer/Console.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
