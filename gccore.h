/*-------------------------------------------------------------
gccore.h -- GC core header
Copyright (C) 2004
Michael Wiedenbauer (shagkur)
Dave Murphy (WinterMute)
This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any
damages arising from the use of this software.
Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:
1.	The origin of this software must not be misrepresented; you
must not claim that you wrote the original software. If you use
this software in a product, an acknowledgment in the product
documentation would be appreciated but is not required.
2.	Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.
3.	This notice may not be removed or altered from any source
distribution.
-------------------------------------------------------------*/


#ifndef __GCCORE_H__
#define __GCCORE_H__

/*! \file gccore.h
\brief Core header which includes all subsequent subsystem headers
*/

#include "libogc/dsp.c"
#include "libogc/aram.c"
#include "libogc/arqueue.c"
#include "libogc/arqmgr.c"
#include "libogc/audio.c"
#include "libogc/cache.c"
#include "libogc/card.c"
#include "libogc/cast.h"
#include "libogc/color.h"
#include "libogc/console.h"
#include "libogc/dvd.c"
#include "libogc/exi.c"
#include "libogc/gu.c"
#include "libogc/gx.c"
#include "libogc/si.c"
#include "libogc/gx_struct.h"
#include "libogc/irq.c"
#include "libogc/lwp.h"
#include "libogc/mutex.c"
#include "libogc/message.c"
#include "libogc/semaphore.c"
#include "libogc/pad.c"
#include "libogc/tpl.c"
#include "libogc/system.h"
#include "libogc/video.c"
#include "libogc/usbgecko.c"
#include "libogc/video_types.h"
#include "libogc/texconv.c"

#if defined(HW_RVL)
#include "libogc/ipc.h"
#include "libogc/es.h"
#include "libogc/stm.h"
#include "libogc/ios.h"
#include "libogc/usb.h"
#include "libogc/isfs.h"
#include "libogc/conf.h"
#include "libogc/usbstorage.h"

#include "libogc/wiilaunch.h"

#endif

/*
 * Error returns
 */
#define RNC_FILE_IS_NOT_RNC				-1
#define RNC_HUF_DECODE_ERROR			-2
#define RNC_FILE_SIZE_MISMATCH			-3
#define RNC_PACKED_CRC_ERROR			-4
#define RNC_UNPACKED_CRC_ERROR			-5

#ifndef ATTRIBUTE_ALIGN
# define ATTRIBUTE_ALIGN(v)				__attribute__((aligned(v)))
#endif
#ifndef ATTRIBUTE_PACKED
# define ATTRIBUTE_PACKED				__attribute__((packed))
#endif

#ifdef __cplusplus
   extern "C" {
#endif /* __cplusplus */


/*!
 * \mainpage
 *
 * - \subpage intro
 * - \subpage api_doc
 */


/*!
 * \page intro Introduction
 * Welcome to the ogc reference documentation.
 */

/*!
 * \page api_doc Detailed API description
 *
 * - \ref aram.h "ARAM subsystem"
 * - \ref arqmgr.h "ARAM queue management subsystem"
 * - \ref audio.h "AUDIO subsystem"
 * - \ref asndlib.h "ASND library"
 * - \ref exi.h "EXI subsystem"
 * - \ref irq.h "IRQ subsystem"
 * - \ref dsp.h "DSP subsystem"
 * - \ref dvd.h "DVD subsystem"
 * - \ref gx.h "GX subsystem"
 * - \ref gu.h "gu/Matrix subsystem"
 * - \ref video.h "VIDEO subsystem"
 * - \ref cache.h "Cache subsystem"
 * - \ref card.h "Memory card subsystem"
 * - \ref consol.h "Console subsystem"
 * - \ref system.h "OS functions and initialization"
 * - \ref lwp.h "Thread subsystem I"
 * - \ref message.h "Thread subsystem II"
 * - \ref mutex.h "Thread subsystem III"
 * - \ref semaphore.h "Thread subsystem IV"
 * - \ref cond.h "Thread subsystem V"
 */

s32 depackrnc1_ulen(void *packed);
s32 depackrnc1(void *packed,void *unpacked);

void depackrnc2(void *packed,void *unpacked);

#ifdef __cplusplus
   }
#endif /* __cplusplus */

#endif