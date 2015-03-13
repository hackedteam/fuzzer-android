#include <linux/types.h>
#include <linux/ioctl.h>
#include <inttypes.h>
#include <stdlib.h>

/********************************/
/**** QSEECOM *******************/
/********************************/

#define MAX_ION_FD  4
#define MAX_APP_NAME_SIZE  32

/*
 * struct qseecom_register_listener_req -
 *      for register listener ioctl request
 * @listener_id - service id (shared between userspace and QSE)
 * @ifd_data_fd - ion handle
 * @virt_sb_base - shared buffer base in user space
 * @sb_size - shared buffer size
 */
   struct qseecom_register_listener_req {
     uint32_t listener_id; /* in */
     int32_t ifd_data_fd; /* in */
     uint32_t virt_sb_base; /* in */
     uint32_t sb_size; /* in */
   };

/*
 * struct qseecom_send_cmd_req - for send command ioctl request
 * @cmd_req_len - command buffer length
 * @cmd_req_buf - command buffer
 * @resp_len - response buffer length
 * @resp_buf - response buffer
 */
struct qseecom_send_cmd_req {
  void *cmd_req_buf; /* in */
  unsigned int cmd_req_len; /* in */
  void *resp_buf; /* in/out */
  unsigned int resp_len; /* in/out */
};


/*
 * struct qseecom_ion_fd_info - ion fd handle data information
 * @fd - ion handle to some memory allocated in user space
 * @cmd_buf_offset - command buffer offset
 */
struct qseecom_ion_fd_info {
  int32_t fd;
  uint32_t cmd_buf_offset;
};
/*
 * struct qseecom_send_modfd_cmd_req - for send command ioctl request
 * @cmd_req_len - command buffer length
 * @cmd_req_buf - command buffer
 * @resp_len - response buffer length
 * @resp_buf - response buffer
 * @ifd_data_fd - ion handle to memory allocated in user space
 * @cmd_buf_offset - command buffer offset
 */
struct qseecom_send_modfd_cmd_req {
  void *cmd_req_buf; /* in */
  unsigned int cmd_req_len; /* in */
  void *resp_buf; /* in/out */
  unsigned int resp_len; /* in/out */
  struct qseecom_ion_fd_info ifd_data[MAX_ION_FD];
};
/*
 * struct qseecom_listener_send_resp_req - signal to continue the send_cmd req.
 * Used as a trigger from HLOS service to notify QSEECOM that it's done with its
 * operation and provide the response for QSEECOM can continue the incomplete
 * command execution
 * @resp_len - Length of the response
 * @resp_buf - Response buffer where the response of the cmd should go.
 */
struct qseecom_send_resp_req {
  void *resp_buf; /* in */
  unsigned int resp_len; /* in */
};

/*
 * struct qseecom_load_img_data - for sending image length information and
 * ion file descriptor to the qseecom driver. ion file descriptor is used
 * for retrieving the ion file handle and in turn the physical address of
 * the image location.
 * @mdt_len - Length of the .mdt file in bytes.
 * @img_len - Length of the .mdt + .b00 +..+.bxx images files in bytes
 * @ion_fd - Ion file descriptor used when allocating memory.
 * @img_name - Name of the image.
 */
struct qseecom_load_img_req {
  uint32_t mdt_len; /* in */
  uint32_t img_len; /* in */
  int32_t  ifd_data_fd; /* in */
  char img_name[MAX_APP_NAME_SIZE]; /* in */
  int app_id; /* out*/
};

struct qseecom_set_sb_mem_param_req {
  int32_t ifd_data_fd; /* in */
  uint32_t virt_sb_base; /* in */
  uint32_t sb_len; /* in */
};

/*
 * struct qseecom_qseos_version_req - get qseos version
 * @qseos_version - version number
 */
struct qseecom_qseos_version_req {
  unsigned int qseos_version; /* in */
};

/*
 * struct qseecom_qseos_app_load_query - verify if app is loaded in qsee
 * @app_name[MAX_APP_NAME_SIZE]-  name of the app.
 * @app_id - app id.
 */
struct qseecom_qseos_app_load_query {
  char app_name[MAX_APP_NAME_SIZE]; /* in */
  int app_id; /* out */
};

#define QSEECOM_IOC_MAGIC    0x97



#define QSEECOM_IOCTL_REGISTER_LISTENER_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 1, struct qseecom_register_listener_req)

#define QSEECOM_IOCTL_UNREGISTER_LISTENER_REQ \
  _IO(QSEECOM_IOC_MAGIC, 2)

#define QSEECOM_IOCTL_SEND_CMD_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 3, struct qseecom_send_cmd_req)

#define QSEECOM_IOCTL_SEND_MODFD_CMD_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 4, struct qseecom_send_modfd_cmd_req)

#define QSEECOM_IOCTL_RECEIVE_REQ \
  _IO(QSEECOM_IOC_MAGIC, 5)

#define QSEECOM_IOCTL_SEND_RESP_REQ \
  _IO(QSEECOM_IOC_MAGIC, 6)

