# $NetBSD: Makefile,v 1.26 2013/06/06 12:53:42 wiz Exp $

DISTNAME=	polkit-qt-0.9.4
PKGREVISION=	16
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_KDE:=apps/KDE4.x/admin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://api.kde.org/kdesupport-api/kdesupport-apidocs/polkit-qt/html
COMMENT=	Qt Wrapper around PolicyKit
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	polkit-qt-core.pc.cmake polkit-qt-gui.pc.cmake polkit-qt.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../security/policykit/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
