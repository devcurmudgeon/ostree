/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2011 Colin Walters <walters@verbum.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Colin Walters <walters@verbum.org>
 */

#ifndef __OSTREE_DAEMON__
#define __OSTREE_DAEMON__

#include <gio/gio.h>

#define OSTREE_DAEMON_NAME "org.gnome.OSTree"
#define OSTREE_DAEMON_PATH "/org/gnome/OSTree"
#define OSTREE_DAEMON_IFACE "org.gnome.OSTree"

G_BEGIN_DECLS

typedef struct {
  GMainLoop *loop;
  OstreeRepo  *repo;

  GDBusConnection *bus;

  int name_id;

  guint32 op_id;

  GHashTable *ops;
} OstreeDaemon;

typedef struct {
  guint32 id;
  OstreeDaemon *daemon;
  char *requestor_dbus_name;
  GCancellable *cancellable;
} OstreeDaemonOperation;

OstreeDaemon *ostree_daemon_new (void);

G_END_DECLS

#endif