#define QSEECOM_IOCTL_LOAD_APP_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 7, struct qseecom_load_img_req)

#define QSEECOM_IOCTL_SET_MEM_PARAM_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 8, struct qseecom_set_sb_mem_param_req)

#define QSEECOM_IOCTL_UNLOAD_APP_REQ \
  _IO(QSEECOM_IOC_MAGIC, 9)

#define QSEECOM_IOCTL_GET_QSEOS_VERSION_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 10, struct qseecom_qseos_version_req)

#define QSEECOM_IOCTL_PERF_ENABLE_REQ \
  _IO(QSEECOM_IOC_MAGIC, 11)

#define QSEECOM_IOCTL_PERF_DISABLE_REQ \
  _IO(QSEECOM_IOC_MAGIC, 12)

#define QSEECOM_IOCTL_LOAD_EXTERNAL_ELF_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 13, struct qseecom_load_img_req)

#define QSEECOM_IOCTL_UNLOAD_EXTERNAL_ELF_REQ \
  _IO(QSEECOM_IOC_MAGIC, 14)

#define QSEECOM_IOCTL_APP_LOADED_QUERY_REQ \
  _IOWR(QSEECOM_IOC_MAGIC, 15, struct qseecom_qseos_app_load_query)



/***********************************/
/******* BINDER ********************/
/***********************************/


#define __user
/* drivers/staging/android/binder.h */
/*
 * Copyright (C) 2008 Google, Inc.
 *
 * Based on, but no longer compatible with, the original
 * OpenBinder.org binder driver interface, which is:
 *
 * Copyright (c) 2005 Palmsource, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#define B_PACK_CHARS(c1, c2, c3, c4) \
	((((c1)<<24)) | (((c2)<<16)) | (((c3)<<8)) | (c4))
#define B_TYPE_LARGE 0x85

enum {
	BINDER_TYPE_BINDER	= B_PACK_CHARS('s', 'b', '*', B_TYPE_LARGE),
	BINDER_TYPE_WEAK_BINDER	= B_PACK_CHARS('w', 'b', '*', B_TYPE_LARGE),
	BINDER_TYPE_HANDLE	= B_PACK_CHARS('s', 'h', '*', B_TYPE_LARGE),
	BINDER_TYPE_WEAK_HANDLE	= B_PACK_CHARS('w', 'h', '*', B_TYPE_LARGE),
	BINDER_TYPE_FD		= B_PACK_CHARS('f', 'd', '*', B_TYPE_LARGE),
};

enum {
	FLAT_BINDER_FLAG_PRIORITY_MASK = 0xff,
	FLAT_BINDER_FLAG_ACCEPTS_FDS = 0x100,
};

/*
 * This is the flattened representation of a Binder object for transfer
 * between processes.  The 'offsets' supplied as part of a binder transaction
 * contains offsets into the data where these structures occur.  The Binder
 * driver takes care of re-writing the structure type and data as it moves
 * between processes.
 */
struct flat_binder_object {
	/* 8 bytes for large_flat_header. */
	unsigned long		type;
	unsigned long		flags;

	/* 8 bytes of data. */
	union {
		void __user	*binder;	/* local object */
		signed long	handle;		/* remote object */
	};

	/* extra data associated with local object */
	void __user		*cookie;
};

/*
 * On 64-bit platforms where user code may run in 32-bits the driver must
 * translate the buffer (and local binder) addresses appropriately.
 */

struct binder_write_read {
	signed long	write_size;	/* bytes to write */
	signed long	write_consumed;	/* bytes consumed by driver */
	unsigned long	write_buffer;
	signed long	read_size;	/* bytes to read */
	signed long	read_consumed;	/* bytes consumed by driver */
	unsigned long	read_buffer;
};

/* Use with BINDER_VERSION, driver fills in fields. */
struct binder_version {
	/* driver protocol version -- increment with incompatible change */
	signed long	protocol_version;
};

/* This is the current protocol version. */
#define BINDER_CURRENT_PROTOCOL_VERSION 7

#define BINDER_WRITE_READ		_IOWR('b', 1, struct binder_write_read)
#define	BINDER_SET_IDLE_TIMEOUT		_IOW('b', 3, int64_t)
#define	BINDER_SET_MAX_THREADS		_IOW('b', 5, size_t)
#define	BINDER_SET_IDLE_PRIORITY	_IOW('b', 6, int)
#define	BINDER_SET_CONTEXT_MGR		_IOW('b', 7, int)
#define	BINDER_THREAD_EXIT		_IOW('b', 8, int)
#define BINDER_VERSION			_IOWR('b', 9, struct binder_version)

/*
 * NOTE: Two special error codes you should check for when calling
 * in to the driver are:
 *
 * EINTR -- The operation has been interupted.  This should be
 * handled by retrying the ioctl() until a different error code
 * is returned.
 *
 * ECONNREFUSED -- The driver is no longer accepting operations
 * from your process.  That is, the process is being destroyed.
 * You should handle this by exiting from your process.  Note
 * that once this error code is returned, all further calls to
 * the driver from any thread will return this same code.
 */

