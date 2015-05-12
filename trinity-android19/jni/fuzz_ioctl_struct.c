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
struct mc_ioctl_init *p48;
struct mc_ioctl_info *p49;
struct mc_ioctl_map *p50;
struct mc_ioctl_reg_wsm *p51;
struct mc_ioctl_execute *p52;
struct mc_ioctl_resolv_cont_wsm *p53;
struct mc_ioctl_resolv_wsm *p54;
struct msm_jpeg_ctrl_cmd *p55;
struct msm_jpeg_buf *p56;
struct msm_jpeg_hw_cmd *p57;
struct msm_jpeg_hw_cmds *p58;
struct timespec *p59;
struct v4l2_capability *p60;
struct v4l2_fmtdesc *p61;
struct v4l2_rect *p62;
struct v4l2_clip *p63;
struct v4l2_window *p64;
struct v4l2_format *p65;
struct v4l2_requestbuffers *p66;
struct v4l2_timecode *p67;
struct v4l2_plane *p68;
struct timeval *p69;
struct v4l2_buffer *p70;
struct v4l2_plane_pix_format *p71;
struct v4l2_pix_format_mplane *p72;
struct v4l2_pix_format *p73;
struct v4l2_framebuffer *p74;
struct v4l2_streamparm *p75;
struct v4l2_fract *p76;
struct v4l2_standard *p77;
struct v4l2_input *p78;
struct v4l2_control *p79;
struct v4l2_tuner *p80;
struct v4l2_modulator *p81;
struct v4l2_audio *p82;
struct v4l2_queryctrl *p83;
struct v4l2_querymenu *p84;
struct v4l2_outputparm *p85;
struct v4l2_audioout *p86;
struct v4l2_frequency *p87;
struct v4l2_cropcap *p88;
struct v4l2_crop *p89;
struct v4l2_jpegcompression *p90;
struct v4l2_sliced_vbi_cap *p91;
struct v4l2_ext_controls *p92;
struct v4l2_frmsize_stepwise *p93;
struct v4l2_frmsizeenum *p94;
struct v4l2_frmival_stepwise *p95;
struct v4l2_frmivalenum *p96;
struct v4l2_enc_idx_entry *p97;
struct v4l2_enc_idx *p98;
struct v4l2_encoder_cmd *p99;
struct v4l2_dbg_match *p100;
struct v4l2_dbg_register *p101;
struct v4l2_dbg_chip_ident *p102;
struct v4l2_hw_freq_seek *p103;
struct v4l2_dv_enum_preset *p104;
struct v4l2_dv_preset *p105;
struct v4l2_dv_timings *p106;
struct v4l2_event *p107;
struct v4l2_event_subscription *p108;
struct v4l2_create_buffers *p109;
struct v4l2_selection *p110;
struct v4l2_decoder_cmd *p111;
struct v4l2_output *p112;


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


case STRUCT_mc_ioctl_init:
if(local_addr != NULL)
p48 = (struct mc_ioctl_init *)local_addr;
else
p48 = (struct mc_ioctl_init *)get_writable_address(sizeof(struct mc_ioctl_init));
if(p48) {
//nq_offset is primitive
//nq_length is primitive
//mcp_offset is primitive
//mcp_length is primitive
return p48;
}
return get_non_null_address();


case STRUCT_mc_ioctl_info:
if(local_addr != NULL)
p49 = (struct mc_ioctl_info *)local_addr;
else
p49 = (struct mc_ioctl_info *)get_writable_address(sizeof(struct mc_ioctl_info));
if(p49) {
//ext_info_id is primitive
//state is primitive
//ext_info is primitive
return p49;
}
return get_non_null_address();


case STRUCT_mc_ioctl_map:
if(local_addr != NULL)
p50 = (struct mc_ioctl_map *)local_addr;
else
p50 = (struct mc_ioctl_map *)get_writable_address(sizeof(struct mc_ioctl_map));
if(p50) {
//len is primitive
//handle is primitive
p50->addr = (void *) get_non_null_address();
p50->phys_addr = (void *) get_non_null_address();
//reused is primitive
return p50;
}
return get_non_null_address();


