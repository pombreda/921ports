# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	electric
PORTVERSION=	9.03
CATEGORIES=	cad java
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.staticfreesoft.com/:1 \
		http://www.staticfreesoft.com/jmanual/:2
MASTER_SITE_SUBDIR=	${PORTNAME:S/-ng//}
PKGNAMESUFFIX=	-ng
EXTRACT_SUFX=
DISTFILES+=	${PORTNAME}Binary-${PORTVERSION}.jar
EXTRACT_ONLY=

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	A sophisticated VLSI design system

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/electric-ng
SUB_LIST+=	LIBFILES="${LIBFILES}" \
		JARFILE="${JARFILE}"
SUB_FILES=	electric-ng

OPTIONS_DEFINE=	BSH 3D IRSIM MANUAL
BSH_DESC=	Enable embedded java interpreter via BSH
3D_DESC=	Enable 3D visualization via Java3D
IRSIM_DESC=	Install IRSIM and 3D animation plugin
MANUAL_DESC=	Install documentation

OPTIONS_DEFAULT=	IRSIM MANUAL 3D

JARFILE=	${PORTNAME}Binary-${PORTVERSION}.jar
J3DLIB=		${LOCALBASE}/share/java/java3d/jar/j3dcore.jar
PLUGINDIR=	${PREFIX}/libexec/${PORTNAME}${PKGNAMESUFFIX}

DESKTOP_ENTRIES="Electric-NG" "${COMMENT}" "${PORTNAME}${PKGNAMESUFFIX}" \
			"${PORTNAME}${PKGNAMESUFFIX}" "Development;Electronics;Engineering;" ${FALSE}
PLIST_FILES+=	share/pixmaps/${PORTNAME}${PKGNAMESUFFIX}.png

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBSH} || exists(${JAVALIBDIR}/bsh.jar)
RUN_DEPENDS+=	${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh
LIBFILES+=	${JAVALIBDIR}/bsh.jar
.endif

.if ${PORT_OPTIONS:M3D} || exists(${J3DLIB})
RUN_DEPENDS+=	${J3DLIB}:${PORTSDIR}/java/java3d
.endif

.if ${PORT_OPTIONS:MIRSIM}
RUN_DEPENDS+=	${JAVALIBDIR}/jmf.jar:${PORTSDIR}/java/jmf
PLUGINS+=	electricSFS-9.03
LIBFILES+=	${PREFIX}/libexec/${PORTNAME}${PKGNAMESUFFIX}/electricSFS-9.03.jar
.endif

.if ${PORT_OPTIONS:MMANUAL}
DISTFILES+=	ElectricManual-9.03.pdf:2
PLIST_FILES+=	share/doc/${PORTNAME}${PKGNAMESUFFIX}/ElectricManual-9.03.pdf
PLIST_DIRS+=	share/doc/${PORTNAME}${PKGNAMESUFFIX}
.endif

.if defined(PLUGINS)
DISTFILES+=	electricSFS-9.03.jar:1
PLIST_FILES+=	libexec/${PORTNAME}${PKGNAMESUFFIX}/electricSFS-9.03.jar
PLIST_DIRS+=	libexec/${PORTNAME}${PKGNAMESUFFIX}
.endif

post-extract:
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -d ${WRKDIR} ${PORTNAME}Binary-${PORTVERSION}.jar \
		com/sun/electric/tool/user/help/helphtml/iconplug.png)

do-install:
	@${MKDIR} ${JAVAJARDIR}
.if ${PORT_OPTIONS:MMANUAL}
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${DISTDIR}/ElectricManual-9.03.pdf ${DOCSDIR}${PKGNAMESUFFIX}
.endif
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/electric-ng ${PREFIX}/bin

	${INSTALL_DATA} ${WRKDIR}/com/sun/electric/tool/user/help/helphtml/iconplug.png \
		${PREFIX}/share/pixmaps/${PORTNAME}${PKGNAMESUFFIX}.png

.if defined(PLUGINS)
	# Install plugins
	@${MKDIR} ${PLUGINDIR}/
	${INSTALL_DATA} ${DISTDIR}/electricSFS-9.03.jar ${PLUGINDIR}/
.endif

.include <bsd.port.mk>