enum transaction_flags {
	TF_ONE_WAY	= 0x01,	/* this is a one-way call: async, no return */
	TF_ROOT_OBJECT	= 0x04,	/* contents are the component's root object */
	TF_STATUS_CODE	= 0x08,	/* contents are a 32-bit status code */
	TF_ACCEPT_FDS	= 0x10,	/* allow replies with file descriptors */
};

struct binder_transaction_data {
	/* The first two are only used for bcTRANSACTION and brTRANSACTION,
	 * identifying the target and contents of the transaction.
	 */
	union {
		size_t	handle;	/* target descriptor of command transaction */
		void	*ptr;	/* target descriptor of return transaction */
	} target;
	void		*cookie;	/* target object cookie */
	unsigned int	code;		/* transaction command */

	/* General information about the transaction. */
	unsigned int	flags;
	pid_t		sender_pid;
	uid_t		sender_euid;
	size_t		data_size;	/* number of bytes of data */
	size_t		offsets_size;	/* number of bytes of offsets */

	/* If this transaction is inline, the data immediately
	 * follows here; otherwise, it ends with a pointer to
	 * the data buffer.
	 */
	union {
		struct {
			/* transaction data */
			const void __user	*buffer;
			/* offsets from buffer to flat_binder_object structs */
			const void __user	*offsets;
		} ptr;
		uint8_t	buf[8];
	} data;
};

struct binder_ptr_cookie {
	void *ptr;
	void *cookie;
};

struct binder_pri_desc {
	int priority;
	int desc;
};

struct binder_pri_ptr_cookie {
	int priority;
	void *ptr;
	void *cookie;
};

enum BinderDriverReturnProtocol {
	BR_ERROR = _IOR('r', 0, int),
	/*
	 * int: error code
	 */

	BR_OK = _IO('r', 1),
	/* No parameters! */

	BR_TRANSACTION = _IOR('r', 2, struct binder_transaction_data),
	BR_REPLY = _IOR('r', 3, struct binder_transaction_data),
	/*
	 * binder_transaction_data: the received command.
	 */

	BR_ACQUIRE_RESULT = _IOR('r', 4, int),
	/*
	 * not currently supported
	 * int: 0 if the last bcATTEMPT_ACQUIRE was not successful.
	 * Else the remote object has acquired a primary reference.
	 */

	BR_DEAD_REPLY = _IO('r', 5),
	/*
	 * The target of the last transaction (either a bcTRANSACTION or
	 * a bcATTEMPT_ACQUIRE) is no longer with us.  No parameters.
	 */

	BR_TRANSACTION_COMPLETE = _IO('r', 6),
	/*
	 * No parameters... always refers to the last transaction requested
	 * (including replies).  Note that this will be sent even for
	 * asynchronous transactions.
	 */

	BR_INCREFS = _IOR('r', 7, struct binder_ptr_cookie),
	BR_ACQUIRE = _IOR('r', 8, struct binder_ptr_cookie),
	BR_RELEASE = _IOR('r', 9, struct binder_ptr_cookie),
	BR_DECREFS = _IOR('r', 10, struct binder_ptr_cookie),
	/*
	 * void *:	ptr to binder
	 * void *: cookie for binder
	 */

	BR_ATTEMPT_ACQUIRE = _IOR('r', 11, struct binder_pri_ptr_cookie),
	/*
	 * not currently supported
	 * int:	priority
	 * void *: ptr to binder
	 * void *: cookie for binder
	 */

	BR_NOOP = _IO('r', 12),
	/*
	 * No parameters.  Do nothing and examine the next command.  It exists
	 * primarily so that we can replace it with a BR_SPAWN_LOOPER command.
	 */

	BR_SPAWN_LOOPER = _IO('r', 13),
	/*
	 * No parameters.  The driver has determined that a process has no
	 * threads waiting to service incomming transactions.  When a process
	 * receives this command, it must spawn a new service thread and
	 * register it via bcENTER_LOOPER.
	 */

	BR_FINISHED = _IO('r', 14),
	/*
	 * not currently supported
	 * stop threadpool thread
	 */

	BR_DEAD_BINDER = _IOR('r', 15, void *),
	/*
	 * void *: cookie
	 */
	BR_CLEAR_DEATH_NOTIFICATION_DONE = _IOR('r', 16, void *),
	/*
	 * void *: cookie
	 */

	BR_FAILED_REPLY = _IO('r', 17),
	/*
	 * The the last transaction (either a bcTRANSACTION or
	 * a bcATTEMPT_ACQUIRE) failed (e.g. out of memory).  No parameters.
	 */
};

enum BinderDriverCommandProtocol {
	BC_TRANSACTION = _IOW('c', 0, struct binder_transaction_data),
	BC_REPLY = _IOW('c', 1, struct binder_transaction_data),
	/*
	 * binder_transaction_data: the sent command.
	 */