case STRUCT_mc_ioctl_reg_wsm:
if(local_addr != NULL)
p51 = (struct mc_ioctl_reg_wsm *)local_addr;
else
p51 = (struct mc_ioctl_reg_wsm *)get_writable_address(sizeof(struct mc_ioctl_reg_wsm));
if(p51) {
//len is primitive
//pid is primitive
//handle is primitive
p51->table_phys = (void *) get_non_null_address();
return p51;
}
return get_non_null_address();


case STRUCT_mc_ioctl_execute:
if(local_addr != NULL)
p52 = (struct mc_ioctl_execute *)local_addr;
else
p52 = (struct mc_ioctl_execute *)get_writable_address(sizeof(struct mc_ioctl_execute));
if(p52) {
p52->phys_start_addr = (void *) get_non_null_address();
//length is primitive
return p52;
}
return get_non_null_address();


case STRUCT_mc_ioctl_resolv_cont_wsm:
if(local_addr != NULL)
p53 = (struct mc_ioctl_resolv_cont_wsm *)local_addr;
else
p53 = (struct mc_ioctl_resolv_cont_wsm *)get_writable_address(sizeof(struct mc_ioctl_resolv_cont_wsm));
if(p53) {
//handle is primitive
p53->phys = (void *) get_non_null_address();
//length is primitive
//fd is primitive
return p53;
}
return get_non_null_address();


case STRUCT_mc_ioctl_resolv_wsm:
if(local_addr != NULL)
p54 = (struct mc_ioctl_resolv_wsm *)local_addr;
else
p54 = (struct mc_ioctl_resolv_wsm *)get_writable_address(sizeof(struct mc_ioctl_resolv_wsm));
if(p54) {
//handle is primitive
//fd is primitive
p54->phys = (void *) get_non_null_address();
return p54;
}
return get_non_null_address();


case STRUCT_msm_jpeg_ctrl_cmd:
if(local_addr != NULL)
p55 = (struct msm_jpeg_ctrl_cmd *)local_addr;
else
p55 = (struct msm_jpeg_ctrl_cmd *)get_writable_address(sizeof(struct msm_jpeg_ctrl_cmd));
if(p55) {
//type is primitive
//len is primitive
p55->value = (void *) get_non_null_address();
return p55;
}
return get_non_null_address();


case STRUCT_msm_jpeg_buf:
if(local_addr != NULL)
p56 = (struct msm_jpeg_buf *)local_addr;
else
p56 = (struct msm_jpeg_buf *)get_writable_address(sizeof(struct msm_jpeg_buf));
if(p56) {
//type is primitive
//fd is primitive
p56->vaddr = (void *) get_non_null_address();
//y_off is primitive
//y_len is primitive
//framedone_len is primitive
//cbcr_off is primitive
//cbcr_len is primitive
//num_of_mcu_rows is primitive
//offset is primitive
//pln2_off is primitive
//pln2_len is primitive
return p56;
}
return get_non_null_address();


case STRUCT_msm_jpeg_hw_cmd:
if(local_addr != NULL)
p57 = (struct msm_jpeg_hw_cmd *)local_addr;
else
p57 = (struct msm_jpeg_hw_cmd *)get_writable_address(sizeof(struct msm_jpeg_hw_cmd));
if(p57) {
//type is primitive
//n is primitive
//offset is primitive
//mask is primitive
p57->pdata = (uint32_t *) get_writable_address(sizeof(uint32_t));
return p57;
}
return get_non_null_address();


case STRUCT_msm_jpeg_hw_cmds:
if(local_addr != NULL)
p58 = (struct msm_jpeg_hw_cmds *)local_addr;
else
p58 = (struct msm_jpeg_hw_cmds *)get_writable_address(sizeof(struct msm_jpeg_hw_cmds));
if(p58) {
//m is primitive
recursive_fuzz(STRUCT_msm_jpeg_hw_cmd, &p58->hw_cmd);
return p58;
}
return get_non_null_address();


case STRUCT_timespec:
if(local_addr != NULL)
p59 = (struct timespec *)local_addr;
else
p59 = (struct timespec *)get_writable_address(sizeof(struct timespec));
if(p59) {
return p59;
}
return get_non_null_address();


case STRUCT_v4l2_capability:
if(local_addr != NULL)
p60 = (struct v4l2_capability *)local_addr;
else
p60 = (struct v4l2_capability *)get_writable_address(sizeof(struct v4l2_capability));
if(p60) {
//driver is an array of __u8 of 16 elements
//card is an array of __u8 of 32 elements
//bus_info is an array of __u8 of 32 elements
//version is primitive
//capabilities is primitive
//device_caps is primitive
//reserved is an array of __u32 of 3 elements
return p60;
}
return get_non_null_address();


