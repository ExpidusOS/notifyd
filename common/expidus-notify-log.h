/*
 *  expidus1-notifyd
 *
 *  Copyright (c) 2016 Simon Steinbeiß <ochosi@expidus.org>
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

#ifndef __EXPIDUS_NOTIFY_LOG_H_
#define __EXPIDUS_NOTIFY_LOG_H_


#define EXPIDUS_NOTIFY_LOG_FILE  "expidus1/notifyd/log"
#define EXPIDUS_NOTIFY_ICON_PATH "expidus1/notifyd/icons/"

GdkPixbuf *notify_pixbuf_from_image_data (GVariant *image_data);

gchar     *notify_icon_name_from_desktop_id (const gchar *desktop_id);

GKeyFile  *expidus_notify_log_get (void);

void       expidus_notify_log_insert (const gchar *app_name,
                                   const gchar *summary,
                                   const gchar *body,
                                   GVariant *image_data,
                                   const gchar *image_path,
                                   const gchar *app_icon,
                                   const gchar *desktop_id,
                                   gint expire_timeout,
                                   const gchar **actions,
                                   gint log_max_size);

GtkWidget *expidus_notify_clear_log_dialog (void);

void expidus_notify_log_clear (void);

#endif /* __EXPIDUS_NOTIFY_LOG_H_ */
