# Created by: Muhammad Moinur Rahmanh <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	commons-math3
PORTVERSION=	3.1
CATEGORIES=	math java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-math3,math,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Java library of self-contained mathematics and statistics components

BUILD_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVAJARDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVAJARDIR}/commons-discovery.jar:${PORTSDIR}/java/jakarta-commons-discovery
RUN_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVAJARDIR}/commons-discovery.jar:${PORTSDIR}/java/jakarta-commons-discovery

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

ALL_TARGET=	jar
MAKE_ARGS=	-Dlibdir=${WRKDIR} -Dnoget=true \
		-Dcommons-logging.jar="file://${JAVAJARDIR}/commons-logging.jar" \
		-Dcommons-discovery.jar="file://${JAVAJARDIR}/commons-discovery.jar"

COMMONS_LOGGING_API=	${LOCALBASE}/share/doc/commons-logging/api
.if exists(${COMMONS_LOGGING_API})
MAKE_ARGS+=	-Dcommons-logging.api=${COMMONS_LOGGING_API}
.endif

COMMONS_DISCOVERY_API=	${LOCALBASE}/share/doc/commons-discovery/api
.if exists(${COMMONS_DISCOVERY_API})
MAKE_ARGS+=	-Dcommons-logging.api=${COMMONS_DISCOVERY_API}
.endif

JARFILE=	${PORTNAME:S,3,,}-${PORTVERSION}-SNAPSHOT.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${DESTJARFILE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
OTHERDOCS=	LICENSE.txt NOTICE.txt
PORTDOCS=	apidocs ${OTHERDOCS}
.endif

JDK_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jdk1.? -maxdepth 1 -name api -type d 2>/dev/null || ${TRUE}) | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Djdk.api=${JDK_API}
.endif

post-patch:
	${REINPLACE_CMD} -e 's#4.4##g' \
			-e 's#junit-#junit#g' \
			-e 's#/usr/share/junit#${JAVAJARDIR}#g' \
			${WRKSRC}/build.xml

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/target/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/target \
	  && ${FIND} -s apidocs -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} -s apidocs -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
