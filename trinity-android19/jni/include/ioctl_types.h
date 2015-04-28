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



/********************************** KGSL ****************************************/
/********************************************************************************/

#define KGSL_VERSION_MAJOR        3
#define KGSL_VERSION_MINOR        14

/*context flags */
#define KGSL_CONTEXT_SAVE_GMEM		  0x00000001
#define KGSL_CONTEXT_NO_GMEM_ALLOC	  0x00000002
#define KGSL_CONTEXT_SUBMIT_IB_LIST	  0x00000004
#define KGSL_CONTEXT_CTX_SWITCH		  0x00000008
#define KGSL_CONTEXT_PREAMBLE		  0x00000010
#define KGSL_CONTEXT_TRASH_STATE	  0x00000020
#define KGSL_CONTEXT_PER_CONTEXT_TS	  0x00000040
#define KGSL_CONTEXT_USER_GENERATED_TS	  0x00000080
#define KGSL_CONTEXT_END_OF_FRAME         0x00000100
#define KGSL_CONTEXT_NO_FAULT_TOLERANCE	  0x00000200
/* bits [12:15] are reserved for future use */
#define KGSL_CONTEXT_TYPE_MASK            0x01F00000
#define KGSL_CONTEXT_TYPE_SHIFT           20

#define KGSL_CONTEXT_TYPE_ANY		  0
#define KGSL_CONTEXT_TYPE_GL		  1
#define KGSL_CONTEXT_TYPE_CL		  2
#define KGSL_CONTEXT_TYPE_C2D		  3
#define KGSL_CONTEXT_TYPE_RS		  4

#define KGSL_CONTEXT_INVALID 0xffffffff

/* --- Memory allocation flags --- */

/* General allocation hints */
#define KGSL_MEMFLAGS_GPUREADONLY 0x01000000
#define KGSL_MEMFLAGS_USE_CPU_MAP 0x10000000

/* Memory caching hints */
#define KGSL_CACHEMODE_MASK 0x0C000000
#define KGSL_CACHEMODE_SHIFT 26

#define KGSL_CACHEMODE_WRITECOMBINE 0
#define KGSL_CACHEMODE_UNCACHED 1
#define KGSL_CACHEMODE_WRITETHROUGH 2
#define KGSL_CACHEMODE_WRITEBACK 3

/* Memory types for which allocations are made */
#define KGSL_MEMTYPE_MASK		0x0000FF00
#define KGSL_MEMTYPE_SHIFT		8

#define KGSL_MEMTYPE_OBJECTANY			0
#define KGSL_MEMTYPE_FRAMEBUFFER		1
#define KGSL_MEMTYPE_RENDERBUFFER		2
#define KGSL_MEMTYPE_ARRAYBUFFER		3
#define KGSL_MEMTYPE_ELEMENTARRAYBUFFER		4
#define KGSL_MEMTYPE_VERTEXARRAYBUFFER		5
#define KGSL_MEMTYPE_TEXTURE			6
#define KGSL_MEMTYPE_SURFACE			7
#define KGSL_MEMTYPE_EGL_SURFACE		8
#define KGSL_MEMTYPE_GL				9
#define KGSL_MEMTYPE_CL				10
#define KGSL_MEMTYPE_CL_BUFFER_MAP		11
#define KGSL_MEMTYPE_CL_BUFFER_NOMAP		12
#define KGSL_MEMTYPE_CL_IMAGE_MAP		13
#define KGSL_MEMTYPE_CL_IMAGE_NOMAP		14
#define KGSL_MEMTYPE_CL_KERNEL_STACK		15
#define KGSL_MEMTYPE_COMMAND			16
#define KGSL_MEMTYPE_2D				17
#define KGSL_MEMTYPE_EGL_IMAGE			18
#define KGSL_MEMTYPE_EGL_SHADOW			19
#define KGSL_MEMTYPE_MULTISAMPLE		20
#define KGSL_MEMTYPE_KERNEL			255

/*
 * Alignment hint, passed as the power of 2 exponent.
 * i.e 4k (2^12) would be 12, 64k (2^16)would be 16.
 */
#define KGSL_MEMALIGN_MASK		0x00FF0000
#define KGSL_MEMALIGN_SHIFT		16

/* --- generic KGSL flag values --- */

#define KGSL_FLAGS_NORMALMODE  0x00000000
#define KGSL_FLAGS_SAFEMODE    0x00000001
#define KGSL_FLAGS_INITIALIZED0 0x00000002
#define KGSL_FLAGS_INITIALIZED 0x00000004
#define KGSL_FLAGS_STARTED     0x00000008
#define KGSL_FLAGS_ACTIVE      0x00000010
#define KGSL_FLAGS_RESERVED0   0x00000020
#define KGSL_FLAGS_RESERVED1   0x00000040
#define KGSL_FLAGS_RESERVED2   0x00000080
#define KGSL_FLAGS_SOFT_RESET  0x00000100
#define KGSL_FLAGS_PER_CONTEXT_TIMESTAMPS 0x00000200

/* Clock flags to show which clocks should be controled by a given platform */
#define KGSL_CLK_SRC	0x00000001
#define KGSL_CLK_CORE	0x00000002
#define KGSL_CLK_IFACE	0x00000004
#define KGSL_CLK_MEM	0x00000008
#define KGSL_CLK_MEM_IFACE 0x00000010
#define KGSL_CLK_AXI	0x00000020

/* Server Side Sync Timeout in milliseconds */
#define KGSL_SYNCOBJ_SERVER_TIMEOUT 2000

/*
 * Reset status values for context
 */
enum kgsl_ctx_reset_stat {
	KGSL_CTX_STAT_NO_ERROR				= 0x00000000,
	KGSL_CTX_STAT_GUILTY_CONTEXT_RESET_EXT		= 0x00000001,
	KGSL_CTX_STAT_INNOCENT_CONTEXT_RESET_EXT	= 0x00000002,
	KGSL_CTX_STAT_UNKNOWN_CONTEXT_RESET_EXT		= 0x00000003
};

#define KGSL_CONVERT_TO_MBPS(val) \
	(val*1000*1000U)

/* device id */
enum kgsl_deviceid {
	KGSL_DEVICE_3D0		= 0x00000000,
	KGSL_DEVICE_2D0		= 0x00000001,
	KGSL_DEVICE_2D1		= 0x00000002,
	KGSL_DEVICE_MAX		= 0x00000003
};

enum kgsl_user_mem_type {
	KGSL_USER_MEM_TYPE_PMEM		= 0x00000000,
	KGSL_USER_MEM_TYPE_ASHMEM	= 0x00000001,
	KGSL_USER_MEM_TYPE_ADDR		= 0x00000002,
	KGSL_USER_MEM_TYPE_ION		= 0x00000003,
	KGSL_USER_MEM_TYPE_MAX		= 0x00000004,
};

struct kgsl_devinfo {

	unsigned int device_id;
	/* chip revision id
	* coreid:8 majorrev:8 minorrev:8 patch:8
	*/
	unsigned int chip_id;
	unsigned int mmu_enabled;
	unsigned int gmem_gpubaseaddr;
	/*
	* This field contains the adreno revision
	* number 200, 205, 220, etc...
	*/
	unsigned int gpu_id;
	unsigned int gmem_sizebytes;
};

/* this structure defines the region of memory that can be mmap()ed from this
   driver. The timestamp fields are volatile because they are written by the
   GPU
*/
struct kgsl_devmemstore {
	volatile unsigned int soptimestamp;
	unsigned int sbz;
	volatile unsigned int eoptimestamp;
	unsigned int sbz2;
	volatile unsigned int ts_cmp_enable;
	unsigned int sbz3;
	volatile unsigned int ref_wait_ts;
	unsigned int sbz4;
	unsigned int current_context;
	unsigned int sbz5;
};

#define KGSL_MEMSTORE_OFFSET(ctxt_id, field) \
	((ctxt_id)*sizeof(struct kgsl_devmemstore) + \
	 offsetof(struct kgsl_devmemstore, field))

/* timestamp id*/
enum kgsl_timestamp_type {
	KGSL_TIMESTAMP_CONSUMED = 0x00000001, /* start-of-pipeline timestamp */
	KGSL_TIMESTAMP_RETIRED  = 0x00000002, /* end-of-pipeline timestamp*/
	KGSL_TIMESTAMP_QUEUED   = 0x00000003,
};

/* property types - used with kgsl_device_getproperty */
enum kgsl_property_type {
	KGSL_PROP_DEVICE_INFO     = 0x00000001,
	KGSL_PROP_DEVICE_SHADOW   = 0x00000002,
	KGSL_PROP_DEVICE_POWER    = 0x00000003,
	KGSL_PROP_SHMEM           = 0x00000004,
	KGSL_PROP_SHMEM_APERTURES = 0x00000005,
	KGSL_PROP_MMU_ENABLE 	  = 0x00000006,
	KGSL_PROP_INTERRUPT_WAITS = 0x00000007,
	KGSL_PROP_VERSION         = 0x00000008,
	KGSL_PROP_GPU_RESET_STAT  = 0x00000009,
	KGSL_PROP_PWRCTRL         = 0x0000000E,
};

struct kgsl_shadowprop {
	unsigned int gpuaddr;
	unsigned int size;
	unsigned int flags; /* contains KGSL_FLAGS_ values */
};

struct kgsl_version {
	unsigned int drv_major;
	unsigned int drv_minor;
	unsigned int dev_major;
	unsigned int dev_minor;
};

/* Performance counter groups */

#define KGSL_PERFCOUNTER_GROUP_CP 0x0
#define KGSL_PERFCOUNTER_GROUP_RBBM 0x1
#define KGSL_PERFCOUNTER_GROUP_PC 0x2
#define KGSL_PERFCOUNTER_GROUP_VFD 0x3
#define KGSL_PERFCOUNTER_GROUP_HLSQ 0x4
#define KGSL_PERFCOUNTER_GROUP_VPC 0x5
#define KGSL_PERFCOUNTER_GROUP_TSE 0x6
#define KGSL_PERFCOUNTER_GROUP_RAS 0x7
#define KGSL_PERFCOUNTER_GROUP_UCHE 0x8
#define KGSL_PERFCOUNTER_GROUP_TP 0x9
#define KGSL_PERFCOUNTER_GROUP_SP 0xA
#define KGSL_PERFCOUNTER_GROUP_RB 0xB
#define KGSL_PERFCOUNTER_GROUP_PWR 0xC
#define KGSL_PERFCOUNTER_GROUP_VBIF 0xD
#define KGSL_PERFCOUNTER_GROUP_VBIF_PWR 0xE

#define KGSL_PERFCOUNTER_NOT_USED 0xFFFFFFFF

/* structure holds list of ibs */
struct kgsl_ibdesc {
	unsigned int gpuaddr;
	void *hostptr;
	unsigned int sizedwords;
	unsigned int ctrl;
};

/* ioctls */
#define KGSL_IOC_TYPE 0x09

/* get misc info about the GPU
   type should be a value from enum kgsl_property_type
   value points to a structure that varies based on type
   sizebytes is sizeof() that structure
   for KGSL_PROP_DEVICE_INFO, use struct kgsl_devinfo
   this structure contaings hardware versioning info.
   for KGSL_PROP_DEVICE_SHADOW, use struct kgsl_shadowprop
   this is used to find mmap() offset and sizes for mapping
   struct kgsl_memstore into userspace.
*/
struct kgsl_device_getproperty {
	unsigned int type;
	void  *value;
	unsigned int sizebytes;
};

#define IOCTL_KGSL_DEVICE_GETPROPERTY \
	_IOWR(KGSL_IOC_TYPE, 0x2, struct kgsl_device_getproperty)

/* IOCTL_KGSL_DEVICE_READ (0x3) - removed 03/2012
 */

/* block until the GPU has executed past a given timestamp
 * timeout is in milliseconds.
 */
struct kgsl_device_waittimestamp {
	unsigned int timestamp;
	unsigned int timeout;
};

#define IOCTL_KGSL_DEVICE_WAITTIMESTAMP \
	_IOW(KGSL_IOC_TYPE, 0x6, struct kgsl_device_waittimestamp)

struct kgsl_device_waittimestamp_ctxtid {
	unsigned int context_id;
	unsigned int timestamp;
	unsigned int timeout;
};

#define IOCTL_KGSL_DEVICE_WAITTIMESTAMP_CTXTID \
	_IOW(KGSL_IOC_TYPE, 0x7, struct kgsl_device_waittimestamp_ctxtid)

/* issue indirect commands to the GPU.
 * drawctxt_id must have been created with IOCTL_KGSL_DRAWCTXT_CREATE
 * ibaddr and sizedwords must specify a subset of a buffer created
 * with IOCTL_KGSL_SHAREDMEM_FROM_PMEM
 * flags may be a mask of KGSL_CONTEXT_ values
 * timestamp is a returned counter value which can be passed to
 * other ioctls to determine when the commands have been executed by
 * the GPU.
 */
struct kgsl_ringbuffer_issueibcmds {
	unsigned int drawctxt_id;
	void *ibdesc_addr;
	unsigned int numibs;
	unsigned int timestamp; /*output param */
	unsigned int flags;
};

#define IOCTL_KGSL_RINGBUFFER_ISSUEIBCMDS \
	_IOWR(KGSL_IOC_TYPE, 0x10, struct kgsl_ringbuffer_issueibcmds)

/* read the most recently executed timestamp value
 * type should be a value from enum kgsl_timestamp_type
 */
struct kgsl_cmdstream_readtimestamp {
	unsigned int type;
	unsigned int timestamp; /*output param */
};

#define IOCTL_KGSL_CMDSTREAM_READTIMESTAMP_OLD \
	_IOR(KGSL_IOC_TYPE, 0x11, struct kgsl_cmdstream_readtimestamp)

#define IOCTL_KGSL_CMDSTREAM_READTIMESTAMP \
	_IOWR(KGSL_IOC_TYPE, 0x11, struct kgsl_cmdstream_readtimestamp)

/* free memory when the GPU reaches a given timestamp.
 * gpuaddr specify a memory region created by a
 * IOCTL_KGSL_SHAREDMEM_FROM_PMEM call
 * type should be a value from enum kgsl_timestamp_type
 */
struct kgsl_cmdstream_freememontimestamp {
	void *gpuaddr;
	unsigned int type;
	unsigned int timestamp;
};

#define IOCTL_KGSL_CMDSTREAM_FREEMEMONTIMESTAMP \
	_IOW(KGSL_IOC_TYPE, 0x12, struct kgsl_cmdstream_freememontimestamp)

/* Previous versions of this header had incorrectly defined
   IOCTL_KGSL_CMDSTREAM_FREEMEMONTIMESTAMP as a read-only ioctl instead
   of a write only ioctl.  To ensure binary compatability, the following
   #define will be used to intercept the incorrect ioctl
*/

#define IOCTL_KGSL_CMDSTREAM_FREEMEMONTIMESTAMP_OLD \
	_IOR(KGSL_IOC_TYPE, 0x12, struct kgsl_cmdstream_freememontimestamp)

/* create a draw context, which is used to preserve GPU state.
 * The flags field may contain a mask KGSL_CONTEXT_*  values
 */
struct kgsl_drawctxt_create {
	unsigned int flags;
	unsigned int drawctxt_id; /*output param */
};

#define IOCTL_KGSL_DRAWCTXT_CREATE \
	_IOWR(KGSL_IOC_TYPE, 0x13, struct kgsl_drawctxt_create)

/* destroy a draw context */
struct kgsl_drawctxt_destroy {
	unsigned int drawctxt_id;
};

#define IOCTL_KGSL_DRAWCTXT_DESTROY \
	_IOW(KGSL_IOC_TYPE, 0x14, struct kgsl_drawctxt_destroy)

/* add a block of pmem, fb, ashmem or user allocated address
 * into the GPU address space */
struct kgsl_map_user_mem {
	int fd;
	void *gpuaddr;   /*output param */
	unsigned int len;
	unsigned int offset;
	void *hostptr;   /*input param */
	enum kgsl_user_mem_type memtype;
	unsigned int flags;
};

#define IOCTL_KGSL_MAP_USER_MEM \
	_IOWR(KGSL_IOC_TYPE, 0x15, struct kgsl_map_user_mem)

struct kgsl_cmdstream_readtimestamp_ctxtid {
	unsigned int context_id;
	unsigned int type;
	unsigned int timestamp; /*output param */
};

#define IOCTL_KGSL_CMDSTREAM_READTIMESTAMP_CTXTID \
	_IOWR(KGSL_IOC_TYPE, 0x16, struct kgsl_cmdstream_readtimestamp_ctxtid)

struct kgsl_cmdstream_freememontimestamp_ctxtid {
	unsigned int context_id;
	void *gpuaddr;
	unsigned int type;
	unsigned int timestamp;
};

#define IOCTL_KGSL_CMDSTREAM_FREEMEMONTIMESTAMP_CTXTID \
	_IOW(KGSL_IOC_TYPE, 0x17, \
	struct kgsl_cmdstream_freememontimestamp_ctxtid)

/* add a block of pmem or fb into the GPU address space */
struct kgsl_sharedmem_from_pmem {
	int pmem_fd;
	void *gpuaddr;	/*output param */
	unsigned int len;
	unsigned int offset;
};

#define IOCTL_KGSL_SHAREDMEM_FROM_PMEM \
	_IOWR(KGSL_IOC_TYPE, 0x20, struct kgsl_sharedmem_from_pmem)

/* remove memory from the GPU's address space */
struct kgsl_sharedmem_free {
	void *gpuaddr;
};

#define IOCTL_KGSL_SHAREDMEM_FREE \
	_IOW(KGSL_IOC_TYPE, 0x21, struct kgsl_sharedmem_free)

struct kgsl_cff_user_event {
	unsigned char cff_opcode;
	unsigned int op1;
	unsigned int op2;
	unsigned int op3;
	unsigned int op4;
	unsigned int op5;
	unsigned int __pad[2];
};

#define IOCTL_KGSL_CFF_USER_EVENT \
	_IOW(KGSL_IOC_TYPE, 0x31, struct kgsl_cff_user_event)

struct kgsl_gmem_desc {
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
	unsigned int pitch;
};

struct kgsl_buffer_desc {
	void *hostptr;
	void *gpuaddr;
	int   size;
	unsigned int format;
	unsigned int pitch;
	unsigned int enabled;
};

struct kgsl_bind_gmem_shadow {
	unsigned int drawctxt_id;
	struct kgsl_gmem_desc gmem_desc;
	unsigned int shadow_x;
	unsigned int shadow_y;
	struct kgsl_buffer_desc shadow_buffer;
	unsigned int buffer_id;
};

#define IOCTL_KGSL_DRAWCTXT_BIND_GMEM_SHADOW \
    _IOW(KGSL_IOC_TYPE, 0x22, struct kgsl_bind_gmem_shadow)

/* add a block of memory into the GPU address space */

/*
 * IOCTL_KGSL_SHAREDMEM_FROM_VMALLOC deprecated 09/2012
 * use IOCTL_KGSL_GPUMEM_ALLOC instead
 */

struct kgsl_sharedmem_from_vmalloc {
	void *gpuaddr;	/*output param */
	void *hostptr;
	unsigned int flags;
};

#define IOCTL_KGSL_SHAREDMEM_FROM_VMALLOC \
	_IOWR(KGSL_IOC_TYPE, 0x23, struct kgsl_sharedmem_from_vmalloc)

/*
 * This is being deprecated in favor of IOCTL_KGSL_GPUMEM_CACHE_SYNC which
 * supports both directions (flush and invalidate). This code will still
 * work, but by definition it will do a flush of the cache which might not be
 * what you want to have happen on a buffer following a GPU operation.  It is
 * safer to go with IOCTL_KGSL_GPUMEM_CACHE_SYNC
 */

#define IOCTL_KGSL_SHAREDMEM_FLUSH_CACHE \
	_IOW(KGSL_IOC_TYPE, 0x24, struct kgsl_sharedmem_free)

struct kgsl_drawctxt_set_bin_base_offset {
	unsigned int drawctxt_id;
	unsigned int offset;
};

#define IOCTL_KGSL_DRAWCTXT_SET_BIN_BASE_OFFSET \
	_IOW(KGSL_IOC_TYPE, 0x25, struct kgsl_drawctxt_set_bin_base_offset)

enum kgsl_cmdwindow_type {
	KGSL_CMDWINDOW_MIN     = 0x00000000,
	KGSL_CMDWINDOW_2D      = 0x00000000,
	KGSL_CMDWINDOW_3D      = 0x00000001, /* legacy */
	KGSL_CMDWINDOW_MMU     = 0x00000002,
	KGSL_CMDWINDOW_ARBITER = 0x000000FF,
	KGSL_CMDWINDOW_MAX     = 0x000000FF,
};

/* write to the command window */
struct kgsl_cmdwindow_write {
	enum kgsl_cmdwindow_type target;
	void *addr;
	unsigned int data;
};

#define IOCTL_KGSL_CMDWINDOW_WRITE \
	_IOW(KGSL_IOC_TYPE, 0x2e, struct kgsl_cmdwindow_write)

struct kgsl_gpumem_alloc {
	void *gpuaddr;
	size_t size;
	unsigned int flags;
};

#define IOCTL_KGSL_GPUMEM_ALLOC \
	_IOWR(KGSL_IOC_TYPE, 0x2f, struct kgsl_gpumem_alloc)

struct kgsl_cff_syncmem {
	void *gpuaddr;
	unsigned int len;
	unsigned int __pad[2]; /* For future binary compatibility */
};

#define IOCTL_KGSL_CFF_SYNCMEM \
	_IOW(KGSL_IOC_TYPE, 0x30, struct kgsl_cff_syncmem)

/*
 * A timestamp event allows the user space to register an action following an
 * expired timestamp. Note IOCTL_KGSL_TIMESTAMP_EVENT has been redefined to
 * _IOWR to support fences which need to return a fd for the priv parameter.
 */

struct kgsl_timestamp_event {
	int type;                /* Type of event (see list below) */
	unsigned int timestamp;  /* Timestamp to trigger event on */
	unsigned int context_id; /* Context for the timestamp */
	void *priv;              /* Pointer to the event specific blob */
	size_t len;              /* Size of the event specific blob */
};

#define IOCTL_KGSL_TIMESTAMP_EVENT_OLD \
	_IOW(KGSL_IOC_TYPE, 0x31, struct kgsl_timestamp_event)

/* A genlock timestamp event releases an existing lock on timestamp expire */

#define KGSL_TIMESTAMP_EVENT_GENLOCK 1

struct kgsl_timestamp_event_genlock {
	int handle; /* Handle of the genlock lock to release */
};

/* A fence timestamp event releases an existing lock on timestamp expire */

#define KGSL_TIMESTAMP_EVENT_FENCE 2

struct kgsl_timestamp_event_fence {
	int fence_fd; /* Fence to signal */
};

/*
 * Set a property within the kernel.  Uses the same structure as
 * IOCTL_KGSL_GETPROPERTY
 */

#define IOCTL_KGSL_SETPROPERTY \
	_IOW(KGSL_IOC_TYPE, 0x32, struct kgsl_device_getproperty)

#define IOCTL_KGSL_TIMESTAMP_EVENT \
	_IOWR(KGSL_IOC_TYPE, 0x33, struct kgsl_timestamp_event)

/**
 * struct kgsl_gpumem_alloc_id - argument to IOCTL_KGSL_GPUMEM_ALLOC_ID
 * @id: returned id value for this allocation.
 * @flags: mask of KGSL_MEM* values requested and actual flags on return.
 * @size: requested size of the allocation and actual size on return.
 * @mmapsize: returned size to pass to mmap() which may be larger than 'size'
 * @gpuaddr: returned GPU address for the allocation
 *
 * Allocate memory for access by the GPU. The flags and size fields are echoed
 * back by the kernel, so that the caller can know if the request was
 * adjusted.
 *
 * Supported flags:
 * KGSL_MEMFLAGS_GPUREADONLY: the GPU will be unable to write to the buffer
 * KGSL_MEMTYPE*: usage hint for debugging aid
 * KGSL_MEMALIGN*: alignment hint, may be ignored or adjusted by the kernel.
 * KGSL_MEMFLAGS_USE_CPU_MAP: If set on call and return, the returned GPU
 * address will be 0. Calling mmap() will set the GPU address.
 */
struct kgsl_gpumem_alloc_id {
	unsigned int id;
	unsigned int flags;
	unsigned int size;
	unsigned int mmapsize;
	void  *gpuaddr;
/* private: reserved for future use*/
	unsigned int __pad[2];
};

#define IOCTL_KGSL_GPUMEM_ALLOC_ID \
	_IOWR(KGSL_IOC_TYPE, 0x34, struct kgsl_gpumem_alloc_id)

/**
 * struct kgsl_gpumem_free_id - argument to IOCTL_KGSL_GPUMEM_FREE_ID
 * @id: GPU allocation id to free
 *
 * Free an allocation by id, in case a GPU address has not been assigned or
 * is unknown. Freeing an allocation by id with this ioctl or by GPU address
 * with IOCTL_KGSL_SHAREDMEM_FREE are equivalent.
 */
struct kgsl_gpumem_free_id {
	unsigned int id;
/* private: reserved for future use*/
	unsigned int __pad;
};

#define IOCTL_KGSL_GPUMEM_FREE_ID \
	_IOWR(KGSL_IOC_TYPE, 0x35, struct kgsl_gpumem_free_id)

/**
 * struct kgsl_gpumem_get_info - argument to IOCTL_KGSL_GPUMEM_GET_INFO
 * @gpuaddr: GPU address to query. Also set on return.
 * @id: GPU allocation id to query. Also set on return.
 * @flags: returned mask of KGSL_MEM* values.
 * @size: returned size of the allocation.
 * @mmapsize: returned size to pass mmap(), which may be larger than 'size'
 * @useraddr: returned address of the userspace mapping for this buffer
 *
 * This ioctl allows querying of all user visible attributes of an existing
 * allocation, by either the GPU address or the id returned by a previous
 * call to IOCTL_KGSL_GPUMEM_ALLOC_ID. Legacy allocation ioctls may not
 * return all attributes so this ioctl can be used to look them up if needed.
 *
 */
struct kgsl_gpumem_get_info {
	void *gpuaddr;
	unsigned int id;
	unsigned int flags;
	unsigned int size;
	unsigned int mmapsize;
	void *useraddr;
/* private: reserved for future use*/
	unsigned int __pad[4];
};

#define IOCTL_KGSL_GPUMEM_GET_INFO\
	_IOWR(KGSL_IOC_TYPE, 0x36, struct kgsl_gpumem_get_info)

/**
 * struct kgsl_gpumem_sync_cache - argument to IOCTL_KGSL_GPUMEM_SYNC_CACHE
 * @gpuaddr: GPU address of the buffer to sync.
 * @id: id of the buffer to sync. Either gpuaddr or id is sufficient.
 * @op: a mask of KGSL_GPUMEM_CACHE_* values
 *
 * Sync the L2 cache for memory headed to and from the GPU - this replaces
 * KGSL_SHAREDMEM_FLUSH_CACHE since it can handle cache management for both
 * directions
 *
 */
struct kgsl_gpumem_sync_cache {
	void *gpuaddr;
	unsigned int id;
	unsigned int op;
/* private: reserved for future use*/
	unsigned int __pad[2]; /* For future binary compatibility */
};

#define KGSL_GPUMEM_CACHE_CLEAN (1 << 0)
#define KGSL_GPUMEM_CACHE_TO_GPU KGSL_GPUMEM_CACHE_CLEAN

#define KGSL_GPUMEM_CACHE_INV (1 << 1)
#define KGSL_GPUMEM_CACHE_FROM_GPU KGSL_GPUMEM_CACHE_INV

#define KGSL_GPUMEM_CACHE_FLUSH \
	(KGSL_GPUMEM_CACHE_CLEAN | KGSL_GPUMEM_CACHE_INV)

#define IOCTL_KGSL_GPUMEM_SYNC_CACHE \
	_IOW(KGSL_IOC_TYPE, 0x37, struct kgsl_gpumem_sync_cache)

/**
 * struct kgsl_perfcounter_get - argument to IOCTL_KGSL_PERFCOUNTER_GET
 * @groupid: Performance counter group ID
 * @countable: Countable to select within the group
 * @offset: Return offset of the reserved counter
 *
 * Get an available performance counter from a specified groupid.  The offset
 * of the performance counter will be returned after successfully assigning
 * the countable to the counter for the specified group.  An error will be
 * returned and an offset of 0 if the groupid is invalid or there are no
 * more counters left.  After successfully getting a perfcounter, the user
 * must call kgsl_perfcounter_put(groupid, contable) when finished with
 * the perfcounter to clear up perfcounter resources.
 *
 */
struct kgsl_perfcounter_get {
	unsigned int groupid;
	unsigned int countable;
	unsigned int offset;
/* private: reserved for future use */
	unsigned int __pad[2]; /* For future binary compatibility */
};

#define IOCTL_KGSL_PERFCOUNTER_GET \
	_IOWR(KGSL_IOC_TYPE, 0x38, struct kgsl_perfcounter_get)

/**
 * struct kgsl_perfcounter_put - argument to IOCTL_KGSL_PERFCOUNTER_PUT
 * @groupid: Performance counter group ID
 * @countable: Countable to release within the group
 *
 * Put an allocated performance counter to allow others to have access to the
 * resource that was previously taken.  This is only to be called after
 * successfully getting a performance counter from kgsl_perfcounter_get().
 *
 */
struct kgsl_perfcounter_put {
	unsigned int groupid;
	unsigned int countable;
/* private: reserved for future use */
	unsigned int __pad[2]; /* For future binary compatibility */
};

#define IOCTL_KGSL_PERFCOUNTER_PUT \
	_IOW(KGSL_IOC_TYPE, 0x39, struct kgsl_perfcounter_put)

/**
 * struct kgsl_perfcounter_query - argument to IOCTL_KGSL_PERFCOUNTER_QUERY
 * @groupid: Performance counter group ID
 * @countable: Return active countables array
 * @size: Size of active countables array
 * @max_counters: Return total number counters for the group ID
 *
 * Query the available performance counters given a groupid.  The array
 * *countables is used to return the current active countables in counters.
 * The size of the array is passed in so the kernel will only write at most
 * size or counter->size for the group id.  The total number of available
 * counters for the group ID is returned in max_counters.
 * If the array or size passed in are invalid, then only the maximum number
 * of counters will be returned, no data will be written to *countables.
 * If the groupid is invalid an error code will be returned.
 *
 */
struct kgsl_perfcounter_query {
	unsigned int groupid;
	/* Array to return the current countable for up to size counters */
	unsigned int *countables;
	unsigned int count;
	unsigned int max_counters;
/* private: reserved for future use */
	unsigned int __pad[2]; /* For future binary compatibility */
};

#define IOCTL_KGSL_PERFCOUNTER_QUERY \
	_IOWR(KGSL_IOC_TYPE, 0x3A, struct kgsl_perfcounter_query)

/**
 * struct kgsl_perfcounter_query - argument to IOCTL_KGSL_PERFCOUNTER_QUERY
 * @groupid: Performance counter group IDs
 * @countable: Performance counter countable IDs
 * @value: Return performance counter reads
 * @size: Size of all arrays (groupid/countable pair and return value)
 *
 * Read in the current value of a performance counter given by the groupid
 * and countable.
 *
 */

struct kgsl_perfcounter_read_group {
	unsigned int groupid;
	unsigned int countable;
	uint64_t value;
};

struct kgsl_perfcounter_read {
	struct kgsl_perfcounter_read_group *reads;
	unsigned int count;
/* private: reserved for future use */
	unsigned int __pad[2]; /* For future binary compatibility */
};

#define IOCTL_KGSL_PERFCOUNTER_READ \
	_IOWR(KGSL_IOC_TYPE, 0x3B, struct kgsl_perfcounter_read)

#ifdef __KERNEL__
#ifdef CONFIG_MSM_KGSL_DRM
int kgsl_gem_obj_addr(int drm_fd, int handle, unsigned long *start,
			unsigned long *len);
#else
#define kgsl_gem_obj_addr(...) 0
#endif
#endif



/****************************************/
/*********** MSM_VIDC_DEC ***************/
/****************************************/




/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_S_BASE 0x40000000
#define VDEC_S_SUCCESS (VDEC_S_BASE)
#define VDEC_S_EFAIL (VDEC_S_BASE + 1)
#define VDEC_S_EFATAL (VDEC_S_BASE + 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_S_EBADPARAM (VDEC_S_BASE + 3)
#define VDEC_S_EINVALSTATE (VDEC_S_BASE + 4)
#define VDEC_S_ENOSWRES (VDEC_S_BASE + 5)
#define VDEC_S_ENOHWRES (VDEC_S_BASE + 6)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_S_EINVALCMD (VDEC_S_BASE + 7)
#define VDEC_S_ETIMEOUT (VDEC_S_BASE + 8)
#define VDEC_S_ENOPREREQ (VDEC_S_BASE + 9)
#define VDEC_S_ECMDQFULL (VDEC_S_BASE + 10)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_S_ENOTSUPP (VDEC_S_BASE + 11)
#define VDEC_S_ENOTIMPL (VDEC_S_BASE + 12)
#define VDEC_S_BUSY (VDEC_S_BASE + 13)
#define VDEC_S_INPUT_BITSTREAM_ERR (VDEC_S_BASE + 14)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_INTF_VER 1
#define VDEC_MSG_BASE 0x0000000
#define VDEC_MSG_INVALID (VDEC_MSG_BASE + 0)
#define VDEC_MSG_RESP_INPUT_BUFFER_DONE (VDEC_MSG_BASE + 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_MSG_RESP_OUTPUT_BUFFER_DONE (VDEC_MSG_BASE + 2)
#define VDEC_MSG_RESP_INPUT_FLUSHED (VDEC_MSG_BASE + 3)
#define VDEC_MSG_RESP_OUTPUT_FLUSHED (VDEC_MSG_BASE + 4)
#define VDEC_MSG_RESP_FLUSH_INPUT_DONE (VDEC_MSG_BASE + 5)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_MSG_RESP_FLUSH_OUTPUT_DONE (VDEC_MSG_BASE + 6)
#define VDEC_MSG_RESP_START_DONE (VDEC_MSG_BASE + 7)
#define VDEC_MSG_RESP_STOP_DONE (VDEC_MSG_BASE + 8)
#define VDEC_MSG_RESP_PAUSE_DONE (VDEC_MSG_BASE + 9)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_MSG_RESP_RESUME_DONE (VDEC_MSG_BASE + 10)
#define VDEC_MSG_RESP_RESOURCE_LOADED (VDEC_MSG_BASE + 11)
#define VDEC_EVT_RESOURCES_LOST (VDEC_MSG_BASE + 12)
#define VDEC_MSG_EVT_CONFIG_CHANGED (VDEC_MSG_BASE + 13)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_MSG_EVT_HW_ERROR (VDEC_MSG_BASE + 14)
#define VDEC_MSG_EVT_INFO_CONFIG_CHANGED (VDEC_MSG_BASE + 15)
#define VDEC_MSG_EVT_INFO_FIELD_DROPPED (VDEC_MSG_BASE + 16)
#define VDEC_BUFFERFLAG_EOS 0x00000001
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_BUFFERFLAG_DECODEONLY 0x00000004
#define VDEC_BUFFERFLAG_DATACORRUPT 0x00000008
#define VDEC_BUFFERFLAG_ENDOFFRAME 0x00000010
#define VDEC_BUFFERFLAG_SYNCFRAME 0x00000020
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_BUFFERFLAG_EXTRADATA 0x00000040
#define VDEC_BUFFERFLAG_CODECCONFIG 0x00000080
#define VDEC_EXTRADATA_NONE 0x001
#define VDEC_EXTRADATA_QP 0x004
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_EXTRADATA_MB_ERROR_MAP 0x008
#define VDEC_EXTRADATA_SEI 0x010
#define VDEC_EXTRADATA_VUI 0x020
#define VDEC_EXTRADATA_VC1 0x040
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_CMDBASE 0x800
#define VDEC_CMD_SET_INTF_VERSION (VDEC_CMDBASE)
#define VDEC_IOCTL_MAGIC 'v'
struct vdec_ioctl_msg {
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void __user *in;
  void __user *out;
};
#define VDEC_IOCTL_GET_PROFILE_LEVEL_SUPPORTED   _IOWR(VDEC_IOCTL_MAGIC, 0, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_GET_INTERLACE_FORMAT   _IOR(VDEC_IOCTL_MAGIC, 1, struct vdec_ioctl_msg)
#define VDEC_IOCTL_GET_CURRENT_PROFILE_LEVEL   _IOWR(VDEC_IOCTL_MAGIC, 2, struct vdec_ioctl_msg)
#define VDEC_IOCTL_SET_OUTPUT_FORMAT   _IOWR(VDEC_IOCTL_MAGIC, 3, struct vdec_ioctl_msg)
#define VDEC_IOCTL_GET_OUTPUT_FORMAT   _IOWR(VDEC_IOCTL_MAGIC, 4, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_SET_CODEC   _IOW(VDEC_IOCTL_MAGIC, 5, struct vdec_ioctl_msg)
#define VDEC_IOCTL_GET_CODEC   _IOR(VDEC_IOCTL_MAGIC, 6, struct vdec_ioctl_msg)
#define VDEC_IOCTL_SET_PICRES   _IOW(VDEC_IOCTL_MAGIC, 7, struct vdec_ioctl_msg)
#define VDEC_IOCTL_GET_PICRES   _IOR(VDEC_IOCTL_MAGIC, 8, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_SET_EXTRADATA   _IOW(VDEC_IOCTL_MAGIC, 9, struct vdec_ioctl_msg)
#define VDEC_IOCTL_GET_EXTRADATA   _IOR(VDEC_IOCTL_MAGIC, 10, struct vdec_ioctl_msg)
#define VDEC_IOCTL_SET_SEQUENCE_HEADER   _IOW(VDEC_IOCTL_MAGIC, 11, struct vdec_ioctl_msg)
#define VDEC_IOCTL_SET_BUFFER_REQ   _IOW(VDEC_IOCTL_MAGIC, 12, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_GET_BUFFER_REQ   _IOR(VDEC_IOCTL_MAGIC, 13, struct vdec_ioctl_msg)
#define VDEC_IOCTL_ALLOCATE_BUFFER   _IOWR(VDEC_IOCTL_MAGIC, 14, struct vdec_ioctl_msg)
#define VDEC_IOCTL_FREE_BUFFER   _IOW(VDEC_IOCTL_MAGIC, 15, struct vdec_ioctl_msg)
#define VDEC_IOCTL_SET_BUFFER   _IOW(VDEC_IOCTL_MAGIC, 16, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_FILL_OUTPUT_BUFFER   _IOW(VDEC_IOCTL_MAGIC, 17, struct vdec_ioctl_msg)
#define VDEC_IOCTL_DECODE_FRAME   _IOW(VDEC_IOCTL_MAGIC, 18, struct vdec_ioctl_msg)
#define VDEC_IOCTL_LOAD_RESOURCES _IO(VDEC_IOCTL_MAGIC, 19)
#define VDEC_IOCTL_CMD_START _IO(VDEC_IOCTL_MAGIC, 20)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_CMD_STOP _IO(VDEC_IOCTL_MAGIC, 21)
#define VDEC_IOCTL_CMD_PAUSE _IO(VDEC_IOCTL_MAGIC, 22)
#define VDEC_IOCTL_CMD_RESUME _IO(VDEC_IOCTL_MAGIC, 23)
#define VDEC_IOCTL_CMD_FLUSH _IOW(VDEC_IOCTL_MAGIC, 24, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_GET_NEXT_MSG   _IOR(VDEC_IOCTL_MAGIC, 25, struct vdec_ioctl_msg)
#define VDEC_IOCTL_STOP_NEXT_MSG _IO(VDEC_IOCTL_MAGIC, 26)
#define VDEC_IOCTL_GET_NUMBER_INSTANCES   _IOR(VDEC_IOCTL_MAGIC, 27, struct vdec_ioctl_msg)
#define VDEC_IOCTL_SET_PICTURE_ORDER   _IOW(VDEC_IOCTL_MAGIC, 28, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_SET_FRAME_RATE   _IOW(VDEC_IOCTL_MAGIC, 29, struct vdec_ioctl_msg)
#define VDEC_IOCTL_SET_H264_MV_BUFFER   _IOW(VDEC_IOCTL_MAGIC, 30, struct vdec_ioctl_msg)
#define VDEC_IOCTL_FREE_H264_MV_BUFFER   _IOW(VDEC_IOCTL_MAGIC, 31, struct vdec_ioctl_msg)
#define VDEC_IOCTL_GET_MV_BUFFER_SIZE   _IOR(VDEC_IOCTL_MAGIC, 32, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_SET_IDR_ONLY_DECODING   _IO(VDEC_IOCTL_MAGIC, 33)
#define VDEC_IOCTL_SET_CONT_ON_RECONFIG   _IO(VDEC_IOCTL_MAGIC, 34)
#define VDEC_IOCTL_SET_DISABLE_DMX   _IOW(VDEC_IOCTL_MAGIC, 35, struct vdec_ioctl_msg)
#define VDEC_IOCTL_GET_DISABLE_DMX   _IOR(VDEC_IOCTL_MAGIC, 36, struct vdec_ioctl_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VDEC_IOCTL_GET_DISABLE_DMX_SUPPORT   _IOR(VDEC_IOCTL_MAGIC, 37, struct vdec_ioctl_msg)
enum vdec_picture {
  PICTURE_TYPE_I,
  PICTURE_TYPE_P,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  PICTURE_TYPE_B,
  PICTURE_TYPE_BI,
  PICTURE_TYPE_SKIP,
  PICTURE_TYPE_IDR,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 PICTURE_TYPE_UNKNOWN
};
enum vdec_buffer {
  VDEC_BUFFER_TYPE_INPUT,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VDEC_BUFFER_TYPE_OUTPUT
};
struct vdec_allocatorproperty {
  enum vdec_buffer buffer_type;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t mincount;
  uint32_t maxcount;
  uint32_t actualcount;
  size_t buffer_size;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t alignment;
  uint32_t buf_poolid;
};
struct vdec_bufferpayload {
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void __user *bufferaddr;
  size_t buffer_len;
  int pmem_fd;
  size_t offset;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  size_t mmaped_size;
};
struct vdec_setbuffer_cmd {
  enum vdec_buffer buffer_type;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct vdec_bufferpayload buffer;
};
struct vdec_fillbuffer_cmd {
  struct vdec_bufferpayload buffer;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void *client_data;
};
enum vdec_bufferflush {
  VDEC_FLUSH_TYPE_INPUT,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_FLUSH_TYPE_OUTPUT,
 VDEC_FLUSH_TYPE_ALL
};
enum vdec_codec {
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_CODECTYPE_H264 = 0x1,
  VDEC_CODECTYPE_H263 = 0x2,
  VDEC_CODECTYPE_MPEG4 = 0x3,
  VDEC_CODECTYPE_DIVX_3 = 0x4,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_CODECTYPE_DIVX_4 = 0x5,
  VDEC_CODECTYPE_DIVX_5 = 0x6,
  VDEC_CODECTYPE_DIVX_6 = 0x7,
  VDEC_CODECTYPE_XVID = 0x8,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_CODECTYPE_MPEG1 = 0x9,
  VDEC_CODECTYPE_MPEG2 = 0xa,
  VDEC_CODECTYPE_VC1 = 0xb,
 VDEC_CODECTYPE_VC1_RCV = 0xc
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum vdec_mpeg2_profile {
  VDEC_MPEG2ProfileSimple = 0x1,
  VDEC_MPEG2ProfileMain = 0x2,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG2Profile422 = 0x4,
  VDEC_MPEG2ProfileSNR = 0x8,
  VDEC_MPEG2ProfileSpatial = 0x10,
  VDEC_MPEG2ProfileHigh = 0x20,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG2ProfileKhronosExtensions = 0x6F000000,
  VDEC_MPEG2ProfileVendorStartUnused = 0x7F000000,
 VDEC_MPEG2ProfileMax = 0x7FFFFFFF
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum vdec_mpeg2_level {
  VDEC_MPEG2LevelLL = 0x1,
  VDEC_MPEG2LevelML = 0x2,
  VDEC_MPEG2LevelH14 = 0x4,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG2LevelHL = 0x8,
  VDEC_MPEG2LevelKhronosExtensions = 0x6F000000,
  VDEC_MPEG2LevelVendorStartUnused = 0x7F000000,
 VDEC_MPEG2LevelMax = 0x7FFFFFFF
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum vdec_mpeg4_profile {
  VDEC_MPEG4ProfileSimple = 0x01,
  VDEC_MPEG4ProfileSimpleScalable = 0x02,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG4ProfileCore = 0x04,
  VDEC_MPEG4ProfileMain = 0x08,
  VDEC_MPEG4ProfileNbit = 0x10,
  VDEC_MPEG4ProfileScalableTexture = 0x20,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG4ProfileSimpleFace = 0x40,
  VDEC_MPEG4ProfileSimpleFBA = 0x80,
  VDEC_MPEG4ProfileBasicAnimated = 0x100,
  VDEC_MPEG4ProfileHybrid = 0x200,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG4ProfileAdvancedRealTime = 0x400,
  VDEC_MPEG4ProfileCoreScalable = 0x800,
  VDEC_MPEG4ProfileAdvancedCoding = 0x1000,
  VDEC_MPEG4ProfileAdvancedCore = 0x2000,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG4ProfileAdvancedScalable = 0x4000,
  VDEC_MPEG4ProfileAdvancedSimple = 0x8000,
  VDEC_MPEG4ProfileKhronosExtensions = 0x6F000000,
  VDEC_MPEG4ProfileVendorStartUnused = 0x7F000000,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VDEC_MPEG4ProfileMax = 0x7FFFFFFF
};
enum vdec_mpeg4_level {
  VDEC_MPEG4Level0 = 0x01,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG4Level0b = 0x02,
  VDEC_MPEG4Level1 = 0x04,
  VDEC_MPEG4Level2 = 0x08,
  VDEC_MPEG4Level3 = 0x10,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG4Level4 = 0x20,
  VDEC_MPEG4Level4a = 0x40,
  VDEC_MPEG4Level5 = 0x80,
  VDEC_MPEG4LevelKhronosExtensions = 0x6F000000,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_MPEG4LevelVendorStartUnused = 0x7F000000,
 VDEC_MPEG4LevelMax = 0x7FFFFFFF
};
enum vdec_avc_profile {
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCProfileBaseline = 0x01,
  VDEC_AVCProfileMain = 0x02,
  VDEC_AVCProfileExtended = 0x04,
  VDEC_AVCProfileHigh = 0x08,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCProfileHigh10 = 0x10,
  VDEC_AVCProfileHigh422 = 0x20,
  VDEC_AVCProfileHigh444 = 0x40,
  VDEC_AVCProfileKhronosExtensions = 0x6F000000,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCProfileVendorStartUnused = 0x7F000000,
 VDEC_AVCProfileMax = 0x7FFFFFFF
};
enum vdec_avc_level {
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCLevel1 = 0x01,
  VDEC_AVCLevel1b = 0x02,
  VDEC_AVCLevel11 = 0x04,
  VDEC_AVCLevel12 = 0x08,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCLevel13 = 0x10,
  VDEC_AVCLevel2 = 0x20,
  VDEC_AVCLevel21 = 0x40,
  VDEC_AVCLevel22 = 0x80,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCLevel3 = 0x100,
  VDEC_AVCLevel31 = 0x200,
  VDEC_AVCLevel32 = 0x400,
  VDEC_AVCLevel4 = 0x800,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCLevel41 = 0x1000,
  VDEC_AVCLevel42 = 0x2000,
  VDEC_AVCLevel5 = 0x4000,
  VDEC_AVCLevel51 = 0x8000,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_AVCLevelKhronosExtensions = 0x6F000000,
  VDEC_AVCLevelVendorStartUnused = 0x7F000000,
 VDEC_AVCLevelMax = 0x7FFFFFFF
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum vdec_divx_profile {
  VDEC_DIVXProfile_qMobile = 0x01,
  VDEC_DIVXProfile_Mobile = 0x02,
  VDEC_DIVXProfile_HD = 0x04,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_DIVXProfile_Handheld = 0x08,
  VDEC_DIVXProfile_Portable = 0x10,
 VDEC_DIVXProfile_HomeTheater = 0x20
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum vdec_xvid_profile {
  VDEC_XVIDProfile_Simple = 0x1,
  VDEC_XVIDProfile_Advanced_Realtime_Simple = 0x2,
 VDEC_XVIDProfile_Advanced_Simple = 0x4
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum vdec_xvid_level {
  VDEC_XVID_LEVEL_S_L0 = 0x1,
  VDEC_XVID_LEVEL_S_L1 = 0x2,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_XVID_LEVEL_S_L2 = 0x4,
  VDEC_XVID_LEVEL_S_L3 = 0x8,
  VDEC_XVID_LEVEL_ARTS_L1 = 0x10,
  VDEC_XVID_LEVEL_ARTS_L2 = 0x20,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_XVID_LEVEL_ARTS_L3 = 0x40,
  VDEC_XVID_LEVEL_ARTS_L4 = 0x80,
  VDEC_XVID_LEVEL_AS_L0 = 0x100,
  VDEC_XVID_LEVEL_AS_L1 = 0x200,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_XVID_LEVEL_AS_L2 = 0x400,
  VDEC_XVID_LEVEL_AS_L3 = 0x800,
 VDEC_XVID_LEVEL_AS_L4 = 0x1000
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum vdec_h263profile {
  VDEC_H263ProfileBaseline = 0x01,
  VDEC_H263ProfileH320Coding = 0x02,
  VDEC_H263ProfileBackwardCompatible = 0x04,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_H263ProfileISWV2 = 0x08,
  VDEC_H263ProfileISWV3 = 0x10,
  VDEC_H263ProfileHighCompression = 0x20,
  VDEC_H263ProfileInternet = 0x40,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_H263ProfileInterlace = 0x80,
  VDEC_H263ProfileHighLatency = 0x100,
  VDEC_H263ProfileKhronosExtensions = 0x6F000000,
  VDEC_H263ProfileVendorStartUnused = 0x7F000000,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VDEC_H263ProfileMax = 0x7FFFFFFF
};
enum vdec_h263level {
  VDEC_H263Level10 = 0x01,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_H263Level20 = 0x02,
  VDEC_H263Level30 = 0x04,
  VDEC_H263Level40 = 0x08,
  VDEC_H263Level45 = 0x10,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_H263Level50 = 0x20,
  VDEC_H263Level60 = 0x40,
  VDEC_H263Level70 = 0x80,
  VDEC_H263LevelKhronosExtensions = 0x6F000000,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_H263LevelVendorStartUnused = 0x7F000000,
 VDEC_H263LevelMax = 0x7FFFFFFF
};
enum vdec_wmv_format {
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_WMVFormatUnused = 0x01,
  VDEC_WMVFormat7 = 0x02,
  VDEC_WMVFormat8 = 0x04,
  VDEC_WMVFormat9 = 0x08,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_WMFFormatKhronosExtensions = 0x6F000000,
  VDEC_WMFFormatVendorStartUnused = 0x7F000000,
 VDEC_WMVFormatMax = 0x7FFFFFFF
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum vdec_vc1_profile {
  VDEC_VC1ProfileSimple = 0x1,
  VDEC_VC1ProfileMain = 0x2,
 VDEC_VC1ProfileAdvanced = 0x4
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum vdec_vc1_level {
  VDEC_VC1_LEVEL_S_Low = 0x1,
  VDEC_VC1_LEVEL_S_Medium = 0x2,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_VC1_LEVEL_M_Low = 0x4,
  VDEC_VC1_LEVEL_M_Medium = 0x8,
  VDEC_VC1_LEVEL_M_High = 0x10,
  VDEC_VC1_LEVEL_A_L0 = 0x20,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  VDEC_VC1_LEVEL_A_L1 = 0x40,
  VDEC_VC1_LEVEL_A_L2 = 0x80,
  VDEC_VC1_LEVEL_A_L3 = 0x100,
 VDEC_VC1_LEVEL_A_L4 = 0x200
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct vdec_profile_level {
  uint32_t profiles;
  uint32_t levels;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum vdec_interlaced_format {
  VDEC_InterlaceFrameProgressive = 0x1,
  VDEC_InterlaceInterleaveFrameTopFieldFirst = 0x2,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VDEC_InterlaceInterleaveFrameBottomFieldFirst = 0x4
};
enum vdec_output_fromat {
  VDEC_YUV_FORMAT_NV12 = 0x1,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VDEC_YUV_FORMAT_TILE_4x2 = 0x2
};
enum vdec_output_order {
  VDEC_ORDER_DISPLAY = 0x1,
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VDEC_ORDER_DECODE = 0x2
};
struct vdec_picsize {
  uint32_t frame_width;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t frame_height;
  uint32_t stride;
  uint32_t scan_lines;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vdec_seqheader {
  void __user *ptr_seqheader;
  size_t seq_header_len;
  int pmem_fd;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  size_t pmem_offset;
};
struct vdec_mberror {
  void __user *ptr_errormap;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  size_t err_mapsize;
};
struct vdec_input_frameinfo {
  void __user *bufferaddr;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  size_t offset;
  size_t datalen;
  uint32_t flags;
  int64_t timestamp;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void *client_data;
  int pmem_fd;
  size_t pmem_offset;
  void __user *desc_addr;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t desc_size;
};
struct vdec_framesize {
  uint32_t left;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t top;
  uint32_t right;
  uint32_t bottom;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vdec_aspectratioinfo {
  uint32_t aspect_ratio;
  uint32_t par_width;
  uint32_t par_height;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct vdec_output_frameinfo {
  void __user *bufferaddr;
  size_t offset;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  size_t len;
  uint32_t flags;
  int64_t time_stamp;
  enum vdec_picture pic_type;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void *client_data;
  void *input_frame_clientdata;
  struct vdec_framesize framesize;
  enum vdec_interlaced_format interlaced_format;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct vdec_aspectratioinfo aspect_ratio_info;
};
union vdec_msgdata {
  struct vdec_output_frameinfo output_frame;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  void *input_frame_clientdata;
};
struct vdec_msginfo {
  uint32_t status_code;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t msgcode;
  union vdec_msgdata msgdata;
  size_t msgdatasize;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vdec_framerate {
  unsigned long fps_denominator;
  unsigned long fps_numerator;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vdec_h264_mv{
  size_t size;
  int count;
  int pmem_fd;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int offset;
};
struct vdec_mv_buff_size{
  int width;
  /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int height;
  int size;
  int alignment;
};
