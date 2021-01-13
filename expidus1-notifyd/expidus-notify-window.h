/*
 *  expidus1-notifyd
 *
 *  Copyright (c) 2008-2009 Brian Tarricone <bjt23@cornell.edu>
 *  Copyright (c) 2009 Jérôme Guelfucci <jeromeg@expidus.org>
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

#ifndef __EXPIDUS_NOTIFY_WINDOW_H__
#define __EXPIDUS_NOTIFY_WINDOW_H__

#include <gtk/gtk.h>

#define EXPIDUS_TYPE_NOTIFY_WINDOW     (expidus_notify_window_get_type())
#define EXPIDUS_NOTIFY_WINDOW(obj)     (G_TYPE_CHECK_INSTANCE_CAST((obj), EXPIDUS_TYPE_NOTIFY_WINDOW, ExpidusNotifyWindow))
#define EXPIDUS_IS_NOTIFY_WINDOW(obj)  (G_TYPE_CHECK_INSTANCE_TYPE((obj), EXPIDUS_TYPE_NOTIFY_WINDOW))

G_BEGIN_DECLS

typedef enum
{
    EXPIDUS_NOTIFY_CLOSE_REASON_EXPIRED = 1,
    EXPIDUS_NOTIFY_CLOSE_REASON_DISMISSED,
    EXPIDUS_NOTIFY_CLOSE_REASON_CLIENT,
    EXPIDUS_NOTIFY_CLOSE_REASON_UNKNOWN,
} ExpidusNotifyCloseReason;

typedef struct _ExpidusNotifyWindow  ExpidusNotifyWindow;

GType expidus_notify_window_get_type(void) G_GNUC_CONST;

GtkWidget *expidus_notify_window_new(void);

GtkWidget *expidus_notify_window_new_full(const gchar *summary,
                                       const gchar *body,
                                       const gchar *icon_name,
                                       gint expire_timeout);

GtkWidget *expidus_notify_window_new_with_actions(const gchar *summary,
                                               const gchar *body,
                                               const gchar *icon_name,
                                               gint expire_timeout,
                                               const gchar **actions,
                                               GtkCssProvider *css_provider);

void expidus_notify_window_set_summary(ExpidusNotifyWindow *window,
                                    const gchar *summary);
void expidus_notify_window_set_body(ExpidusNotifyWindow *window,
                                 const gchar *body);

void expidus_notify_window_set_geometry(ExpidusNotifyWindow *window,
                                     GdkRectangle rectangle);
GdkRectangle *expidus_notify_window_get_geometry(ExpidusNotifyWindow *window);

void expidus_notify_window_set_last_monitor(ExpidusNotifyWindow *window,
                                         gint monitor);
gint expidus_notify_window_get_last_monitor(ExpidusNotifyWindow *window);

void expidus_notify_window_set_icon_name(ExpidusNotifyWindow *window,
                                      const gchar *icon_name);
void expidus_notify_window_set_icon_pixbuf(ExpidusNotifyWindow *window,
                                        GdkPixbuf *pixbuf);

void expidus_notify_window_set_expire_timeout(ExpidusNotifyWindow *window,
                                           gint expire_timeout);

void expidus_notify_window_set_actions(ExpidusNotifyWindow *window,
                                    const gchar **actions,
                                    GtkCssProvider *css_provider);

void expidus_notify_window_set_fade_transparent(ExpidusNotifyWindow *window,
                                             gboolean fade_transparent);
gboolean expidus_notify_window_get_fade_transparent(ExpidusNotifyWindow *window);

void expidus_notify_window_set_opacity(ExpidusNotifyWindow *window,
                                    gdouble opacity);
gdouble expidus_notify_window_get_opacity(ExpidusNotifyWindow *window);

void expidus_notify_window_set_icon_only(ExpidusNotifyWindow *window,
                                      gboolean icon_only);

void expidus_notify_window_set_gauge_value(ExpidusNotifyWindow *window,
                                        gint value,
                                        GtkCssProvider *css_provider);
void expidus_notify_window_unset_gauge_value(ExpidusNotifyWindow *window);

void expidus_notify_window_set_do_fadeout(ExpidusNotifyWindow *window,
                                       gboolean do_fadeout,
                                       gboolean do_slideout);

void expidus_notify_window_set_notify_location(ExpidusNotifyWindow *window,
                                            GtkCornerType notify_location);
/* signal trigger */
void expidus_notify_window_closed(ExpidusNotifyWindow *window,
                               ExpidusNotifyCloseReason reason);

G_END_DECLS

#endif  /* __EXPIDUS_NOTIFY_WINDOW_H__ */