case STRUCT_v4l2_fmtdesc:
if(local_addr != NULL)
p61 = (struct v4l2_fmtdesc *)local_addr;
else
p61 = (struct v4l2_fmtdesc *)get_writable_address(sizeof(struct v4l2_fmtdesc));
if(p61) {
//index is primitive
//enum v4l2_buf_type;
//flags is primitive
//description is an array of __u8 of 32 elements
//pixelformat is primitive
//reserved is an array of __u32 of 4 elements
return p61;
}
return get_non_null_address();


case STRUCT_v4l2_rect:
if(local_addr != NULL)
p62 = (struct v4l2_rect *)local_addr;
else
p62 = (struct v4l2_rect *)get_writable_address(sizeof(struct v4l2_rect));
if(p62) {
//left is primitive
//top is primitive
//width is primitive
//height is primitive
return p62;
}
return get_non_null_address();


case STRUCT_v4l2_clip:
if(local_addr != NULL)
p63 = (struct v4l2_clip *)local_addr;
else
p63 = (struct v4l2_clip *)get_writable_address(sizeof(struct v4l2_clip));
if(p63) {
recursive_fuzz(STRUCT_v4l2_rect, &p63->c);
p63->next = (void *) get_non_null_address();
return p63;
}
return get_non_null_address();


case STRUCT_v4l2_window:
if(local_addr != NULL)
p64 = (struct v4l2_window *)local_addr;
else
p64 = (struct v4l2_window *)get_writable_address(sizeof(struct v4l2_window));
if(p64) {
recursive_fuzz(STRUCT_v4l2_rect, &p64->w);
//enum v4l2_field;
//chromakey is primitive
p64->clips = (struct v4l2_clip *) recursive_fuzz(STRUCT_v4l2_clip, NULL);
//clipcount is primitive
p64->bitmap = (void *) get_non_null_address();
//global_alpha is primitive
return p64;
}
return get_non_null_address();


case STRUCT_v4l2_format:
if(local_addr != NULL)
p65 = (struct v4l2_format *)local_addr;
else
p65 = (struct v4l2_format *)get_writable_address(sizeof(struct v4l2_format));
if(p65) {
//enum v4l2_buf_type;
recursive_fuzz(STRUCT_v4l2_window, &p65->win);
return p65;
}
return get_non_null_address();


case STRUCT_v4l2_requestbuffers:
if(local_addr != NULL)
p66 = (struct v4l2_requestbuffers *)local_addr;
else
p66 = (struct v4l2_requestbuffers *)get_writable_address(sizeof(struct v4l2_requestbuffers));
if(p66) {
//count is primitive
//enum v4l2_buf_type;
//enum v4l2_memory;
//reserved is an array of __u32 of 2 elements
return p66;
}
return get_non_null_address();


case STRUCT_v4l2_timecode:
if(local_addr != NULL)
p67 = (struct v4l2_timecode *)local_addr;
else
p67 = (struct v4l2_timecode *)get_writable_address(sizeof(struct v4l2_timecode));
if(p67) {
//type is primitive
//flags is primitive
//frames is primitive
//seconds is primitive
//minutes is primitive
//hours is primitive
//userbits is an array of __u8 of 4 elements
return p67;
}
return get_non_null_address();


case STRUCT_v4l2_plane:
if(local_addr != NULL)
p68 = (struct v4l2_plane *)local_addr;
else
p68 = (struct v4l2_plane *)get_writable_address(sizeof(struct v4l2_plane));
if(p68) {
//bytesused is primitive
//length is primitive
p68->userptr = (void *) get_non_null_address();
//data_offset is primitive
//reserved is an array of __u32 of 11 elements
return p68;
}
return get_non_null_address();


case STRUCT_timeval:
if(local_addr != NULL)
p69 = (struct timeval *)local_addr;
else
p69 = (struct timeval *)get_writable_address(sizeof(struct timeval));
if(p69) {
return p69;
}
return get_non_null_address();


