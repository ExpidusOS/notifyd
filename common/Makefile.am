AM_CPPFLAGS = \
	-I${top_srcdir}

noinst_LTLIBRARIES = \
	libexpidus-notifyd-common.la

libexpidus_notifyd_common_la_SOURCES = \
	expidus-notify-log.c \
	expidus-notify-log.h

libexpidus_notifyd_common_la_CFLAGS = \
	$(LIBEXPIDUS1UI_CFLAGS) \
	$(GTK3_CFLAGS) \
	$(PLATFORM_CFLAGS)

libexpidus_notifyd_common_la_LIBADD = \
	$(LIBEXPIDUS1UI_LIBS) \
	$(GTK3_LIBS)

libexpidus_notifyd_common_la_LDFLAGS = \
	-no-undefined \
	$(PLATFORM_LDFLAGS)
