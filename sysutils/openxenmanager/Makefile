# $NetBSD: Makefile,v 1.9 2013/10/10 14:42:33 ryoon Exp $
#

DISTNAME=	openxenmanager_0.r80+dfsg.orig
PKGNAME=	openxenmanager-0.0.80
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/o/openxenmanager/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/openxenmanager/
COMMENT=	Open source XenServer/Xen Cloud Platform interface
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_TOOLS+=	pax
USE_LANGUAGES=	# none
NO_BUILD=	yes

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.7.7:../../www/py-httplib2

INSTALLATION_DIRS=	bin share

REPLACE_PYTHON=		openxenmanager/*py openxenmanager/pygtk_chart/*py

OXMDIR=			${PREFIX}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Replace pathes
SUBST_FILES.path=	openxenmanager.sh
SUBST_VARS.path=	PYTHONBIN OXMDIR

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/openxenmanager.sh ${WRKSRC}

pre-configure:
	${FIND} ${WRKSRC}/openxenmanager -type f | grep pyc | xargs ${RM}
	${RM} ${WRKSRC}/openxenmanager/openxenmanager

do-install:
	cd ${WRKSRC} && \
		pax -rw  openxenmanager ${DESTDIR}${PREFIX}/share
	${INSTALL_SCRIPT} ${WRKSRC}/openxenmanager.sh \
		${DESTDIR}${PREFIX}/bin/openxenmanager

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