case STRUCT_v4l2_buffer:
if(local_addr != NULL)
p70 = (struct v4l2_buffer *)local_addr;
else
p70 = (struct v4l2_buffer *)get_writable_address(sizeof(struct v4l2_buffer));
if(p70) {
//index is primitive
//enum v4l2_buf_type;
//bytesused is primitive
//flags is primitive
//enum v4l2_field;
recursive_fuzz(STRUCT_timeval, &p70->timestamp);
recursive_fuzz(STRUCT_v4l2_timecode, &p70->timecode);
//sequence is primitive
//enum v4l2_memory;
p70->planes = (struct v4l2_plane *) recursive_fuzz(STRUCT_v4l2_plane, NULL);
//length is primitive
//input is primitive
//reserved is primitive
return p70;
}
return get_non_null_address();


case STRUCT_v4l2_plane_pix_format:
if(local_addr != NULL)
p71 = (struct v4l2_plane_pix_format *)local_addr;
else
p71 = (struct v4l2_plane_pix_format *)get_writable_address(sizeof(struct v4l2_plane_pix_format));
if(p71) {
//sizeimage is primitive
//bytesperline is primitive
//reserved is an array of __u16 of 7 elements
return p71;
}
return get_non_null_address();


case STRUCT_v4l2_pix_format_mplane:
if(local_addr != NULL)
p72 = (struct v4l2_pix_format_mplane *)local_addr;
else
p72 = (struct v4l2_pix_format_mplane *)get_writable_address(sizeof(struct v4l2_pix_format_mplane));
if(p72) {
//width is primitive
//height is primitive
//pixelformat is primitive
//enum v4l2_field;
//enum v4l2_colorspace;
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[0]);
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[1]);
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[2]);
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[3]);
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[4]);
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[5]);
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[6]);
recursive_fuzz(STRUCT_v4l2_plane_pix_format, &p72->plane_fmt[7]);
//plane_fmt is an array of v4l2_plane_pix_format of 8 elements
//num_planes is primitive
//reserved is an array of __u8 of 11 elements
return p72;
}
return get_non_null_address();


case STRUCT_v4l2_pix_format:
if(local_addr != NULL)
p73 = (struct v4l2_pix_format *)local_addr;
else
p73 = (struct v4l2_pix_format *)get_writable_address(sizeof(struct v4l2_pix_format));
if(p73) {
//width is primitive
//height is primitive
//pixelformat is primitive
//enum v4l2_field;
//bytesperline is primitive
//sizeimage is primitive
//enum v4l2_colorspace;
//priv is primitive
return p73;
}
return get_non_null_address();


case STRUCT_v4l2_framebuffer:
if(local_addr != NULL)
p74 = (struct v4l2_framebuffer *)local_addr;
else
p74 = (struct v4l2_framebuffer *)get_writable_address(sizeof(struct v4l2_framebuffer));
if(p74) {
//capability is primitive
//flags is primitive
p74->base = (void *) get_non_null_address();
recursive_fuzz(STRUCT_v4l2_pix_format, &p74->fmt);
return p74;
}
return get_non_null_address();


case STRUCT_v4l2_streamparm:
if(local_addr != NULL)
p75 = (struct v4l2_streamparm *)local_addr;
else
p75 = (struct v4l2_streamparm *)get_writable_address(sizeof(struct v4l2_streamparm));
if(p75) {
//enum v4l2_buf_type;
//raw_data is an array of __u8 of 200 elements
return p75;
}
return get_non_null_address();


case STRUCT_v4l2_fract:
if(local_addr != NULL)
p76 = (struct v4l2_fract *)local_addr;
else
p76 = (struct v4l2_fract *)get_writable_address(sizeof(struct v4l2_fract));
if(p76) {
//numerator is primitive
//denominator is primitive
return p76;
}
return get_non_null_address();


case STRUCT_v4l2_standard:
if(local_addr != NULL)
p77 = (struct v4l2_standard *)local_addr;
else
p77 = (struct v4l2_standard *)get_writable_address(sizeof(struct v4l2_standard));
if(p77) {
//index is primitive
//name is an array of __u8 of 24 elements
recursive_fuzz(STRUCT_v4l2_fract, &p77->frameperiod);
//framelines is primitive
//reserved is an array of __u32 of 4 elements
return p77;
}
return get_non_null_address();


