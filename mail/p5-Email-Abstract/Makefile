# $NetBSD: Makefile,v 1.21 2013/09/08 07:38:02 wen Exp $

DISTNAME=	Email-Abstract-3.006
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ema
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Abstract/
COMMENT=	Perl5 module for writing representation-independent mail handling code
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	{perl>5.10,p5-Module-Pluggable>=1.5}:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/Email/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
