/* Automatically generated */
#include <stdlib.h>
#include "child.h"
#include "ioctls.h"
#include "ioctl_types.h"
#include "maps.h"
#include "random.h"
#include "sanitise.h"
#include "shm.h"
#include "syscall.h"
#include "trinity.h"
#include "fuzz_ioctl_struct.h"

static void * recursive_fuzz(enum ioctl_struct_type type, void * local_addr) {

switch(type) {
struct qseecom_register_listener_req *p0;
struct qseecom_send_cmd_req *p1;
struct qseecom_ion_fd_info *p2;
struct qseecom_send_modfd_cmd_req *p3;
struct qseecom_send_resp_req *p4;
struct qseecom_load_img_req *p5;
struct qseecom_set_sb_mem_param_req *p6;
struct qseecom_qseos_version_req *p7;
struct qseecom_qseos_app_load_query *p8;
struct kgsl_devinfo *p9;
struct kgsl_devmemstore *p10;
struct kgsl_shadowprop *p11;
struct kgsl_version *p12;
struct kgsl_ibdesc *p13;
struct kgsl_device_getproperty *p14;
struct kgsl_device_waittimestamp *p15;
struct kgsl_device_waittimestamp_ctxtid *p16;
struct kgsl_ringbuffer_issueibcmds *p17;
struct kgsl_cmdstream_readtimestamp *p18;
struct kgsl_cmdstream_freememontimestamp *p19;
struct kgsl_drawctxt_create *p20;
struct kgsl_map_user_mem *p21;
struct kgsl_cmdstream_readtimestamp_ctxtid *p22;
struct kgsl_cmdstream_freememontimestamp_ctxtid *p23;
struct kgsl_sharedmem_from_pmem *p24;
struct kgsl_sharedmem_free *p25;
struct kgsl_cff_user_event *p26;
struct kgsl_gmem_desc *p27;
struct kgsl_buffer_desc *p28;
struct kgsl_bind_gmem_shadow *p29;
struct kgsl_sharedmem_from_vmalloc *p30;
struct kgsl_drawctxt_set_bin_base_offset *p31;
struct kgsl_cmdwindow_write *p32;
struct kgsl_cff_syncmem *p33;
struct kgsl_timestamp_event *p34;
struct kgsl_timestamp_event_genlock *p35;
struct kgsl_timestamp_event_fence *p36;
struct kgsl_gpumem_alloc_id *p37;
struct kgsl_gpumem_free_id *p38;
struct kgsl_gpumem_get_info *p39;
struct kgsl_gpumem_sync_cache *p40;
struct kgsl_perfcounter_get *p41;
struct kgsl_perfcounter_put *p42;
struct kgsl_perfcounter_query *p43;
struct kgsl_perfcounter_read_group *p44;
struct kgsl_perfcounter_read *p45;
struct kgsl_drawctxt_destroy *p46;
struct kgsl_gpumem_alloc *p47;


case STRUCT_qseecom_register_listener_req:
if(local_addr != NULL)
p0 = (struct qseecom_register_listener_req *)local_addr;
else
p0 = (struct qseecom_register_listener_req *)get_writable_address(sizeof(struct qseecom_register_listener_req));
if(p0) {
//listener_id is primitive
//ifd_data_fd is primitive
//virt_sb_base is primitive
//sb_size is primitive
return p0;
}
return get_non_null_address();


case STRUCT_qseecom_send_cmd_req:
if(local_addr != NULL)
p1 = (struct qseecom_send_cmd_req *)local_addr;
else
p1 = (struct qseecom_send_cmd_req *)get_writable_address(sizeof(struct qseecom_send_cmd_req));
if(p1) {
p1->cmd_req_buf = (void *) get_non_null_address();
//cmd_req_len is primitive
p1->resp_buf = (void *) get_non_null_address();
//resp_len is primitive
return p1;
}
return get_non_null_address();


case STRUCT_qseecom_ion_fd_info:
if(local_addr != NULL)
p2 = (struct qseecom_ion_fd_info *)local_addr;
else
p2 = (struct qseecom_ion_fd_info *)get_writable_address(sizeof(struct qseecom_ion_fd_info));
if(p2) {
//fd is primitive
//cmd_buf_offset is primitive
return p2;
}
return get_non_null_address();


case STRUCT_qseecom_send_modfd_cmd_req:
if(local_addr != NULL)
p3 = (struct qseecom_send_modfd_cmd_req *)local_addr;
else
p3 = (struct qseecom_send_modfd_cmd_req *)get_writable_address(sizeof(struct qseecom_send_modfd_cmd_req));
if(p3) {
p3->cmd_req_buf = (void *) get_non_null_address();
//cmd_req_len is primitive
p3->resp_buf = (void *) get_non_null_address();
//resp_len is primitive
recursive_fuzz(STRUCT_qseecom_ion_fd_info, &p3->ifd_data[0]);
recursive_fuzz(STRUCT_qseecom_ion_fd_info, &p3->ifd_data[1]);
recursive_fuzz(STRUCT_qseecom_ion_fd_info, &p3->ifd_data[2]);
recursive_fuzz(STRUCT_qseecom_ion_fd_info, &p3->ifd_data[3]);
//ifd_data is an array of qseecom_ion_fd_info of 4 elements
return p3;
}
return get_non_null_address();


case STRUCT_qseecom_send_resp_req:
if(local_addr != NULL)
p4 = (struct qseecom_send_resp_req *)local_addr;
else
p4 = (struct qseecom_send_resp_req *)get_writable_address(sizeof(struct qseecom_send_resp_req));
if(p4) {
p4->resp_buf = (void *) get_non_null_address();
//resp_len is primitive
return p4;
}
return get_non_null_address();


case STRUCT_qseecom_load_img_req:
if(local_addr != NULL)
p5 = (struct qseecom_load_img_req *)local_addr;
else
p5 = (struct qseecom_load_img_req *)get_writable_address(sizeof(struct qseecom_load_img_req));
if(p5) {
//mdt_len is primitive
//img_len is primitive
//ifd_data_fd is primitive
//img_name is an array of char of 32 elements
//app_id is primitive
return p5;
}
return get_non_null_address();


case STRUCT_qseecom_set_sb_mem_param_req:
if(local_addr != NULL)
p6 = (struct qseecom_set_sb_mem_param_req *)local_addr;
else
p6 = (struct qseecom_set_sb_mem_param_req *)get_writable_address(sizeof(struct qseecom_set_sb_mem_param_req));
if(p6) {
//ifd_data_fd is primitive
//virt_sb_base is primitive
//sb_len is primitive
return p6;
}
return get_non_null_address();


case STRUCT_qseecom_qseos_version_req:
if(local_addr != NULL)
p7 = (struct qseecom_qseos_version_req *)local_addr;
else
p7 = (struct qseecom_qseos_version_req *)get_writable_address(sizeof(struct qseecom_qseos_version_req));
if(p7) {
//qseos_version is primitive
return p7;
}
return get_non_null_address();


case STRUCT_qseecom_qseos_app_load_query:
if(local_addr != NULL)
p8 = (struct qseecom_qseos_app_load_query *)local_addr;
else
p8 = (struct qseecom_qseos_app_load_query *)get_writable_address(sizeof(struct qseecom_qseos_app_load_query));
if(p8) {
//app_name is an array of char of 32 elements
//app_id is primitive
return p8;
}
return get_non_null_address();


case STRUCT_kgsl_devinfo:
if(local_addr != NULL)
p9 = (struct kgsl_devinfo *)local_addr;
else
p9 = (struct kgsl_devinfo *)get_writable_address(sizeof(struct kgsl_devinfo));
if(p9) {
//device_id is primitive
//chip_id is primitive
//mmu_enabled is primitive
//gmem_gpubaseaddr is primitive
//gpu_id is primitive
//gmem_sizebytes is primitive
return p9;
}
return get_non_null_address();


case STRUCT_kgsl_devmemstore:
if(local_addr != NULL)
p10 = (struct kgsl_devmemstore *)local_addr;
else
p10 = (struct kgsl_devmemstore *)get_writable_address(sizeof(struct kgsl_devmemstore));
if(p10) {
//soptimestamp is primitive
//sbz is primitive
//eoptimestamp is primitive
//sbz2 is primitive
//ts_cmp_enable is primitive
//sbz3 is primitive
//ref_wait_ts is primitive
//sbz4 is primitive
//current_context is primitive
//sbz5 is primitive
return p10;
}
return get_non_null_address();


case STRUCT_kgsl_shadowprop:
if(local_addr != NULL)
p11 = (struct kgsl_shadowprop *)local_addr;
else
p11 = (struct kgsl_shadowprop *)get_writable_address(sizeof(struct kgsl_shadowprop));
if(p11) {
//gpuaddr is primitive
//size is primitive
//flags is primitive
return p11;
}
return get_non_null_address();


case STRUCT_kgsl_version:
if(local_addr != NULL)
p12 = (struct kgsl_version *)local_addr;
else
p12 = (struct kgsl_version *)get_writable_address(sizeof(struct kgsl_version));
if(p12) {
//drv_major is primitive
//drv_minor is primitive
//dev_major is primitive
//dev_minor is primitive
return p12;
}
return get_non_null_address();


case STRUCT_kgsl_ibdesc:
if(local_addr != NULL)
p13 = (struct kgsl_ibdesc *)local_addr;
else
p13 = (struct kgsl_ibdesc *)get_writable_address(sizeof(struct kgsl_ibdesc));
if(p13) {
//gpuaddr is primitive
p13->hostptr = (void *) get_non_null_address();
//sizedwords is primitive
//ctrl is primitive
return p13;
}
return get_non_null_address();


case STRUCT_kgsl_device_getproperty:
if(local_addr != NULL)
p14 = (struct kgsl_device_getproperty *)local_addr;
else
p14 = (struct kgsl_device_getproperty *)get_writable_address(sizeof(struct kgsl_device_getproperty));
if(p14) {
//type is primitive
p14->value = (void *) get_non_null_address();
//sizebytes is primitive
return p14;
}
return get_non_null_address();


case STRUCT_kgsl_device_waittimestamp:
if(local_addr != NULL)
p15 = (struct kgsl_device_waittimestamp *)local_addr;
else
p15 = (struct kgsl_device_waittimestamp *)get_writable_address(sizeof(struct kgsl_device_waittimestamp));
if(p15) {
//timestamp is primitive
//timeout is primitive
return p15;
}
return get_non_null_address();


case STRUCT_kgsl_device_waittimestamp_ctxtid:
if(local_addr != NULL)
p16 = (struct kgsl_device_waittimestamp_ctxtid *)local_addr;
else
p16 = (struct kgsl_device_waittimestamp_ctxtid *)get_writable_address(sizeof(struct kgsl_device_waittimestamp_ctxtid));
if(p16) {
//context_id is primitive
//timestamp is primitive
//timeout is primitive
return p16;
}
return get_non_null_address();


case STRUCT_kgsl_ringbuffer_issueibcmds:
if(local_addr != NULL)
p17 = (struct kgsl_ringbuffer_issueibcmds *)local_addr;
else
p17 = (struct kgsl_ringbuffer_issueibcmds *)get_writable_address(sizeof(struct kgsl_ringbuffer_issueibcmds));
if(p17) {
//drawctxt_id is primitive
p17->ibdesc_addr = (void *) get_non_null_address();
//numibs is primitive
//timestamp is primitive
//flags is primitive
return p17;
}
return get_non_null_address();


case STRUCT_kgsl_cmdstream_readtimestamp:
if(local_addr != NULL)
p18 = (struct kgsl_cmdstream_readtimestamp *)local_addr;
else
p18 = (struct kgsl_cmdstream_readtimestamp *)get_writable_address(sizeof(struct kgsl_cmdstream_readtimestamp));
if(p18) {
//type is primitive
//timestamp is primitive
return p18;
}
return get_non_null_address();


case STRUCT_kgsl_cmdstream_freememontimestamp:
if(local_addr != NULL)
p19 = (struct kgsl_cmdstream_freememontimestamp *)local_addr;
else
p19 = (struct kgsl_cmdstream_freememontimestamp *)get_writable_address(sizeof(struct kgsl_cmdstream_freememontimestamp));
if(p19) {
p19->gpuaddr = (void *) get_non_null_address();
//type is primitive
//timestamp is primitive
return p19;
}
return get_non_null_address();


case STRUCT_kgsl_drawctxt_create:
if(local_addr != NULL)
p20 = (struct kgsl_drawctxt_create *)local_addr;
else
p20 = (struct kgsl_drawctxt_create *)get_writable_address(sizeof(struct kgsl_drawctxt_create));
if(p20) {
//flags is primitive
//drawctxt_id is primitive
return p20;
}
return get_non_null_address();


case STRUCT_kgsl_map_user_mem:
if(local_addr != NULL)
p21 = (struct kgsl_map_user_mem *)local_addr;
else
p21 = (struct kgsl_map_user_mem *)get_writable_address(sizeof(struct kgsl_map_user_mem));
if(p21) {
//fd is primitive
p21->gpuaddr = (void *) get_non_null_address();
//len is primitive
//offset is primitive
p21->hostptr = (void *) get_non_null_address();
//enum kgsl_user_mem_type;
//flags is primitive
return p21;
}
return get_non_null_address();


case STRUCT_kgsl_cmdstream_readtimestamp_ctxtid:
if(local_addr != NULL)
p22 = (struct kgsl_cmdstream_readtimestamp_ctxtid *)local_addr;
else
p22 = (struct kgsl_cmdstream_readtimestamp_ctxtid *)get_writable_address(sizeof(struct kgsl_cmdstream_readtimestamp_ctxtid));
if(p22) {
//context_id is primitive
//type is primitive
//timestamp is primitive
return p22;
}
return get_non_null_address();


case STRUCT_kgsl_cmdstream_freememontimestamp_ctxtid:
if(local_addr != NULL)
p23 = (struct kgsl_cmdstream_freememontimestamp_ctxtid *)local_addr;
else
p23 = (struct kgsl_cmdstream_freememontimestamp_ctxtid *)get_writable_address(sizeof(struct kgsl_cmdstream_freememontimestamp_ctxtid));
if(p23) {
//context_id is primitive
p23->gpuaddr = (void *) get_non_null_address();
//type is primitive
//timestamp is primitive
return p23;
}
return get_non_null_address();


case STRUCT_kgsl_sharedmem_from_pmem:
if(local_addr != NULL)
p24 = (struct kgsl_sharedmem_from_pmem *)local_addr;
else
p24 = (struct kgsl_sharedmem_from_pmem *)get_writable_address(sizeof(struct kgsl_sharedmem_from_pmem));
if(p24) {
//pmem_fd is primitive
p24->gpuaddr = (void *) get_non_null_address();
//len is primitive
//offset is primitive
return p24;
}
return get_non_null_address();


case STRUCT_kgsl_sharedmem_free:
if(local_addr != NULL)
p25 = (struct kgsl_sharedmem_free *)local_addr;
else
p25 = (struct kgsl_sharedmem_free *)get_writable_address(sizeof(struct kgsl_sharedmem_free));
if(p25) {
p25->gpuaddr = (void *) get_non_null_address();
return p25;
}
return get_non_null_address();


case STRUCT_kgsl_cff_user_event:
if(local_addr != NULL)
p26 = (struct kgsl_cff_user_event *)local_addr;
else
p26 = (struct kgsl_cff_user_event *)get_writable_address(sizeof(struct kgsl_cff_user_event));
if(p26) {
//cff_opcode is primitive
//op1 is primitive
//op2 is primitive
//op3 is primitive
//op4 is primitive
//op5 is primitive
//__pad is an array of int of 2 elements
return p26;
}
return get_non_null_address();


case STRUCT_kgsl_gmem_desc:
if(local_addr != NULL)
p27 = (struct kgsl_gmem_desc *)local_addr;
else
p27 = (struct kgsl_gmem_desc *)get_writable_address(sizeof(struct kgsl_gmem_desc));
if(p27) {
//x is primitive
//y is primitive
//width is primitive
//height is primitive
//pitch is primitive
return p27;
}
return get_non_null_address();


case STRUCT_kgsl_buffer_desc:
if(local_addr != NULL)
p28 = (struct kgsl_buffer_desc *)local_addr;
else
p28 = (struct kgsl_buffer_desc *)get_writable_address(sizeof(struct kgsl_buffer_desc));
if(p28) {
p28->hostptr = (void *) get_non_null_address();
p28->gpuaddr = (void *) get_non_null_address();
//size is primitive
//format is primitive
//pitch is primitive
//enabled is primitive
return p28;
}
return get_non_null_address();


case STRUCT_kgsl_bind_gmem_shadow:
if(local_addr != NULL)
p29 = (struct kgsl_bind_gmem_shadow *)local_addr;
else
p29 = (struct kgsl_bind_gmem_shadow *)get_writable_address(sizeof(struct kgsl_bind_gmem_shadow));
if(p29) {
//drawctxt_id is primitive
recursive_fuzz(STRUCT_kgsl_gmem_desc, &p29->gmem_desc);
//shadow_x is primitive
//shadow_y is primitive
recursive_fuzz(STRUCT_kgsl_buffer_desc, &p29->shadow_buffer);
//buffer_id is primitive
return p29;
}
return get_non_null_address();


case STRUCT_kgsl_sharedmem_from_vmalloc:
if(local_addr != NULL)
p30 = (struct kgsl_sharedmem_from_vmalloc *)local_addr;
else
p30 = (struct kgsl_sharedmem_from_vmalloc *)get_writable_address(sizeof(struct kgsl_sharedmem_from_vmalloc));
if(p30) {
p30->gpuaddr = (void *) get_non_null_address();
p30->hostptr = (void *) get_non_null_address();
//flags is primitive
return p30;
}
return get_non_null_address();


case STRUCT_kgsl_drawctxt_set_bin_base_offset:
if(local_addr != NULL)
p31 = (struct kgsl_drawctxt_set_bin_base_offset *)local_addr;
else
p31 = (struct kgsl_drawctxt_set_bin_base_offset *)get_writable_address(sizeof(struct kgsl_drawctxt_set_bin_base_offset));
if(p31) {
//drawctxt_id is primitive
//offset is primitive
return p31;
}
return get_non_null_address();


case STRUCT_kgsl_cmdwindow_write:
if(local_addr != NULL)
p32 = (struct kgsl_cmdwindow_write *)local_addr;
else
p32 = (struct kgsl_cmdwindow_write *)get_writable_address(sizeof(struct kgsl_cmdwindow_write));
if(p32) {
//enum kgsl_cmdwindow_type;
p32->addr = (void *) get_non_null_address();
//data is primitive
return p32;
}
return get_non_null_address();


case STRUCT_kgsl_cff_syncmem:
if(local_addr != NULL)
p33 = (struct kgsl_cff_syncmem *)local_addr;
else
p33 = (struct kgsl_cff_syncmem *)get_writable_address(sizeof(struct kgsl_cff_syncmem));
if(p33) {
p33->gpuaddr = (void *) get_non_null_address();
//len is primitive
//__pad is an array of int of 2 elements
return p33;
}
return get_non_null_address();


case STRUCT_kgsl_timestamp_event:
if(local_addr != NULL)
p34 = (struct kgsl_timestamp_event *)local_addr;
else
p34 = (struct kgsl_timestamp_event *)get_writable_address(sizeof(struct kgsl_timestamp_event));
if(p34) {
//type is primitive
//timestamp is primitive
//context_id is primitive
p34->priv = (void *) get_non_null_address();
//len is primitive
return p34;
}
return get_non_null_address();


case STRUCT_kgsl_timestamp_event_genlock:
if(local_addr != NULL)
p35 = (struct kgsl_timestamp_event_genlock *)local_addr;
else
p35 = (struct kgsl_timestamp_event_genlock *)get_writable_address(sizeof(struct kgsl_timestamp_event_genlock));
if(p35) {
//handle is primitive
return p35;
}
return get_non_null_address();


case STRUCT_kgsl_timestamp_event_fence:
if(local_addr != NULL)
p36 = (struct kgsl_timestamp_event_fence *)local_addr;
else
p36 = (struct kgsl_timestamp_event_fence *)get_writable_address(sizeof(struct kgsl_timestamp_event_fence));
if(p36) {
//fence_fd is primitive
return p36;
}
return get_non_null_address();


case STRUCT_kgsl_gpumem_alloc_id:
if(local_addr != NULL)
p37 = (struct kgsl_gpumem_alloc_id *)local_addr;
else
p37 = (struct kgsl_gpumem_alloc_id *)get_writable_address(sizeof(struct kgsl_gpumem_alloc_id));
if(p37) {
//id is primitive
//flags is primitive
//size is primitive
//mmapsize is primitive
p37->gpuaddr = (void *) get_non_null_address();
//__pad is an array of int of 2 elements
return p37;
}
return get_non_null_address();


case STRUCT_kgsl_gpumem_free_id:
if(local_addr != NULL)
p38 = (struct kgsl_gpumem_free_id *)local_addr;
else
p38 = (struct kgsl_gpumem_free_id *)get_writable_address(sizeof(struct kgsl_gpumem_free_id));
if(p38) {
//id is primitive
//__pad is primitive
return p38;
}
return get_non_null_address();


case STRUCT_kgsl_gpumem_get_info:
if(local_addr != NULL)
p39 = (struct kgsl_gpumem_get_info *)local_addr;
else
p39 = (struct kgsl_gpumem_get_info *)get_writable_address(sizeof(struct kgsl_gpumem_get_info));
if(p39) {
p39->gpuaddr = (void *) get_non_null_address();
//id is primitive
//flags is primitive
//size is primitive
//mmapsize is primitive
p39->useraddr = (void *) get_non_null_address();
//__pad is an array of int of 4 elements
return p39;
}
return get_non_null_address();


case STRUCT_kgsl_gpumem_sync_cache:
if(local_addr != NULL)
p40 = (struct kgsl_gpumem_sync_cache *)local_addr;
else
p40 = (struct kgsl_gpumem_sync_cache *)get_writable_address(sizeof(struct kgsl_gpumem_sync_cache));
if(p40) {
p40->gpuaddr = (void *) get_non_null_address();
//id is primitive
//op is primitive
//__pad is an array of int of 2 elements
return p40;
}
return get_non_null_address();


case STRUCT_kgsl_perfcounter_get:
if(local_addr != NULL)
p41 = (struct kgsl_perfcounter_get *)local_addr;
else
p41 = (struct kgsl_perfcounter_get *)get_writable_address(sizeof(struct kgsl_perfcounter_get));
if(p41) {
//groupid is primitive
//countable is primitive
//offset is primitive
//__pad is an array of int of 2 elements
return p41;
}
return get_non_null_address();


case STRUCT_kgsl_perfcounter_put:
if(local_addr != NULL)
p42 = (struct kgsl_perfcounter_put *)local_addr;
else
p42 = (struct kgsl_perfcounter_put *)get_writable_address(sizeof(struct kgsl_perfcounter_put));
if(p42) {
//groupid is primitive
//countable is primitive
//__pad is an array of int of 2 elements
return p42;
}
return get_non_null_address();


case STRUCT_kgsl_perfcounter_query:
if(local_addr != NULL)
p43 = (struct kgsl_perfcounter_query *)local_addr;
else
p43 = (struct kgsl_perfcounter_query *)get_writable_address(sizeof(struct kgsl_perfcounter_query));
if(p43) {
//groupid is primitive
p43->countables = (int *) get_writable_address(sizeof(int));
//count is primitive
//max_counters is primitive
//__pad is an array of int of 2 elements
return p43;
}
return get_non_null_address();


case STRUCT_kgsl_perfcounter_read_group:
if(local_addr != NULL)
p44 = (struct kgsl_perfcounter_read_group *)local_addr;
else
p44 = (struct kgsl_perfcounter_read_group *)get_writable_address(sizeof(struct kgsl_perfcounter_read_group));
if(p44) {
//groupid is primitive
//countable is primitive
return p44;
}
return get_non_null_address();


case STRUCT_kgsl_perfcounter_read:
if(local_addr != NULL)
p45 = (struct kgsl_perfcounter_read *)local_addr;
else
p45 = (struct kgsl_perfcounter_read *)get_writable_address(sizeof(struct kgsl_perfcounter_read));
if(p45) {
p45->reads = (struct kgsl_perfcounter_read_group *) recursive_fuzz(STRUCT_kgsl_perfcounter_read_group, NULL);
//count is primitive
//__pad is an array of int of 2 elements
return p45;
}
return get_non_null_address();


case STRUCT_kgsl_drawctxt_destroy:
if(local_addr != NULL)
p46 = (struct kgsl_drawctxt_destroy *)local_addr;
else
p46 = (struct kgsl_drawctxt_destroy *)get_writable_address(sizeof(struct kgsl_drawctxt_destroy));
if(p46) {
//drawctxt_id is primitive
return p46;
}
return get_non_null_address();


case STRUCT_kgsl_gpumem_alloc:
if(local_addr != NULL)
p47 = (struct kgsl_gpumem_alloc *)local_addr;
else
p47 = (struct kgsl_gpumem_alloc *)get_writable_address(sizeof(struct kgsl_gpumem_alloc));
if(p47) {
p47->gpuaddr = (void *) get_non_null_address();
//size is primitive
//flags is primitive
return p47;
}
return get_non_null_address();


default:
return get_non_null_address();
}
}

void fuzz_ioctl_struct_type(struct syscallrecord *rec) {

// Sanity check
if(!rec->ioctl_struct_type) {
if(rand_bool()) {
rec->a3 = rand32();
return;
}

rec->a3 = (unsigned long) get_non_null_address();
return;
}

rec->a3 = (unsigned long) recursive_fuzz(rec->ioctl_struct_type, NULL);

return;
}