case STRUCT_v4l2_input:
if(local_addr != NULL)
p78 = (struct v4l2_input *)local_addr;
else
p78 = (struct v4l2_input *)get_writable_address(sizeof(struct v4l2_input));
if(p78) {
//index is primitive
//name is an array of __u8 of 32 elements
//type is primitive
//audioset is primitive
//tuner is primitive
//status is primitive
//capabilities is primitive
//reserved is an array of __u32 of 3 elements
return p78;
}
return get_non_null_address();


case STRUCT_v4l2_control:
if(local_addr != NULL)
p79 = (struct v4l2_control *)local_addr;
else
p79 = (struct v4l2_control *)get_writable_address(sizeof(struct v4l2_control));
if(p79) {
//id is primitive
//value is primitive
return p79;
}
return get_non_null_address();


case STRUCT_v4l2_tuner:
if(local_addr != NULL)
p80 = (struct v4l2_tuner *)local_addr;
else
p80 = (struct v4l2_tuner *)get_writable_address(sizeof(struct v4l2_tuner));
if(p80) {
//index is primitive
//name is an array of __u8 of 32 elements
//enum v4l2_tuner_type;
//capability is primitive
//rangelow is primitive
//rangehigh is primitive
//rxsubchans is primitive
//audmode is primitive
//signal is primitive
//afc is primitive
//reserved is an array of __u32 of 4 elements
return p80;
}
return get_non_null_address();


case STRUCT_v4l2_modulator:
if(local_addr != NULL)
p81 = (struct v4l2_modulator *)local_addr;
else
p81 = (struct v4l2_modulator *)get_writable_address(sizeof(struct v4l2_modulator));
if(p81) {
//index is primitive
//name is an array of __u8 of 32 elements
//capability is primitive
//rangelow is primitive
//rangehigh is primitive
//txsubchans is primitive
//reserved is an array of __u32 of 4 elements
return p81;
}
return get_non_null_address();


case STRUCT_v4l2_audio:
if(local_addr != NULL)
p82 = (struct v4l2_audio *)local_addr;
else
p82 = (struct v4l2_audio *)get_writable_address(sizeof(struct v4l2_audio));
if(p82) {
//index is primitive
//name is an array of __u8 of 32 elements
//capability is primitive
//mode is primitive
//reserved is an array of __u32 of 2 elements
return p82;
}
return get_non_null_address();


case STRUCT_v4l2_queryctrl:
if(local_addr != NULL)
p83 = (struct v4l2_queryctrl *)local_addr;
else
p83 = (struct v4l2_queryctrl *)get_writable_address(sizeof(struct v4l2_queryctrl));
if(p83) {
//id is primitive
//enum v4l2_ctrl_type;
//name is an array of __u8 of 32 elements
//minimum is primitive
//maximum is primitive
//step is primitive
//default_value is primitive
//flags is primitive
//reserved is an array of __u32 of 2 elements
return p83;
}
return get_non_null_address();


case STRUCT_v4l2_querymenu:
if(local_addr != NULL)
p84 = (struct v4l2_querymenu *)local_addr;
else
p84 = (struct v4l2_querymenu *)get_writable_address(sizeof(struct v4l2_querymenu));
if(p84) {
//id is primitive
//index is primitive
//name is an array of __u8 of 32 elements
//reserved is primitive
return p84;
}
return get_non_null_address();


case STRUCT_v4l2_outputparm:
if(local_addr != NULL)
p85 = (struct v4l2_outputparm *)local_addr;
else
p85 = (struct v4l2_outputparm *)get_writable_address(sizeof(struct v4l2_outputparm));
if(p85) {
//capability is primitive
//outputmode is primitive
recursive_fuzz(STRUCT_v4l2_fract, &p85->timeperframe);
//extendedmode is primitive
//writebuffers is primitive
//reserved is an array of __u32 of 4 elements
return p85;
}
return get_non_null_address();


case STRUCT_v4l2_audioout:
if(local_addr != NULL)
p86 = (struct v4l2_audioout *)local_addr;
else
p86 = (struct v4l2_audioout *)get_writable_address(sizeof(struct v4l2_audioout));
if(p86) {
//index is primitive
//name is an array of __u8 of 32 elements
//capability is primitive
//mode is primitive
//reserved is an array of __u32 of 2 elements
return p86;
}
return get_non_null_address();