	BC_ACQUIRE_RESULT = _IOW('c', 2, int),
	/*
	 * not currently supported
	 * int:  0 if the last BR_ATTEMPT_ACQUIRE was not successful.
	 * Else you have acquired a primary reference on the object.
	 */

	BC_FREE_BUFFER = _IOW('c', 3, int),
	/*
	 * void *: ptr to transaction data received on a read
	 */

	BC_INCREFS = _IOW('c', 4, int),
	BC_ACQUIRE = _IOW('c', 5, int),
	BC_RELEASE = _IOW('c', 6, int),
	BC_DECREFS = _IOW('c', 7, int),
	/*
	 * int:	descriptor
	 */

	BC_INCREFS_DONE = _IOW('c', 8, struct binder_ptr_cookie),
	BC_ACQUIRE_DONE = _IOW('c', 9, struct binder_ptr_cookie),
	/*
	 * void *: ptr to binder
	 * void *: cookie for binder
	 */

	BC_ATTEMPT_ACQUIRE = _IOW('c', 10, struct binder_pri_desc),
	/*
	 * not currently supported
	 * int: priority
	 * int: descriptor
	 */

	BC_REGISTER_LOOPER = _IO('c', 11),
	/*
	 * No parameters.
	 * Register a spawned looper thread with the device.
	 */

	BC_ENTER_LOOPER = _IO('c', 12),
	BC_EXIT_LOOPER = _IO('c', 13),
	/*
	 * No parameters.
	 * These two commands are sent as an application-level thread
	 * enters and exits the binder loop, respectively.  They are
	 * used so the binder can have an accurate count of the number
	 * of looping threads it has available.
	 */

	BC_REQUEST_DEATH_NOTIFICATION = _IOW('c', 14, struct binder_ptr_cookie),
	/*
	 * void *: ptr to binder
	 * void *: cookie
	 */

	BC_CLEAR_DEATH_NOTIFICATION = _IOW('c', 15, struct binder_ptr_cookie),
	/*
	 * void *: ptr to binder
	 * void *: cookie
	 */

	BC_DEAD_BINDER_DONE = _IOW('c', 16, void *),
	/*
	 * void *: cookie
	 */
};



/***********************************************************************************/
/********************** DRM **********************************************/
/***********************************************************************************/

#include "config.h"


#ifdef USE_DRM

#include <drm/drm.h>
#ifdef USE_DRM_EXYNOS
#include <drm/exynos_drm.h>
#endif
#include <drm/i810_drm.h>
#include <drm/i915_drm.h>
#include <drm/mga_drm.h>
#include <drm/nouveau_drm.h>
#include <drm/r128_drm.h>
#include <drm/radeon_drm.h>
#include <drm/savage_drm.h>

/* Copy-paste relevant stuff from header, as it is buggy. */
/* #include <drm/sis_drm.h> */

/* SiS specific ioctls */
#define NOT_USED_0_3
#define DRM_SIS_FB_ALLOC	0x04
#define DRM_SIS_FB_FREE	        0x05
#define NOT_USED_6_12
#define DRM_SIS_AGP_INIT	0x13
#define DRM_SIS_AGP_ALLOC	0x14
#define DRM_SIS_AGP_FREE	0x15
#define DRM_SIS_FB_INIT	        0x16

#define DRM_IOCTL_SIS_FB_ALLOC		DRM_IOWR(DRM_COMMAND_BASE + DRM_SIS_FB_ALLOC, drm_sis_mem_t)
#define DRM_IOCTL_SIS_FB_FREE		DRM_IOW( DRM_COMMAND_BASE + DRM_SIS_FB_FREE, drm_sis_mem_t)
#define DRM_IOCTL_SIS_AGP_INIT		DRM_IOWR(DRM_COMMAND_BASE + DRM_SIS_AGP_INIT, drm_sis_agp_t)
#define DRM_IOCTL_SIS_AGP_ALLOC		DRM_IOWR(DRM_COMMAND_BASE + DRM_SIS_AGP_ALLOC, drm_sis_mem_t)
#define DRM_IOCTL_SIS_AGP_FREE		DRM_IOW( DRM_COMMAND_BASE + DRM_SIS_AGP_FREE, drm_sis_mem_t)
#define DRM_IOCTL_SIS_FB_INIT		DRM_IOW( DRM_COMMAND_BASE + DRM_SIS_FB_INIT, drm_sis_fb_t)
/*
#define DRM_IOCTL_SIS_FLIP		DRM_IOW( 0x48, drm_sis_flip_t)
#define DRM_IOCTL_SIS_FLIP_INIT		DRM_IO(  0x49)
#define DRM_IOCTL_SIS_FLIP_FINAL	DRM_IO(  0x50)
*/

