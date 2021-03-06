$NetBSD: patch-imap_src_c-client_auth_gss.c,v 1.1 2012/10/10 19:45:49 markd Exp $

heimdal support from imap-uw package.

--- imap/src/c-client/auth_gss.c.orig	2008-06-04 18:18:34.000000000 +0000
+++ imap/src/c-client/auth_gss.c
@@ -26,6 +26,17 @@
  * Last Edited:	30 August 2006
  */
 
+#ifdef HEIMDAL_KRB5
+#include <gssapi/gssapi.h>
+#ifdef GSSAPI_GSSAPI_H_ /* older heimdals use GSSAPI_H_ */
+#include <gssapi/gssapi_krb5.h>
+#endif
+#include <krb5.h>
+#define gss_nt_service_name	GSS_C_NT_HOSTBASED_SERVICE
+#else
+#include <gssapi/gssapi_generic.h>
+#include <gssapi/gssapi_krb5.h>
+#endif
 
 long auth_gssapi_valid (void);
 long auth_gssapi_client (authchallenge_t challenger,authrespond_t responder,
@@ -64,15 +75,32 @@ long auth_gssapi_valid (void)
   OM_uint32 smn;
   gss_buffer_desc buf;
   gss_name_t name;
+  krb5_context ctx;
+  krb5_keytab kt;
+  krb5_kt_cursor csr;
+
+				/* make a context */
+  if (krb5_init_context (&ctx))
+   return NIL;
 				/* make service name */
   sprintf (tmp,"%s@%s",(char *) mail_parameters (NIL,GET_SERVICENAME,NIL),
 	   mylocalhost ());
   buf.length = strlen (buf.value = tmp);
 				/* see if can build a name */
   if (gss_import_name (&smn,&buf,GSS_C_NT_HOSTBASED_SERVICE,&name) !=
-      GSS_S_COMPLETE) return NIL;
-				/* remove server method if no keytab */
-  if (!kerberos_server_valid ()) auth_gss.server = NIL;
+      GSS_S_COMPLETE) {
+    krb5_free_context (ctx);	/* finished with context */
+    return NIL;
+  }
+
+				/* get default keytab */
+  if (!krb5_kt_default (ctx,&kt)) {
+				/* can do server if have good keytab */
+    if (!krb5_kt_start_seq_get (ctx,kt,&csr))
+	auth_gss.server = auth_gssapi_server;
+    krb5_kt_close (ctx,kt);	/* finished with keytab */
+  }
+  krb5_free_context (ctx);	/* finished with context */
   gss_release_name (&smn,&name);/* finished with name */
   return LONGT;
 }