case STRUCT_v4l2_frequency:
if(local_addr != NULL)
p87 = (struct v4l2_frequency *)local_addr;
else
p87 = (struct v4l2_frequency *)get_writable_address(sizeof(struct v4l2_frequency));
if(p87) {
//tuner is primitive
//enum v4l2_tuner_type;
//frequency is primitive
//reserved is an array of __u32 of 8 elements
return p87;
}
return get_non_null_address();


case STRUCT_v4l2_cropcap:
if(local_addr != NULL)
p88 = (struct v4l2_cropcap *)local_addr;
else
p88 = (struct v4l2_cropcap *)get_writable_address(sizeof(struct v4l2_cropcap));
if(p88) {
//enum v4l2_buf_type;
recursive_fuzz(STRUCT_v4l2_rect, &p88->bounds);
recursive_fuzz(STRUCT_v4l2_rect, &p88->defrect);
recursive_fuzz(STRUCT_v4l2_fract, &p88->pixelaspect);
return p88;
}
return get_non_null_address();


case STRUCT_v4l2_crop:
if(local_addr != NULL)
p89 = (struct v4l2_crop *)local_addr;
else
p89 = (struct v4l2_crop *)get_writable_address(sizeof(struct v4l2_crop));
if(p89) {
//enum v4l2_buf_type;
recursive_fuzz(STRUCT_v4l2_rect, &p89->c);
return p89;
}
return get_non_null_address();


case STRUCT_v4l2_jpegcompression:
if(local_addr != NULL)
p90 = (struct v4l2_jpegcompression *)local_addr;
else
p90 = (struct v4l2_jpegcompression *)get_writable_address(sizeof(struct v4l2_jpegcompression));
if(p90) {
//quality is primitive
//APPn is primitive
//APP_len is primitive
//APP_data is an array of char of 60 elements
//COM_len is primitive
//COM_data is an array of char of 60 elements
//jpeg_markers is primitive
//marker is primitive
return p90;
}
return get_non_null_address();


case STRUCT_v4l2_sliced_vbi_cap:
if(local_addr != NULL)
p91 = (struct v4l2_sliced_vbi_cap *)local_addr;
else
p91 = (struct v4l2_sliced_vbi_cap *)get_writable_address(sizeof(struct v4l2_sliced_vbi_cap));
if(p91) {
//service_set is primitive
//service_lines is an array of __u16 of 2 elements
//enum v4l2_buf_type;
//reserved is an array of __u32 of 3 elements
return p91;
}
return get_non_null_address();


case STRUCT_v4l2_ext_controls:
if(local_addr != NULL)
p92 = (struct v4l2_ext_controls *)local_addr;
else
p92 = (struct v4l2_ext_controls *)get_writable_address(sizeof(struct v4l2_ext_controls));
if(p92) {
//ctrl_class is primitive
//count is primitive
//error_idx is primitive
//reserved is an array of __u32 of 2 elements
p92->controls = (void *) get_non_null_address();
return p92;
}
return get_non_null_address();


case STRUCT_v4l2_frmsize_stepwise:
if(local_addr != NULL)
p93 = (struct v4l2_frmsize_stepwise *)local_addr;
else
p93 = (struct v4l2_frmsize_stepwise *)get_writable_address(sizeof(struct v4l2_frmsize_stepwise));
if(p93) {
//min_width is primitive
//max_width is primitive
//step_width is primitive
//min_height is primitive
//max_height is primitive
//step_height is primitive
return p93;
}
return get_non_null_address();


case STRUCT_v4l2_frmsizeenum:
if(local_addr != NULL)
p94 = (struct v4l2_frmsizeenum *)local_addr;
else
p94 = (struct v4l2_frmsizeenum *)get_writable_address(sizeof(struct v4l2_frmsizeenum));
if(p94) {
//index is primitive
//pixel_format is primitive
//type is primitive
recursive_fuzz(STRUCT_v4l2_frmsize_stepwise, &p94->stepwise);
//reserved is an array of __u32 of 2 elements
return p94;
}
return get_non_null_address();


case STRUCT_v4l2_frmival_stepwise:
if(local_addr != NULL)
p95 = (struct v4l2_frmival_stepwise *)local_addr;
else
p95 = (struct v4l2_frmival_stepwise *)get_writable_address(sizeof(struct v4l2_frmival_stepwise));
if(p95) {
recursive_fuzz(STRUCT_v4l2_fract, &p95->min);
recursive_fuzz(STRUCT_v4l2_fract, &p95->max);
recursive_fuzz(STRUCT_v4l2_fract, &p95->step);
return p95;
}
return get_non_null_address();