/* deprecated nouveau ioctls */
/*
 * Copyright 2005 Stephane Marchesin.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef DRM_IOCTL_NOUVEAU_GETPARAM
struct drm_nouveau_getparam {
	uint64_t param;
	uint64_t value;
};
#define DRM_IOCTL_NOUVEAU_GETPARAM           DRM_IOWR(DRM_COMMAND_BASE + DRM_NOUVEAU_GETPARAM, struct drm_nouveau_getparam)
#endif

#ifndef DRM_IOCTL_NOUVEAU_SETPARAM
struct drm_nouveau_setparam {
	uint64_t param;
	uint64_t value;
};
#define DRM_IOCTL_NOUVEAU_SETPARAM           DRM_IOWR(DRM_COMMAND_BASE + DRM_NOUVEAU_SETPARAM, struct drm_nouveau_setparam)
#endif

#ifndef DRM_IOCTL_NOUVEAU_CHANNEL_ALLOC
struct drm_nouveau_channel_alloc {
	uint32_t     fb_ctxdma_handle;
	uint32_t     tt_ctxdma_handle;

	int          channel;
	uint32_t     pushbuf_domains;

	/* Notifier memory */
	uint32_t     notifier_handle;

	/* DRM-enforced subchannel assignments */
	struct {
		uint32_t handle;
		uint32_t grclass;
	} subchan[8];
	uint32_t nr_subchan;
};
#define DRM_IOCTL_NOUVEAU_CHANNEL_ALLOC      DRM_IOWR(DRM_COMMAND_BASE + DRM_NOUVEAU_CHANNEL_ALLOC, struct drm_nouveau_channel_alloc)
#endif

#ifndef DRM_IOCTL_NOUVEAU_CHANNEL_FREE
struct drm_nouveau_channel_free {
	int channel;
};
#define DRM_IOCTL_NOUVEAU_CHANNEL_FREE       DRM_IOW (DRM_COMMAND_BASE + DRM_NOUVEAU_CHANNEL_FREE, struct drm_nouveau_channel_free)
#endif

#ifndef DRM_IOCTL_NOUVEAU_GROBJ_ALLOC
struct drm_nouveau_grobj_alloc {
	int      channel;
	uint32_t handle;
	int      class;
};
#define DRM_IOCTL_NOUVEAU_GROBJ_ALLOC        DRM_IOW (DRM_COMMAND_BASE + DRM_NOUVEAU_GROBJ_ALLOC, struct drm_nouveau_grobj_alloc)
#endif

#ifndef DRM_IOCTL_NOUVEAU_NOTIFIEROBJ_ALLOC
struct drm_nouveau_notifierobj_alloc {
	uint32_t channel;
	uint32_t handle;
	uint32_t size;
	uint32_t offset;
};
#define DRM_IOCTL_NOUVEAU_NOTIFIEROBJ_ALLOC  DRM_IOWR(DRM_COMMAND_BASE + DRM_NOUVEAU_NOTIFIEROBJ_ALLOC, struct drm_nouveau_notifierobj_alloc)
#endif

#ifndef DRM_IOCTL_NOUVEAU_GPUOBJ_FREE
struct drm_nouveau_gpuobj_free {
	int      channel;
	uint32_t handle;
};
#define DRM_IOCTL_NOUVEAU_GPUOBJ_FREE        DRM_IOW (DRM_COMMAND_BASE + DRM_NOUVEAU_GPUOBJ_FREE, struct drm_nouveau_gpuobj_free)
#endif

typedef struct {
	int context;
	unsigned long offset;
	unsigned long size;
	unsigned long free;
} drm_sis_mem_t;

typedef struct {
	unsigned long offset, size;
} drm_sis_agp_t;

typedef struct {
	unsigned long offset, size;
} drm_sis_fb_t;

/* header is buggy. */
/* #include <drm/via_drm.h> */

#endif //USE_DRM



/******************************************************************/
/****** MSM_VIDC_ENC **************************************************/
/*****************************************************************/

