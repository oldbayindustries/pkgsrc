# $NetBSD: Makefile,v 1.6 2012/10/23 19:51:08 asau Exp $
#

DISTNAME=		ir-account-0.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ir.bbn.com/~gdt/ir-account/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.ir.bbn.com/~gdt/ir-account/
COMMENT=		Copy accounts among systems and manage sudo privs

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

DEPENDS+=		sudo>=1.6:../../security/sudo

.include "../../mk/bsd.pkg.mk"