case STRUCT_v4l2_frmivalenum:
if(local_addr != NULL)
p96 = (struct v4l2_frmivalenum *)local_addr;
else
p96 = (struct v4l2_frmivalenum *)get_writable_address(sizeof(struct v4l2_frmivalenum));
if(p96) {
//index is primitive
//pixel_format is primitive
//width is primitive
//height is primitive
//type is primitive
recursive_fuzz(STRUCT_v4l2_frmival_stepwise, &p96->stepwise);
//reserved is an array of __u32 of 2 elements
return p96;
}
return get_non_null_address();


case STRUCT_v4l2_enc_idx_entry:
if(local_addr != NULL)
p97 = (struct v4l2_enc_idx_entry *)local_addr;
else
p97 = (struct v4l2_enc_idx_entry *)get_writable_address(sizeof(struct v4l2_enc_idx_entry));
if(p97) {
//length is primitive
//flags is primitive
//reserved is an array of __u32 of 2 elements
return p97;
}
return get_non_null_address();


case STRUCT_v4l2_enc_idx:
if(local_addr != NULL)
p98 = (struct v4l2_enc_idx *)local_addr;
else
p98 = (struct v4l2_enc_idx *)get_writable_address(sizeof(struct v4l2_enc_idx));
if(p98) {
//entries is primitive
//entries_cap is primitive
//reserved is an array of __u32 of 4 elements
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[0]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[1]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[2]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[3]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[4]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[5]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[6]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[7]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[8]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[9]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[10]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[11]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[12]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[13]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[14]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[15]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[16]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[17]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[18]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[19]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[20]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[21]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[22]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[23]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[24]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[25]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[26]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[27]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[28]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[29]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[30]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[31]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[32]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[33]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[34]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[35]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[36]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[37]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[38]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[39]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[40]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[41]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[42]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[43]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[44]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[45]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[46]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[47]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[48]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[49]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[50]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[51]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[52]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[53]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[54]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[55]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[56]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[57]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[58]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[59]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[60]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[61]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[62]);
recursive_fuzz(STRUCT_v4l2_enc_idx_entry, &p98->entry[63]);
//entry is an array of v4l2_enc_idx_entry of 64 elements
return p98;
}
return get_non_null_address();


case STRUCT_v4l2_encoder_cmd:
if(local_addr != NULL)
p99 = (struct v4l2_encoder_cmd *)local_addr;
else
p99 = (struct v4l2_encoder_cmd *)get_writable_address(sizeof(struct v4l2_encoder_cmd));
if(p99) {
//cmd is primitive
//flags is primitive
//data is an array of __u32 of 8 elements
return p99;
}
return get_non_null_address();


case STRUCT_v4l2_dbg_match:
if(local_addr != NULL)
p100 = (struct v4l2_dbg_match *)local_addr;
else
p100 = (struct v4l2_dbg_match *)get_writable_address(sizeof(struct v4l2_dbg_match));
if(p100) {
//type is primitive
//addr is primitive
//name is an array of char of 32 elements
return p100;
}
return get_non_null_address();


case STRUCT_v4l2_dbg_register:
if(local_addr != NULL)
p101 = (struct v4l2_dbg_register *)local_addr;
else
p101 = (struct v4l2_dbg_register *)get_writable_address(sizeof(struct v4l2_dbg_register));
if(p101) {
recursive_fuzz(STRUCT_v4l2_dbg_match, &p101->match);
//size is primitive
return p101;
}
return get_non_null_address();


case STRUCT_v4l2_dbg_chip_ident:
if(local_addr != NULL)
p102 = (struct v4l2_dbg_chip_ident *)local_addr;
else
p102 = (struct v4l2_dbg_chip_ident *)get_writable_address(sizeof(struct v4l2_dbg_chip_ident));
if(p102) {
recursive_fuzz(STRUCT_v4l2_dbg_match, &p102->match);
//ident is primitive
//revision is primitive
return p102;
}
return get_non_null_address();


case STRUCT_v4l2_hw_freq_seek:
if(local_addr != NULL)
p103 = (struct v4l2_hw_freq_seek *)local_addr;
else
p103 = (struct v4l2_hw_freq_seek *)get_writable_address(sizeof(struct v4l2_hw_freq_seek));
if(p103) {
//tuner is primitive
//enum v4l2_tuner_type;
//seek_upward is primitive
//wrap_around is primitive
//spacing is primitive
//reserved is an array of __u32 of 7 elements
return p103;
}
return get_non_null_address();


