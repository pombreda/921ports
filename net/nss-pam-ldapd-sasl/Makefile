# Created by: rflynn@acsalaska.net
# $FreeBSD$

PORTNAME=		nss-pam-ldapd
PKGNAMESUFFIX=		-sasl

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Advanced fork of nss_ldap with sasl support

LICENSE=		# pet portlint

OPTIONS_SET+=	SASL

SLAVE_PORT=		sasl # In case we come up with more
MASTERDIR=		${.CURDIR}/../nss-pam-ldapd

.include "${MASTERDIR}/Makefile"