/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_S_BASE 0x00000000
#define VEN_S_SUCCESS (VEN_S_BASE) 
#define VEN_S_EFAIL (VEN_S_BASE+1) 
#define VEN_S_EFATAL (VEN_S_BASE+2) 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_S_EBADPARAM (VEN_S_BASE+3) 
#define VEN_S_EINVALSTATE (VEN_S_BASE+4)
#define VEN_S_ENOSWRES (VEN_S_BASE+5) 
#define VEN_S_ENOHWRES (VEN_S_BASE+6) 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_S_EBUFFREQ (VEN_S_BASE+7) 
#define VEN_S_EINVALCMD (VEN_S_BASE+8) 
#define VEN_S_ETIMEOUT (VEN_S_BASE+9) 
#define VEN_S_ENOREATMPT (VEN_S_BASE+10)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_S_ENOPREREQ (VEN_S_BASE+11) 
#define VEN_S_ECMDQFULL (VEN_S_BASE+12) 
#define VEN_S_ENOTSUPP (VEN_S_BASE+13) 
#define VEN_S_ENOTIMPL (VEN_S_BASE+14) 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_S_ENOTPMEM (VEN_S_BASE+15) 
#define VEN_S_EFLUSHED (VEN_S_BASE+16) 
#define VEN_S_EINSUFBUF (VEN_S_BASE+17) 
#define VEN_S_ESAMESTATE (VEN_S_BASE+18)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_S_EINVALTRANS (VEN_S_BASE+19)
#define VEN_INTF_VER 1
#define VEN_MSG_INDICATION 0
#define VEN_MSG_INPUT_BUFFER_DONE 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_MSG_OUTPUT_BUFFER_DONE 2
#define VEN_MSG_NEED_OUTPUT_BUFFER 3
#define VEN_MSG_FLUSH_INPUT_DONE 4
#define VEN_MSG_FLUSH_OUPUT_DONE 5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_MSG_START 6
#define VEN_MSG_STOP 7
#define VEN_MSG_PAUSE 8
#define VEN_MSG_RESUME 9
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_MSG_STOP_READING_MSG 10
#define VEN_BUFFLAG_EOS 0x00000001
#define VEN_BUFFLAG_ENDOFFRAME 0x00000010
#define VEN_BUFFLAG_SYNCFRAME 0x00000020
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_BUFFLAG_EXTRADATA 0x00000040
#define VEN_BUFFLAG_CODECCONFIG 0x00000080
#define VEN_EXTRADATA_NONE 0x001
#define VEN_EXTRADATA_QCOMFILLER 0x002
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_EXTRADATA_SLICEINFO 0x100
#define VEN_FRAME_TYPE_I 1 
#define VEN_FRAME_TYPE_P 2 
#define VEN_FRAME_TYPE_B 3 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_CODEC_MPEG4 1 
#define VEN_CODEC_H264 2 
#define VEN_CODEC_H263 3 
#define VEN_PROFILE_MPEG4_SP 1 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_PROFILE_MPEG4_ASP 2 
#define VEN_PROFILE_H264_BASELINE 3 
#define VEN_PROFILE_H264_MAIN 4 
#define VEN_PROFILE_H264_HIGH 5 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_PROFILE_H263_BASELINE 6 
#define VEN_LEVEL_MPEG4_0 0x1 
#define VEN_LEVEL_MPEG4_1 0x2 
#define VEN_LEVEL_MPEG4_2 0x3 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_LEVEL_MPEG4_3 0x4 
#define VEN_LEVEL_MPEG4_4 0x5 
#define VEN_LEVEL_MPEG4_5 0x6 
#define VEN_LEVEL_MPEG4_3b 0x7 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_LEVEL_MPEG4_6 0x8 
#define VEN_LEVEL_H264_1 0x9 
#define VEN_LEVEL_H264_1b 0xA 
#define VEN_LEVEL_H264_1p1 0xB 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_LEVEL_H264_1p2 0xC 
#define VEN_LEVEL_H264_1p3 0xD 
#define VEN_LEVEL_H264_2 0xE 
#define VEN_LEVEL_H264_2p1 0xF 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_LEVEL_H264_2p2 0x10 
#define VEN_LEVEL_H264_3 0x11 
#define VEN_LEVEL_H264_3p1 0x12 
#define VEN_LEVEL_H264_3p2 0x13 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_LEVEL_H264_4 0x14 
#define VEN_LEVEL_H263_10 0x15 
#define VEN_LEVEL_H263_20 0x16 
#define VEN_LEVEL_H263_30 0x17 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_LEVEL_H263_40 0x18 
#define VEN_LEVEL_H263_45 0x19 
#define VEN_LEVEL_H263_50 0x1A 
#define VEN_LEVEL_H263_60 0x1B 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_LEVEL_H263_70 0x1C 
#define VEN_ENTROPY_MODEL_CAVLC 1
#define VEN_ENTROPY_MODEL_CABAC 2
#define VEN_CABAC_MODEL_0 1 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_CABAC_MODEL_1 2 
#define VEN_CABAC_MODEL_2 3 
#define VEN_DB_DISABLE 1 
#define VEN_DB_ALL_BLKG_BNDRY 2 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_DB_SKIP_SLICE_BNDRY 3 
#define VEN_MSLICE_OFF 1
#define VEN_MSLICE_CNT_MB 2  
#define VEN_MSLICE_CNT_BYTE 3  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_MSLICE_GOB 4  
#define VEN_RC_OFF 1
#define VEN_RC_VBR_VFR 2
#define VEN_RC_VBR_CFR 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_RC_CBR_VFR 4
#define VEN_RC_CBR_CFR 5
#define VEN_FLUSH_INPUT 1
#define VEN_FLUSH_OUTPUT 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_FLUSH_ALL 3
#define VEN_INPUTFMT_NV12 1 
#define VEN_INPUTFMT_NV21 2 
#define VEN_INPUTFMT_NV12_16M2KA 3 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_ROTATION_0 1 
#define VEN_ROTATION_90 2 
#define VEN_ROTATION_180 3 
#define VEN_ROTATION_270 4 
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_TIMEOUT_INFINITE 0xffffffff
#define VEN_IR_OFF 1
#define VEN_IR_CYCLIC 2
#define VEN_IR_RANDOM 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTLBASE_NENC 0x800
#define VEN_IOCTLBASE_ENC 0x850
struct venc_ioctl_msg{
  void __user *in;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void __user *out;
};


