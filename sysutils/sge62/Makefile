# Created by: Brooks Davis <brooks@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sge
PORTVERSION=	${SGE_VERSION}
PORTREVISION=	3
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://gridengine.sunsource.net/files/documents/7/197/:src \
		${MASTER_SITE_LOCAL:S/$/:src/}
MASTER_SITE_SUBDIR=	brooks/:src
DISTNAME=	ge-V${SGE_RELEASE:S/.//}_TAG-src
DISTFILES=	${DISTNAME}.tar.gz:src
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sun Grid Engine, a batch queueing system

DEPRECATED=	Ancient and unsupported release
EXPIRATION_DATE=2013-03-01

OPTIONS_DEFINE=	BDB X11 QSH
OPTIONS_DEFAULT=	BDB X11 QSH
X11_DESC=	Qmon X11 GUI
QSH_DESC=	qsh (requires xterm on exec hosts)

.include <bsd.port.options.mk>

LATEST_LINK=	sge62
CONFLICTS=	sge-6.[013-9]* sge-5* sgeee-[0-9]* sge-0.*

NOT_FOR_ARCHS=	powerpc

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	${SGE_ROOT}/lib/${SGE_ARCH}

SGE_BASE?=	sge
SGE_ROOT=	${PREFIX}/${SGE_BASE}
SGE_ARCH=	fbsd-${ARCH}
SGE_BUILD_ARCH=	FREEBSD_${ARCH:U}
SGE_RELEASE=	6.2u2_1
SGE_VERSION=	${SGE_RELEASE:S/u/./:S/_/./:S/beta/.b/}

PLIST_SUB+=	SGE_ARCH=${SGE_ARCH}
PLIST_SUB+=	SGE_BASE=${SGE_BASE}

SUB_FILES=	pkg-message pkg-install
SUB_LIST+=	SGE_BASE=${SGE_BASE}

USE_RC_SUBR=	sge

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
WRKSRC=		${WRKDIR}/gridengine/source
TMP_SGE_ROOT=	${WRKDIR}/sgeroot
AIMK_CMD=	${SETENV} ${AIMK_ENV} ./aimk ${AIMK_ARGS}

# From DEFAULTPROGS in scripts/distinst
INST_PROGS=	man common \
		sge_qmaster \
		sge_execd \
		sge_shadowd \
		sge_shepherd \
		sge_coshepherd \
		qstat \
		qsub \
		qalter \
		qconf \
		qdel \
		qacct \
		qmod \
		qsh \
		utilbin \
		jobs \
		${QMON} \
		qhost \
		qmake \
		qtcsh \
		qping \
		qloadsensor.exe \
		sgepasswd \
		qquota

MANPREFIX=	${SGE_ROOT}
.include "${.CURDIR}/Makefile.man"
EXCEPTFILES=	arc_depend_irix.asc arc_depend_solaris.asc man testsuite

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif

.if ${PORT_OPTIONS:MBDB}
LIB_DEPENDS=	db-4.2:${PORTSDIR}/databases/db42
PLIST_SUB+=	BDB_SPOOL=
.else
AIMK_ARGS+=	-spool-classic
PLIST_SUB+=	BDB_SPOOL="@comment "
.endif

AIMK_ARGS+=	-no-java -no-jni -no-gui-inst

.if ${PORT_OPTIONS:MX11}
USE_MOTIF=	yes
PLIST_SUB+=	QMON=
QMON=		qmon
.else
AIMK_ARGS+=	-no-qmon
PLIST_SUB+=	QMON="@comment "
QMON=		noqmon
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
	    -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
	    -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
	    ${WRKSRC}/dist/util/arch_variables \
	    ${WRKSRC}/dist/pvm/src/aimk
	@${REINPLACE_CMD} -e "s|%%CC%%|${CC}|g" \
	    -e "s|%%CXX%%|${CXX}|g" \
	    -e "s|%%CFLAGS%%|${CFLAGS}|g" \
	    -e "s|%%CXXFLAGS%%|${CXXFLAGS}|g" \
	    -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
	    ${WRKSRC}/aimk \
	    ${WRKSRC}/dist/pvm/src/aimk
.if ${OSVERSION} > 900007
	@test \! -d ${WRKSRC}/3rdparty/qtcsh/${SGE_BUILD_ARCH} || \
	    (cd ${WRKSRC}/3rdparty/qtcsh/${SGE_BUILD_ARCH} && \
	     patch -p0 < ${FILESDIR}/qtcsh-config.h.diff)
	@test -d ${WRKSRC}/3rdparty/qtcsh/${SGE_BUILD_ARCH} || \
	    (cd ${WRKSRC}/3rdparty/qtcsh/FREEBSD_I386 && \
	     patch -p0 < ${FILESDIR}/qtcsh-config.h.diff)
.endif
	@test -d ${WRKSRC}/3rdparty/qtcsh/${SGE_BUILD_ARCH} || \
	    (${CP} -r ${WRKSRC}/3rdparty/qtcsh/FREEBSD_I386 \
		${WRKSRC}/3rdparty/qtcsh/${SGE_BUILD_ARCH} && \
	     ${REINPLACE_CMD} -e 's|FREEBSD_I386|${SGE_BUILD_ARCH}|' \
		${WRKSRC}/3rdparty/qtcsh/${SGE_BUILD_ARCH}/Makefile)
	@${REINPLACE_CMD} -e 's|^CC = gcc|CC = ${CC}|' \
	    -e 's|^CPP = gcc -E|CPP = ${CPP}|' \
	    ${WRKSRC}/3rdparty/qmake/FREEBSD_*/Makefile \
	    ${WRKSRC}/3rdparty/qmake/FREEBSD_*/glob/Makefile \
	    ${WRKSRC}/3rdparty/qtcsh/${SGE_BUILD_ARCH}/Makefile
	@${RM} ${WRKSRC}/dist/util/arch_variables.orig
	@${RM} ${WRKSRC}/dist/util/create_settings.sh.orig
	@${RM} ${WRKSRC}/dist/util/install_modules/inst_common.sh.orig
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
	    ${REINPLACE_CMD} "s|-g -O2|${CFLAGS}|"
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%OPENSSLBASE%%|${OPENSSLBASE}|g' \
	    -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${FILESDIR}/aimk.private > ${WRKSRC}/aimk.private
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%OPENSSLBASE%%|${OPENSSLBASE}|g' \
	    -e 's|%%WRKDIR%%|${WRKDIR}|g' \
	    ${FILESDIR}/distinst.private > ${WRKSRC}/distinst.private
.if ! ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e 's/qmon//' ${WRKSRC}/dist/util/setfileperm.sh
.endif

do-build:
	@cd ${WRKSRC} && ${AIMK_CMD} -only-depend
	@cd ${WRKSRC} && ./scripts/zerodepend
	@cd ${WRKSRC} && ${AIMK_CMD} depend
	@cd ${WRKSRC} && \
	    ${AIMK_CMD} -debug && \
	    ${AIMK_CMD} -man ${SGE_PRODUCT}
	@${MKDIR} ${TMP_SGE_ROOT}
	@cd ${WRKSRC} && ${SETENV} SGE_ROOT=${TMP_SGE_ROOT} \
	    ./scripts/distinst -local -libs ${SGE_ARCH} -- ${INST_PROGS}
.if ! ${PORT_OPTIONS:MQSH}
	@${RM} ${TMP_SGE_ROOT}/bin/${SGE_ARCH}/qlogin
	@${RM} ${TMP_SGE_ROOT}/bin/${SGE_ARCH}/qrsh
	@${MV} ${TMP_SGE_ROOT}/bin/${SGE_ARCH}/qsh ${TMP_SGE_ROOT}/bin/${SGE_ARCH}/qrsh
	@${LN} -s qrsh ${TMP_SGE_ROOT}/bin/${SGE_ARCH}/qlogin
	@${INSTALL_SCRIPT} ${FILESDIR}/qsh-disabled.sh ${TMP_SGE_ROOT}/bin/${SGE_ARCH}/qsh
.endif
.if ! ${PORT_OPTIONS:MX11}
	@${RM} ${TMP_SGE_ROOT}/catman/cat/cat1/qmon.1
	@${RM} -r ${TMP_SGE_ROOT}/3rd_party/qmon
.endif

do-install:
	@${MKDIR} ${SGE_ROOT}
	@cd ${TMP_SGE_ROOT} && \
	    ${FIND} . | ${TAR} cTf - - | ${TAR} xUCf ${SGE_ROOT} -
	@cd ${SGE_ROOT} && ${SETENV} SGE_ROOT=${SGE_ROOT} util/setfileperm.sh -auto ${SGE_ROOT}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/../doc && ${FIND} * \( -name CVS \
	    ${EXCEPTFILES:S/^/-o -name /} \) -a -prune -o -type f -print \
	    | ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

# Automaticly produce the offical machine dependent bits tarball from
# the temporary root.  This can be used if FreeBSD machines are to be
# included in a shared SGE installation.
release-tar: build
	cd ${TMP_SGE_ROOT} && \
	    ${TAR} cfvz ${.CURDIR}/sge-${SGE_RELEASE}-bin-${SGE_ARCH}.tar.gz \
	    `${FIND} . -name ${SGE_ARCH}`

#########################################################################
# Maintainer support below this line.  No user servicable parts inside. #
#########################################################################

# Build a pkg-plist and Makefile.man
build-plist:
.if ! ${PORT_OPTIONS:MBDB} || ! ${PORT_OPTIONS:MX11}
	@echo "ERROR: All OPTIONS must be enabled to build plist!" && ${FALSE}
.endif
	@${FIND} ${TMP_SGE_ROOT}/* -name man -prune -o \
	    \( -type f -o -type l \) -print | \
	    ${SORT} | \
	    ${SED} -e 's|^${TMP_SGE_ROOT}|%%SGE_BASE%%|' \
		-e 's|${SGE_ARCH}|%%SGE_ARCH%%|' \
		-e 's|\(.*libspool[bc].so\)|%%BDB_SPOOL%%\1|' \
		-e 's|\(.*libdb-4.2.so\)|%%BDB_SPOOL%%\1|' \
		-e 's|\(.*utilbin.*db_.*\)|%%BDB_SPOOL%%\1|' \
		-e 's|\(.*libXltree.so\)|%%QMON%%\1|' \
		-e 's|\(.*qmon.*\)|%%QMON%%\1|' \
	    > ${PLIST}
	@${FIND} ${WRKSRC}/../doc \( -name CVS \
	    ${EXCEPTFILES:S/^/-o -name /} \) -a -prune -o -type f -print | \
	    ${SORT} | \
	    ${SED} -e 's|${WRKSRC}/../doc|%%PORTDOCS%%%%DOCSDIR%%|' \
	    >> ${PLIST}
	@${FIND} ${TMP_SGE_ROOT}/* -type d | \
	    ${SORT} -r | \
	    ${SED} -e 's|^${TMP_SGE_ROOT}|@dirrm %%SGE_BASE%%|' \
		-e 's|${SGE_ARCH}|%%SGE_ARCH%%|' \
		-e 's|\(.*qmon.*\)|%%QMON%%\1|' \
	    >> ${PLIST}
	@${FIND} ${WRKSRC}/../doc \( -name CVS \
	    ${EXCEPTFILES:S/^/-o -name /} \) -a -prune -o -type d -print | \
	    ${SORT} -r | \
	    ${SED} -e 's|${WRKSRC}/../doc|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' \
	    >> ${PLIST}
	@echo '@dirrmtry %%SGE_BASE%%' >> ${PLIST}
	@echo '@unexec test ! -d %D/%%SGE_BASE%% || ( echo "Configuration information saved.  If you will *NOT* use this package anymore," && echo "please remove %D/%%SGE_BASE%% and its contents manually.")' >> ${PLIST}
	@echo "# Do not edit!  Auto-generated file." > ${.CURDIR}/Makefile.man
	@echo "# See build-plist target in Makefile." >> ${.CURDIR}/Makefile.man
	@echo "#" >> ${.CURDIR}/Makefile.man
	@${FIND} ${TMP_SGE_ROOT}/man -type f | ${XARGS} ${GREP} -H ^\\.so | \
	    ${SED} \
	    -e 's|.*/\([^ :/][^ :/]*\):.*/\([^ :/][^ :/]*\)$$|MLINKS+=\2 \1|' \
	    >> ${.CURDIR}/Makefile.man
	@${FIND} ${TMP_SGE_ROOT}/man -type f | ${XARGS} ${GREP} -L ^\\.so | \
	    ${SED} -e 's|.*man\([0-9LN]\)/\(.*\)|MAN\1+=\2|' \
	    >> ${.CURDIR}/Makefile.man

.include <bsd.port.mk>
