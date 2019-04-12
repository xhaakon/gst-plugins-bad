/*
 * GStreamer
 * Copyright (C) 2018 Edward Hervey <edward@centricular.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gst/gst.h>

#include "gstcccombiner.h"
#include "gstccconverter.h"
#include "gstccextractor.h"
#include "gstline21dec.h"
#include "gstceaccoverlay.h"
#include "gstline21enc.h"

static gboolean
closedcaption_init (GstPlugin * plugin)
{
  gboolean ret;

  ret = gst_element_register (plugin, "cccombiner", GST_RANK_NONE,
      GST_TYPE_CCCOMBINER);

  ret &= gst_element_register (plugin, "ccconverter", GST_RANK_NONE,
      GST_TYPE_CCCONVERTER);

  ret &= gst_element_register (plugin, "ccextractor", GST_RANK_NONE,
      GST_TYPE_CCEXTRACTOR);

  ret &= gst_element_register (plugin, "line21decoder", GST_RANK_NONE,
      GST_TYPE_LINE21DECODER);

  ret &= gst_element_register (plugin, "cc708overlay", GST_RANK_PRIMARY,
      GST_TYPE_CEA_CC_OVERLAY);

  ret &= gst_element_register (plugin, "line21encoder", GST_RANK_NONE,
      GST_TYPE_LINE21ENCODER);

  return ret;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    closedcaption,
    "Closed Caption elements",
    closedcaption_init, VERSION, "LGPL", GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN)
