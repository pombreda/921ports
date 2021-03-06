# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e17-modules
PORTVERSION=	20120918
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	# Empty
DISTFILES=	# Empty

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Meta-port for e17 modules

NO_BUILD=	yes
WANT_EFL=	yes
E17_ARCH=	freebsd${OSREL}-${ARCH}

MODULES=	alarm comp-scale cpu deskshow diskio eektool elfe empris engage eooorg \
		everything-aspell everything-mpris everything-pidgin everything-places \
		everything-shotgun everything-wallpaper everything-websearch exebuf execwatch \
		flame forecasts iiirk itask mail mem moon mpdule net news \
		penguins photo places rain rmb screenshot slideshow snow \
		taskbar tclock uptime weather winlist-ng winselector wlan

COMP_SCALE_PATH=	scale
EVERYTHING_MPRIS_PATH=	evry-mpris
EVERYTHING_PIDGIN_PATH=	evry-pidgin
EVERYTHING_SHOTGUN_PATH=	evry-shotgun
EVERYTHING_WEBSEARCH_PATH=	evry-websearch

.for M in ${MODULES}
OPTIONS+=	${M:U:S,-,_,g} "Install ${M} module"
. if !defined(${M:U:S,-,_,g}_OFF)
OPTIONS+=	on
. else
OPTIONS+=	off
. endif
.endfor

.include <bsd.port.options.mk>

.for M in ${MODULES}
. if !defined(${M:U:S,-,_,g}_PATH)
${M:U:S,-,_,g}_PATH=	${M}
. endif
. if !defined(WITHOUT_${M:U:S,-,_,g})
RUN_DEPENDS+=	${LOCALBASE}/lib/enlightenment/modules/${${M:U:S,-,_,g}_PATH}/${E17_ARCH}/module.so:${PORTSDIR}/x11-wm/e17-module-${M}
. endif
.endfor

do-install:	# empty

.include <bsd.port.mk>
