# Created by: Oleg A. Mamontov <oleg@mamontov.net>
# $FreeBSD$

PORTNAME=	Tail-Stat
PORTVERSION=	0.20
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LONERR
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Real-time log statistics server

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Log-Dispatch>=2.26:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-Pid-File-Flock>=0:${PORTSDIR}/devel/p5-Pid-File-Flock \
		p5-Sys-Syslog>=0.16:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-Tie-Hash-Indexed>=0:${PORTSDIR}/devel/p5-Tie-Hash-Indexed
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP

PERL_CONFIGURE=	yes

USE_RC_SUBR=	tstatd
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

MAN1=		tstatd.1

MAN3=		Tail::Stat.3 \
		Tail::Stat::Plugin.3 \
		Tail::Stat::Plugin::apache.3 \
		Tail::Stat::Plugin::clamd.3 \
		Tail::Stat::Plugin::cvsupd.3 \
		Tail::Stat::Plugin::icecast.3 \
		Tail::Stat::Plugin::nginx.3 \
		Tail::Stat::Plugin::spamd.3

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
