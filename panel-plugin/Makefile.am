AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-DG_LOG_DOMAIN=\"expidus1-notification-plugin\" \
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\" \
	$(PLATFORM_CPPFLAGS)

#
# Notification plugin
#
plugin_LTLIBRARIES = \
	libnotification-plugin.la

plugindir = \
	$(libdir)/expidus1/panel/plugins

libnotification_plugin_la_SOURCES = \
	notification-plugin.c \
	notification-plugin.h \
	notification-plugin-dialogs.c \
	notification-plugin-dialogs.h \
	notification-plugin-log.c \
	notification-plugin-log.h

libnotification_plugin_la_CFLAGS = \
	$(LIBEXPIDUS1UTIL_CFLAGS) \
	$(LIBEXPIDUS1UI_CFLAGS) \
	$(LIBEXPIDUS1PANEL_CFLAGS) \
	$(ESCONF_CFLAGS) \
	$(PLATFORM_CFLAGS)

libnotification_plugin_la_LDFLAGS = \
       -avoid-version \
       -module \
       -no-undefined \
       -export-symbols-regex '^expidus_panel_module_(preinit|init|construct)' \
       $(PLATFORM_LDFLAGS)

libnotification_plugin_la_LIBADD = \
	$(top_builddir)/common/libexpidus-notifyd-common.la \
	$(LIBEXPIDUS1UTIL_LIBS) \
	$(LIBEXPIDUS1UI_LIBS) \
	$(LIBEXPIDUS1PANEL_LIBS)	\
	$(ESCONF_LIBS)

#
# Desktop file
#
desktopdir =								\
	$(datadir)/expidus1/panel/plugins

desktop_DATA =								\
	notification-plugin.desktop

@INTLTOOL_DESKTOP_RULE@

EXTRA_DIST =								\
	notification-plugin.desktop.in

CLEANFILES =								\
	$(desktop_DATA)

# vi:set ts=8 sw=8 noet ai nocindent syntax=automake:
