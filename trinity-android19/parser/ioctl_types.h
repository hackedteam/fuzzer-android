struct qseecom_register_listener_req {
  uint32_t listener_id;
  int32_t ifd_data_fd;
  uint32_t virt_sb_base;
  uint32_t sb_size;
};

struct qseecom_send_cmd_req {
  void *cmd_req_buf;
  int cmd_req_len; 
  void *resp_buf; 
  int resp_len; 
};

struct qseecom_ion_fd_info {
  int32_t fd;
  uint32_t cmd_buf_offset;
};

struct qseecom_send_modfd_cmd_req {
  void *cmd_req_buf; 
  int cmd_req_len; 
  void *resp_buf; 
  int resp_len; 
  struct qseecom_ion_fd_info ifd_data[4];
};


struct qseecom_send_resp_req {
  void *resp_buf; 
  int resp_len; 
};


struct qseecom_load_img_req {
  uint32_t mdt_len; 
  uint32_t img_len; 
  int32_t  ifd_data_fd; 
  char img_name[32]; 
  int app_id; 
};

struct qseecom_set_sb_mem_param_req {
  int32_t ifd_data_fd; 
  uint32_t virt_sb_base;
  uint32_t sb_len;
};

struct qseecom_qseos_version_req {
  int qseos_version;
};


struct qseecom_qseos_app_load_query {
  char app_name[32]; 
  int app_id; 

};

struct kgsl_devinfo {

  int device_id;
  int chip_id;
  int mmu_enabled;
  int gmem_gpubaseaddr;
  int gpu_id;
  int gmem_sizebytes;
};


struct kgsl_devmemstore {
  int soptimestamp;
  int sbz;
  int eoptimestamp;
  int sbz2;
  int ts_cmp_enable;
  int sbz3;
  int ref_wait_ts;
  int sbz4;
  int current_context;
  int sbz5;
};


struct kgsl_shadowprop {
  int gpuaddr;
  int size;
  int flags;
};

struct kgsl_version {
  int drv_major;
  int drv_minor;
  int dev_major;
  int dev_minor;
};


struct kgsl_ibdesc {
  int gpuaddr;
  void *hostptr;
  int sizedwords;
  int ctrl;
};


struct kgsl_device_getproperty {
  int type;
  void  *value;
  int sizebytes;
};


struct kgsl_device_waittimestamp {
  int timestamp;
  int timeout;
};


struct kgsl_device_waittimestamp_ctxtid {
  int context_id;
  int timestamp;
  int timeout;
};


struct kgsl_ringbuffer_issueibcmds {
  int drawctxt_id;
  void *ibdesc_addr;
  int numibs;
  int timestamp;
  int flags;
};


struct kgsl_cmdstream_readtimestamp {
  int type;
  int timestamp;
};


struct kgsl_cmdstream_freememontimestamp {
  void *gpuaddr;
  int type;
  int timestamp;
};


struct kgsl_drawctxt_create {
  int flags;
  int drawctxt_id;
};


struct kgsl_map_user_mem {
  int fd;
  void *gpuaddr;  
  int len;
  int offset;
  void *hostptr;
  enum kgsl_user_mem_type memtype;
  int flags;
};


struct kgsl_cmdstream_readtimestamp_ctxtid {
  int context_id;
  int type;
  int timestamp;
};

struct kgsl_cmdstream_freememontimestamp_ctxtid {
  int context_id;
  void *gpuaddr;
  int type;
  int timestamp;
};


struct kgsl_sharedmem_from_pmem {
  int pmem_fd;
  void *gpuaddr;
  int len;
  int offset;
};


struct kgsl_sharedmem_free {
  void *gpuaddr;
};


struct kgsl_cff_user_event {
  unsigned char cff_opcode;
  int op1;
  int op2;
  int op3;
  int op4;
  int op5;
  int __pad[2];
};


struct kgsl_gmem_desc {
  int x;
  int y;
  int width;
  int height;
  int pitch;
};


struct kgsl_buffer_desc {
  void *hostptr;
  void *gpuaddr;
  int   size;
  int format;
  int pitch;
  int enabled;
};

struct kgsl_bind_gmem_shadow {
  int drawctxt_id;
  struct kgsl_gmem_desc gmem_desc;
  int shadow_x;
  int shadow_y;
  struct kgsl_buffer_desc shadow_buffer;
  int buffer_id;
};

struct kgsl_sharedmem_from_vmalloc {
  void *gpuaddr;
  void *hostptr;
  int flags;
};


struct kgsl_drawctxt_set_bin_base_offset {
  int drawctxt_id;
  int offset;
};

struct kgsl_cmdwindow_write {
  enum kgsl_cmdwindow_type target;
  void *addr;
  int data;
};


struct kgsl_cff_syncmem {
  void *gpuaddr;
  int len;
  int __pad[2];
};

struct kgsl_timestamp_event {
  int type; 
  int timestamp;
  int context_id;
  void *priv; 
  size_t len; 
};


struct kgsl_timestamp_event_genlock {
  int handle;
};


struct kgsl_timestamp_event_fence {
  int fence_fd;
};


struct kgsl_gpumem_alloc_id {
  int id;
  int flags;
  int size;
  int mmapsize;
  void  *gpuaddr;
  int __pad[2];
};


struct kgsl_gpumem_free_id {
  int id;
  int __pad;
};


struct kgsl_gpumem_get_info {
  void *gpuaddr;
  int id;
  int flags;
  int size;
  int mmapsize;
  void *useraddr;
  int __pad[4];
};


struct kgsl_gpumem_sync_cache {
  void *gpuaddr;
  int id;
  int op;
  int __pad[2]; 
};

struct kgsl_perfcounter_get {
  int groupid;
  int countable;
  int offset;
  int __pad[2];
};


struct kgsl_perfcounter_put {
  int groupid;
  int countable;
  int __pad[2];
};


struct kgsl_perfcounter_query {
  int groupid;
  int *countables;
  int count;
  int max_counters;
  int __pad[2];
};


struct kgsl_perfcounter_read_group {
  int groupid;
  int countable;
  uint64_t value;
};

struct kgsl_perfcounter_read {
  struct kgsl_perfcounter_read_group *reads;
  int count;
  int __pad[2];
};



struct kgsl_drawctxt_destroy {
  int drawctxt_id;
};


struct kgsl_gpumem_alloc {
  void *gpuaddr;
  size_t size;
  int flags;
};
