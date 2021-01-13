/*
 *  expidus1-notifyd
 *
 *  Copyright (c) 2008 Brian Tarricone <bjt23@cornell.edu>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License ONLY.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include <glib/gstdio.h>

#include <gtk/gtk.h>

#include <xfconf/xfconf.h>
#include <libexpidus1util/libexpidus1util.h>
#include <libexpidus1ui/libexpidus1ui.h>

#include "expidus-notify-daemon.h"

int
main(int argc,
     char **argv)
{
    ExpidusNotifyDaemon *xndaemon;
    GError *error = NULL;

    xfconf_init(NULL);
 	
    gtk_init(&argc, &argv);

    expidus_textdomain(GETTEXT_PACKAGE, LOCALEDIR, "UTF-8");

    if(argc > 1) {
        if(!strcmp(argv[1], "--version") || !strcmp(argv[1], "-V")) {
            g_print("%s %s\n", _("Expidus Notify Daemon"), VERSION);
            return 0;
        } else {
            g_printerr(_("Unknown option \"%s\"\n"), argv[1]);
            return 1;
        }
    }

    xndaemon = expidus_notify_daemon_new_unique(&error);
    if(!xndaemon) {
        expidus_message_dialog(NULL, _("Expidus Notify Daemon"),
                            "dialog-error",
                            _("Unable to start notification daemon"),
                            error->message,
                            "application-exit", GTK_RESPONSE_ACCEPT,
                            NULL);
        g_error_free(error);
        return 1;
    }

    gtk_main();

    g_object_unref(G_OBJECT(xndaemon));

    return 0;
}