#define VEN_IOCTL_SET_INTF_VERSION   _IOW(VEN_IOCTLBASE_NENC, 0, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_READ_NEXT_MSG   _IOWR(VEN_IOCTLBASE_NENC, 1, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_CMD_STOP_READ_MSG _IO(VEN_IOCTLBASE_NENC, 2)
#define VEN_IOCTL_SET_INPUT_BUFFER_REQ   _IOW(VEN_IOCTLBASE_NENC, 3, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_INPUT_BUFFER_REQ   _IOR(VEN_IOCTLBASE_NENC, 4, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_ALLOC_INPUT_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 5, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_INPUT_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 6, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_FREE_INPUT_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 7, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_OUTPUT_BUFFER_REQ   _IOW(VEN_IOCTLBASE_NENC, 8, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_OUTPUT_BUFFER_REQ   _IOR(VEN_IOCTLBASE_NENC, 9, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_CMD_ALLOC_OUTPUT_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 10, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_OUTPUT_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 11, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_FREE_OUTPUT_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 12, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_START _IO(VEN_IOCTLBASE_NENC, 13)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_CMD_ENCODE_FRAME   _IOW(VEN_IOCTLBASE_NENC, 14, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_FILL_OUTPUT_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 15, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_FLUSH   _IOW(VEN_IOCTLBASE_NENC, 16, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_PAUSE _IO(VEN_IOCTLBASE_NENC, 17)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_CMD_RESUME _IO(VEN_IOCTLBASE_NENC, 18)
#define VEN_IOCTL_CMD_STOP _IO(VEN_IOCTLBASE_NENC, 19)
#define VEN_IOCTL_SET_RECON_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 20, struct venc_ioctl_msg)
#define VEN_IOCTL_FREE_RECON_BUFFER   _IOW(VEN_IOCTLBASE_NENC, 21, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_GET_RECON_BUFFER_SIZE   _IOW(VEN_IOCTLBASE_NENC, 22, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_BASE_CFG   _IOW(VEN_IOCTLBASE_ENC, 1, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_BASE_CFG   _IOR(VEN_IOCTLBASE_ENC, 2, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_LIVE_MODE   _IOW(VEN_IOCTLBASE_ENC, 3, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_GET_LIVE_MODE   _IOR(VEN_IOCTLBASE_ENC, 4, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_CODEC_PROFILE   _IOW(VEN_IOCTLBASE_ENC, 5, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_CODEC_PROFILE   _IOR(VEN_IOCTLBASE_ENC, 6, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_PROFILE_LEVEL   _IOW(VEN_IOCTLBASE_ENC, 7, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_GET_PROFILE_LEVEL   _IOR(VEN_IOCTLBASE_ENC, 8, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_SHORT_HDR   _IOW(VEN_IOCTLBASE_ENC, 9, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_SHORT_HDR   _IOR(VEN_IOCTLBASE_ENC, 10, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_SESSION_QP   _IOW(VEN_IOCTLBASE_ENC, 11, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_GET_SESSION_QP   _IOR(VEN_IOCTLBASE_ENC, 12, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_INTRA_PERIOD   _IOW(VEN_IOCTLBASE_ENC, 13, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_INTRA_PERIOD   _IOR(VEN_IOCTLBASE_ENC, 14, struct venc_ioctl_msg)
#define VEN_IOCTL_CMD_REQUEST_IFRAME _IO(VEN_IOCTLBASE_ENC, 15)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_GET_CAPABILITY   _IOR(VEN_IOCTLBASE_ENC, 16, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_SEQUENCE_HDR   _IOR(VEN_IOCTLBASE_ENC, 17, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_ENTROPY_CFG   _IOW(VEN_IOCTLBASE_ENC, 18, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_ENTROPY_CFG   _IOR(VEN_IOCTLBASE_ENC, 19, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_DEBLOCKING_CFG   _IOW(VEN_IOCTLBASE_ENC, 20, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_DEBLOCKING_CFG   _IOR(VEN_IOCTLBASE_ENC, 21, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_INTRA_REFRESH   _IOW(VEN_IOCTLBASE_ENC, 22, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_INTRA_REFRESH   _IOR(VEN_IOCTLBASE_ENC, 23, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_MULTI_SLICE_CFG   _IOW(VEN_IOCTLBASE_ENC, 24, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_MULTI_SLICE_CFG   _IOR(VEN_IOCTLBASE_ENC, 25, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_RATE_CTRL_CFG   _IOW(VEN_IOCTLBASE_ENC, 26, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_RATE_CTRL_CFG   _IOR(VEN_IOCTLBASE_ENC, 27, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_VOP_TIMING_CFG   _IOW(VEN_IOCTLBASE_ENC, 28, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_VOP_TIMING_CFG   _IOR(VEN_IOCTLBASE_ENC, 29, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_FRAME_RATE   _IOW(VEN_IOCTLBASE_ENC, 30, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_FRAME_RATE   _IOR(VEN_IOCTLBASE_ENC, 31, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_TARGET_BITRATE   _IOW(VEN_IOCTLBASE_ENC, 32, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_TARGET_BITRATE   _IOR(VEN_IOCTLBASE_ENC, 33, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_ROTATION   _IOW(VEN_IOCTLBASE_ENC, 34, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_ROTATION   _IOR(VEN_IOCTLBASE_ENC, 35, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_HEC   _IOW(VEN_IOCTLBASE_ENC, 36, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_HEC   _IOR(VEN_IOCTLBASE_ENC, 37, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_DATA_PARTITION   _IOW(VEN_IOCTLBASE_ENC, 38, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_DATA_PARTITION   _IOR(VEN_IOCTLBASE_ENC, 39, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_RVLC   _IOW(VEN_IOCTLBASE_ENC, 40, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_RVLC   _IOR(VEN_IOCTLBASE_ENC, 41, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_AC_PREDICTION   _IOW(VEN_IOCTLBASE_ENC, 42, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_AC_PREDICTION   _IOR(VEN_IOCTLBASE_ENC, 43, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_QP_RANGE   _IOW(VEN_IOCTLBASE_ENC, 44, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_QP_RANGE   _IOR(VEN_IOCTLBASE_ENC, 45, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_NUMBER_INSTANCES   _IOR(VEN_IOCTLBASE_ENC, 46, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_METABUFFER_MODE   _IOW(VEN_IOCTLBASE_ENC, 47, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VEN_IOCTL_SET_EXTRADATA   _IOW(VEN_IOCTLBASE_ENC, 48, struct venc_ioctl_msg)
#define VEN_IOCTL_GET_EXTRADATA   _IOR(VEN_IOCTLBASE_ENC, 49, struct venc_ioctl_msg)
#define VEN_IOCTL_SET_SLICE_DELIVERY_MODE   _IO(VEN_IOCTLBASE_ENC, 50)
#define VEN_IOCTL_SET_SPS_PPS_FOR_IDR   _IOW(VEN_IOCTLBASE_ENC, 51, struct venc_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct venc_switch{
    unsigned char status;
  };
