# $NetBSD: Makefile,v 1.46 2013/01/21 11:49:19 wiz Exp $
#

DISTNAME=	pyorbit-2.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyorbit/ORBit/}
PKGREVISION=	5
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyorbit/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for ORBit2
LICENSE=	gnu-lgpl-v2.1

PY_PATCHPLIST=	YES
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pyorbit-2.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_SELF_CONFLICT=	YES

BUILDLINK_API_DEPENDS.python26+= python26>=2.6.2nb4

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-std=c9x
.endif

do-test:
	(cd ${WRKSRC}/tests/c-inproc && ${PYTHONBIN} test-c-inproc.py)

.include "../../net/ORBit2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