case STRUCT_v4l2_dv_enum_preset:
if(local_addr != NULL)
p104 = (struct v4l2_dv_enum_preset *)local_addr;
else
p104 = (struct v4l2_dv_enum_preset *)get_writable_address(sizeof(struct v4l2_dv_enum_preset));
if(p104) {
//index is primitive
//preset is primitive
//name is an array of __u8 of 32 elements
//width is primitive
//height is primitive
//reserved is an array of __u32 of 4 elements
return p104;
}
return get_non_null_address();


case STRUCT_v4l2_dv_preset:
if(local_addr != NULL)
p105 = (struct v4l2_dv_preset *)local_addr;
else
p105 = (struct v4l2_dv_preset *)get_writable_address(sizeof(struct v4l2_dv_preset));
if(p105) {
//preset is primitive
//reserved is an array of __u32 of 4 elements
return p105;
}
return get_non_null_address();


case STRUCT_v4l2_dv_timings:
if(local_addr != NULL)
p106 = (struct v4l2_dv_timings *)local_addr;
else
p106 = (struct v4l2_dv_timings *)get_writable_address(sizeof(struct v4l2_dv_timings));
if(p106) {
//type is primitive
//reserved is an array of __u32 of 32 elements
return p106;
}
return get_non_null_address();


case STRUCT_v4l2_event:
if(local_addr != NULL)
p107 = (struct v4l2_event *)local_addr;
else
p107 = (struct v4l2_event *)get_writable_address(sizeof(struct v4l2_event));
if(p107) {
//type is primitive
//data is an array of __u8 of 64 elements
//pending is primitive
//sequence is primitive
recursive_fuzz(STRUCT_timespec, &p107->timestamp);
//id is primitive
//reserved is an array of __u32 of 8 elements
return p107;
}
return get_non_null_address();


case STRUCT_v4l2_event_subscription:
if(local_addr != NULL)
p108 = (struct v4l2_event_subscription *)local_addr;
else
p108 = (struct v4l2_event_subscription *)get_writable_address(sizeof(struct v4l2_event_subscription));
if(p108) {
//type is primitive
//id is primitive
//flags is primitive
//reserved is an array of __u32 of 5 elements
return p108;
}
return get_non_null_address();


case STRUCT_v4l2_create_buffers:
if(local_addr != NULL)
p109 = (struct v4l2_create_buffers *)local_addr;
else
p109 = (struct v4l2_create_buffers *)get_writable_address(sizeof(struct v4l2_create_buffers));
if(p109) {
//index is primitive
//count is primitive
//enum v4l2_memory;
recursive_fuzz(STRUCT_v4l2_format, &p109->format);
//reserved is an array of __u32 of 8 elements
return p109;
}
return get_non_null_address();


case STRUCT_v4l2_selection:
if(local_addr != NULL)
p110 = (struct v4l2_selection *)local_addr;
else
p110 = (struct v4l2_selection *)get_writable_address(sizeof(struct v4l2_selection));
if(p110) {
//type is primitive
//target is primitive
//flags is primitive
recursive_fuzz(STRUCT_v4l2_rect, &p110->r);
//reserved is an array of __u32 of 9 elements
return p110;
}
return get_non_null_address();


case STRUCT_v4l2_decoder_cmd:
if(local_addr != NULL)
p111 = (struct v4l2_decoder_cmd *)local_addr;
else
p111 = (struct v4l2_decoder_cmd *)get_writable_address(sizeof(struct v4l2_decoder_cmd));
if(p111) {
//cmd is primitive
//flags is primitive
//speed is primitive
//format is primitive
return p111;
}
return get_non_null_address();


case STRUCT_v4l2_output:
if(local_addr != NULL)
p112 = (struct v4l2_output *)local_addr;
else
p112 = (struct v4l2_output *)get_writable_address(sizeof(struct v4l2_output));
if(p112) {
//index is primitive
//name is an array of __u8 of 32 elements
//type is primitive
//audioset is primitive
//modulator is primitive
//std is primitive
//capabilities is primitive
//reserved is an array of __u32 of 3 elements
return p112;
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