struct venc_allocatorproperty{
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long mincount;
  unsigned long maxcount;
  unsigned long actualcount;
  unsigned long datasize;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long suffixsize;
  unsigned long alignment;
  unsigned long bufpoolid;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_bufferpayload{
  unsigned char *pbuffer;
  size_t sz;
  int fd;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int offset;
  unsigned int maped_size;
  unsigned long filled_len;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_buffer{
  unsigned char *ptrbuffer;
  unsigned long sz;
  unsigned long len;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long offset;
  long long timestamp;
  unsigned long flags;
  void *clientdata;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_basecfg{
  unsigned long input_width;
  unsigned long input_height;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long dvs_width;
  unsigned long dvs_height;
  unsigned long codectype;
  unsigned long fps_num;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long fps_den;
  unsigned long targetbitrate;
  unsigned long inputformat;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_profile{
  unsigned long profile;
};
struct ven_profilelevel{
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long level;
};
struct venc_sessionqp{
  unsigned long iframeqp;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long pframqp;
};
struct venc_qprange{
  unsigned long maxqp;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long minqp;
};
struct venc_intraperiod{
  unsigned long num_pframes;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long num_bframes;
};
struct venc_seqheader{
  unsigned char *hdrbufptr;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long bufsize;
  unsigned long hdrlen;
};
struct venc_capability{
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long codec_types;
  unsigned long maxframe_width;
  unsigned long maxframe_height;
  unsigned long maxtarget_bitrate;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long maxframe_rate;
  unsigned long input_formats;
  unsigned char dvs;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_entropycfg{
  unsigned longentropysel;
  unsigned long cabacmodel;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_dbcfg{
  unsigned long db_mode;
  unsigned long slicealpha_offset;
  unsigned long slicebeta_offset;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_intrarefresh{
  unsigned long irmode;
  unsigned long mbcount;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_multiclicecfg{
  unsigned long mslice_mode;
  unsigned long mslice_size;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_bufferflush{
  unsigned long flush_mode;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_ratectrlcfg{
  unsigned long rcmode;
};
struct venc_voptimingcfg{
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long voptime_resolution;
};
struct venc_framerate{
  unsigned long fps_denominator;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long fps_numerator;
};
struct venc_targetbitrate{
  unsigned long target_bitrate;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_rotation{
  unsigned long rotation;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_timeout{
  unsigned long millisec;
};
struct venc_headerextension{
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long header_extension;
};
struct venc_msg{
  unsigned long statuscode;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long msgcode;
  struct venc_buffer buf;
  unsigned long msgdata_size;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_recon_addr{
  unsigned char *pbuffer;
  unsigned long buffer_size;
  unsigned long pmem_fd;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long offset;
};
struct venc_recon_buff_size{
  int width;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int height;
  int size;
  int alignment;
};
