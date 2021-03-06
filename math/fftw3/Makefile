# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$
#    $MCom: ports-experimental/math/fftw3/Makefile,v 1.1 2006/03/28 00:08:57 ahze Exp $

PORTNAME=	fftw3
PORTVERSION=	3.3.3
PORTREVISION?=	1
CATEGORIES=	math
MASTER_SITES=	http://www.fftw.org/ \
		ftp://ftp.fftw.org/pub/fftw/
PKGNAMESUFFIX=	${FFTW3_PKGNAMESUFFIX}
DISTNAME=	fftw-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

#current flavors: default, float, long, and quad
FFTW3_FLAVOR?=	default
FFTW3_SUFX=

GNU_CONFIGURE=	yes
USES=	pathfix
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

CONFIGURE_ARGS =	--enable-shared --enable-threads --disable-fortran
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if ${FFTW3_FLAVOR} == "default"
MAN1=	fftw-wisdom-to-conf.1 fftw-wisdom.1
INFO=	fftw3
.else
#For non-default flavors, build and install the flavor-dependent components
#only, so that these flavors may coexist with the default flavor
MAN1=	fftw${FFTW3_SUFX}-wisdom.1
INSTALL_TARGET=	install-pkgconfigDATA install-libLTLIBRARIES install-exec
.endif

OPTIONS_DEFINE =	G77_WRAPPERS OPENMP OPTIMIZED_CFLAGS

G77_WRAPPERS_DESC=	Alter Fortran wrappers for use with g77
OPENMP_DESC=		Build OpenMP multithreaded libraries

OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENMP}
CONFIGURE_ARGS+=	--enable-openmp
PLIST_SUB+=	OPENMP=""
USE_GCC=	any
.else
CONFIGURE_ARGS+=	--disable-openmp
PLIST_SUB+=	OPENMP="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fstrict-aliasing
.  if !defined(WITH_DEBUG)
CFLAGS+=	-fomit-frame-pointer
.  endif
.  if ${ARCH} == "i386"
CFLAGS+=	-malign-double
.  endif
WITHOUT_NO_STRICT_ALIASING=	yes
.endif # end OPTIMIZED_CFLAGS

#Users must add altivec and avx to MACHINE_CPU when desired:
#this is not currently done in bsd.cpu.mk
.if ${FFTW3_FLAVOR} == "default"
.  if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=--enable-avx
.  elif !empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=--enable-sse2
.  endif
.elif ${FFTW3_FLAVOR} == "float"
FFTW3_SUFX=	f
FFTW3_PKGNAMESUFFIX=	-float
CONFIGURE_ARGS+=--enable-float
.  if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=--enable-avx
.  elif !empty(MACHINE_CPU:Msse)
CONFIGURE_ARGS+=--enable-sse
.  elif !empty(ARCH:Mpowerpc*) && !empty(MACHINE_CPU:Maltivec)
CONFIGURE_ARGS+=--enable-altivec
.  endif
.elif ${FFTW3_FLAVOR} == "long"
.  if ${OSVERSION} < 800000
ONLY_FOR_ARCHS =	i386 sparc64
LIB_DEPENDS+=	ml:${PORTSDIR}/math/ldouble
.  endif
FFTW3_SUFX=	l
FFTW3_PKGNAMESUFFIX=	-long
CONFIGURE_ARGS+=--enable-long-double
.elif ${FFTW3_FLAVOR} == "quad"
FFTW3_SUFX=	q
FFTW3_PKGNAMESUFFIX=	-quad
CONFIGURE_ARGS+=--enable-quad-precision
ONLY_FOR_ARCHS =	i386 amd64
USE_GCC=	4.6+
.endif

.if ${FFTW3_FLAVOR} == "default"
PLIST_SUB+=	DEF=""
.else
PLIST_SUB+=	DEF="@comment "
.endif

PLIST_SUB+=	FFTW3_SUFX="${FFTW3_SUFX}"

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/fftw|${PREFIX}/etc/fftw|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/api/import-system-wisdom.c \
		${WRKSRC}/doc/fftw3* \
		${WRKSRC}/tools/*
	@${REINPLACE_CMD} \
	-e '/libfftw3@PREC_SUFFIX@_threads\.la:/{N; \
	s/$$(LIBS)/$$(PTHREAD_LIBS) &/;}' \
		${WRKSRC}/threads/Makefile.in
.if ${FFTW3_FLAVOR} != "default"
	@${REINPLACE_CMD} -E \
	-e '/(DIST_COMMON|bin_SCRIPTS|BUILT_SOURCES|EXTRA_DIST) =/,\
	/[^\]$$/s/[^[:blank:]]*fftw-wisdom-to-conf[^[:blank:]]*//' \
		${WRKSRC}/tools/Makefile.in
.  if ${FFTW3_FLAVOR} == "long" && ${OSVERSION} < 800000
	@${REINPLACE_CMD} -e 's|-lm |-L${LOCALBASE}/lib -lml &|' \
		${WRKSRC}/configure
.  endif
.endif

post-patch-script:
	@${FIND} ${WRKSRC} -type f \( -name \*.bak -or -name \*.orig \) \
	-exec ${RM} -f {} \;

post-configure:
#After issuing --disable-fortran in order to avoid using a Fortran compiler
#during configuration, edit config.h to provide Fortran wrappers appropriate for
#gfortran, with ac_cv_f77_mangling="lower case, underscore, no extra underscore"
	@${REINPLACE_CMD} -e '/DISABLE_FORTRAN/d' ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_EQUIV 1" >> ${WRKSRC}/config.h
.if ${PORT_OPTIONS:MG77_WRAPPERS}
	@${ECHO_CMD} "#define WITH_G77_WRAPPERS 1" >> ${WRKSRC}/config.h
.endif

.if ${FFTW3_FLAVOR} != "default"
post-install:
	@${INSTALL_MAN} ${WRKSRC}/tools/fftw${FFTW3_SUFX}-wisdom.1 ${PREFIX}/man/man1
.endif

regression-test test: smallcheck

.for t in bigcheck check exhaustive-check paranoid-check smallcheck
${t}: build
	@cd ${WRKSRC}/tests; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} ${t}

.endfor

.include <bsd.port.post.mk>
