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

#ifndef __EXPIDUS_NOTIFY_DAEMON_H__
#define __EXPIDUS_NOTIFY_DAEMON_H__

#include <glib-object.h>

#define EXPIDUS_TYPE_NOTIFY_DAEMON     (expidus_notify_daemon_get_type())
#define EXPIDUS_NOTIFY_DAEMON(obj)     (G_TYPE_CHECK_INSTANCE_CAST((obj), EXPIDUS_TYPE_NOTIFY_DAEMON, ExpidusNotifyDaemon))
#define EXPIDUS_IS_NOTIFY_DAEMON(obj)  (G_TYPE_CHECK_INSTANCE_TYPE((obj), EXPIDUS_TYPE_NOTIFY_DAEMON))

G_BEGIN_DECLS

typedef struct _ExpidusNotifyDaemon  ExpidusNotifyDaemon;

GType expidus_notify_daemon_get_type(void) G_GNUC_CONST;

ExpidusNotifyDaemon *expidus_notify_daemon_new_unique(GError **error);

G_END_DECLS

#endif  /* __EXPIDUS_NOTIFY_DAEMON_H__ */
