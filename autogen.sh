#!/bin/sh
#
#
# Copyright (c) 2002-2020
#         The Expidus development team. All rights reserved.
#
# Written for Expidus by Benedikt Meurer <benny@expidus.org>.
#

(type xdt-autogen) >/dev/null 2>&1 || {
  cat >&2 <<EOF
autogen.sh: You don't seem to have the Expidus development tools installed on
            your system, which are required to build this software.
            Please install the expidus1-dev-tools package first, it is available
            from your distribution or https://www.expidus.org/.
EOF
  exit 1
}

XDT_AUTOGEN_REQUIRED_VERSION="4.14.0" xdt-autogen "$@"

# vi:set ts=2 sw=2 et ai:
