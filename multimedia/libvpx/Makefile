# $NetBSD: Makefile,v 1.28 2013/10/23 18:24:02 adam Exp $

DISTNAME=	libvpx-v1.2.0
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	multimedia
MASTER_SITES=	http://webm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/webm/
COMMENT=	On2 VP8 library from Google
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake bash:build perl:build
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${BASH}
CONFIGURE_ARGS+=	--disable-postproc
CONFIGURE_ARGS+=	--enable-pic
CONFIGURE_ARGS+=	--enable-runtime-cpu-detect
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-unit-tests

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

REPLACE_BASH=		configure \
			build/make/configure.sh \
			build/make/version.sh \
			build/make/gen_asm_deps.sh \
			build/make/rtcd.sh \
			examples/gen_example_text.sh \
			examples/gen_example_code.sh

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-Wl,-Bsymbolic
.  if ${MACHINE_ARCH} == "i386"
.    if !empty(OS_VERSION:M12.*) || !empty(OS_VERSION:M13.*)
CONFIGURE_ARGS+=	--target=x86-darwin12-gcc
.    elif !empty(OS_VERSION:M11.*)
CONFIGURE_ARGS+=	--target=x86-darwin11-gcc
.    elif !empty(OS_VERSION:M10.*)
CONFIGURE_ARGS+=	--target=x86-darwin10-gcc
.    elif !empty(OS_VERSION:M9.*)
CONFIGURE_ARGS+=	--target=x86-darwin9-gcc
.    else
CONFIGURE_ARGS+=	--target=x86-darwin8-gcc
.    endif
.  elif ${MACHINE_ARCH} == "x86_64"
.    if !empty(OS_VERSION:M12.*) || !empty(OS_VERSION:M13.*)
CONFIGURE_ARGS+=	--target=x86_64-darwin12-gcc
.    elif !empty(OS_VERSION:M11.*)
CONFIGURE_ARGS+=	--target=x86_64-darwin11-gcc
.    elif !empty(OS_VERSION:M10.*)
CONFIGURE_ARGS+=	--target=x86_64-darwin10-gcc
.    else
CONFIGURE_ARGS+=	--target=x86_64-darwin9-gcc
.    endif
.  endif
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH}
CONFIGURE_ARGS+=	--target=mips32-linux-gcc
.endif

BUILD_TARGET=	# none

post-extract:
	${CP} ${FILESDIR}/strip_fPIC.sh ${WRKSRC}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
