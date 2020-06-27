#include "vlib.h"
typedef void (*func_ptr)(unordered_map<string, Wire*>&);
unordered_map<string, func_ptr> vlib = {
    { "GEN_AND2_D1" , &GEN_AND2_D1::step },
    { "GEN_AND2_D2" , &GEN_AND2_D2::step },
    { "GEN_AND2_D4" , &GEN_AND2_D4::step },
    { "GEN_AND2_D8" , &GEN_AND2_D8::step },
    { "GEN_AND3_D1" , &GEN_AND3_D1::step },
    { "GEN_AND3_D2" , &GEN_AND3_D2::step },
    { "GEN_AND3_D4" , &GEN_AND3_D4::step },
    { "GEN_AND3_D8" , &GEN_AND3_D8::step },
    { "GEN_AND4_D1" , &GEN_AND4_D1::step },
    { "GEN_AND4_D2" , &GEN_AND4_D2::step },
    { "GEN_AND4_D4" , &GEN_AND4_D4::step },
    { "GEN_AND4_D8" , &GEN_AND4_D8::step },
    { "GEN_AO211_D1" , &GEN_AO211_D1::step },
    { "GEN_AO211_D2" , &GEN_AO211_D2::step },
    { "GEN_AO211_D4" , &GEN_AO211_D4::step },
    { "GEN_AO21_D1" , &GEN_AO21_D1::step },
    { "GEN_AO21_D2" , &GEN_AO21_D2::step },
    { "GEN_AO21_D4" , &GEN_AO21_D4::step },
    { "GEN_AO221_D1" , &GEN_AO221_D1::step },
    { "GEN_AO221_D2" , &GEN_AO221_D2::step },
    { "GEN_AO221_D4" , &GEN_AO221_D4::step },
    { "GEN_AO222_D1" , &GEN_AO222_D1::step },
    { "GEN_AO222_D2" , &GEN_AO222_D2::step },
    { "GEN_AO222_D4" , &GEN_AO222_D4::step },
    { "GEN_AO22_D1" , &GEN_AO22_D1::step },
    { "GEN_AO22_D2" , &GEN_AO22_D2::step },
    { "GEN_AO22_D4" , &GEN_AO22_D4::step },
    { "GEN_AO22_D8" , &GEN_AO22_D8::step },
    { "GEN_AO31_D1" , &GEN_AO31_D1::step },
    { "GEN_AO31_D2" , &GEN_AO31_D2::step },
    { "GEN_AO31_D4" , &GEN_AO31_D4::step },
    { "GEN_AO32_D1" , &GEN_AO32_D1::step },
    { "GEN_AO32_D2" , &GEN_AO32_D2::step },
    { "GEN_AO32_D4" , &GEN_AO32_D4::step },
    { "GEN_AO33_D1" , &GEN_AO33_D1::step },
    { "GEN_AO33_D2" , &GEN_AO33_D2::step },
    { "GEN_AO33_D4" , &GEN_AO33_D4::step },
    { "GEN_AOI211_D1" , &GEN_AOI211_D1::step },
    { "GEN_AOI211_D2" , &GEN_AOI211_D2::step },
    { "GEN_AOI211_D4" , &GEN_AOI211_D4::step },
    { "GEN_AOI21_D1" , &GEN_AOI21_D1::step },
    { "GEN_AOI21_D2" , &GEN_AOI21_D2::step },
    { "GEN_AOI21_D4" , &GEN_AOI21_D4::step },
    { "GEN_AOI221_D1" , &GEN_AOI221_D1::step },
    { "GEN_AOI221_D2" , &GEN_AOI221_D2::step },
    { "GEN_AOI221_D4" , &GEN_AOI221_D4::step },
    { "GEN_AOI222_D1" , &GEN_AOI222_D1::step },
    { "GEN_AOI222_D2" , &GEN_AOI222_D2::step },
    { "GEN_AOI222_D4" , &GEN_AOI222_D4::step },
    { "GEN_AOI22_D1" , &GEN_AOI22_D1::step },
    { "GEN_AOI22_D2" , &GEN_AOI22_D2::step },
    { "GEN_AOI22_D4" , &GEN_AOI22_D4::step },
    { "GEN_AOI31_D1" , &GEN_AOI31_D1::step },
    { "GEN_AOI31_D2" , &GEN_AOI31_D2::step },
    { "GEN_AOI31_D4" , &GEN_AOI31_D4::step },
    { "GEN_AOI32_D1" , &GEN_AOI32_D1::step },
    { "GEN_AOI32_D2" , &GEN_AOI32_D2::step },
    { "GEN_AOI32_D4" , &GEN_AOI32_D4::step },
    { "GEN_AOI33_D1" , &GEN_AOI33_D1::step },
    { "GEN_AOI33_D2" , &GEN_AOI33_D2::step },
    { "GEN_AOI33_D4" , &GEN_AOI33_D4::step },
    { "GEN_BUF_D1" , &GEN_BUF_D1::step },
    { "GEN_BUF_D2" , &GEN_BUF_D2::step },
    { "GEN_BUF_D4" , &GEN_BUF_D4::step },
    { "GEN_BUF_D8" , &GEN_BUF_D8::step },
    { "GEN_FA_D1" , &GEN_FA_D1::step },
    { "GEN_FA_D2" , &GEN_FA_D2::step },
    { "GEN_FA_D4" , &GEN_FA_D4::step },
    { "GEN_HA_D1" , &GEN_HA_D1::step },
    { "GEN_HA_D2" , &GEN_HA_D2::step },
    { "GEN_HA_D4" , &GEN_HA_D4::step },
    { "GEN_INV_D1" , &GEN_INV_D1::step },
    { "GEN_INV_D2" , &GEN_INV_D2::step },
    { "GEN_INV_D4" , &GEN_INV_D4::step },
    { "GEN_INV_D8" , &GEN_INV_D8::step },
    { "GEN_MAJORITYAOI222_D1" , &GEN_MAJORITYAOI222_D1::step },
    { "GEN_MAJORITYAOI222_D2" , &GEN_MAJORITYAOI222_D2::step },
    { "GEN_MAJORITYAOI222_D4" , &GEN_MAJORITYAOI222_D4::step },
    { "GEN_MAJORITYAOI22_D1" , &GEN_MAJORITYAOI22_D1::step },
    { "GEN_MAJORITYAOI22_D2" , &GEN_MAJORITYAOI22_D2::step },
    { "GEN_MAJORITYAOI22_D4" , &GEN_MAJORITYAOI22_D4::step },
    { "GEN_MAJORITYOAI22_D1" , &GEN_MAJORITYOAI22_D1::step },
    { "GEN_MAJORITYOAI22_D2" , &GEN_MAJORITYOAI22_D2::step },
    { "GEN_MAJORITYOAI22_D4" , &GEN_MAJORITYOAI22_D4::step },
    { "GEN_LATCH_D1" , &GEN_LATCH_D1::step },
    { "GEN_LATCH_D2" , &GEN_LATCH_D2::step },
    { "GEN_LATCH_D4" , &GEN_LATCH_D4::step },
    { "GEN_DFCLR_D1" , &GEN_DFCLR_D1::step },
    { "GEN_DFCLR_D2" , &GEN_DFCLR_D2::step },
    { "GEN_DFCLR_D4" , &GEN_DFCLR_D4::step },
    { "GEN_DFCLR_D8" , &GEN_DFCLR_D8::step },
    { "GEN_DF_D1" , &GEN_DF_D1::step },
    { "GEN_DF_D2" , &GEN_DF_D2::step },
    { "GEN_DF_D4" , &GEN_DF_D4::step },
    { "GEN_DF_D8" , &GEN_DF_D8::step },
    { "GEN_DFSET_D1" , &GEN_DFSET_D1::step },
    { "GEN_DFSET_D2" , &GEN_DFSET_D2::step },
    { "GEN_DFSET_D4" , &GEN_DFSET_D4::step },
    { "GEN_DFSET_D8" , &GEN_DFSET_D8::step },
    { "GEN_MUX2_D1" , &GEN_MUX2_D1::step },
    { "GEN_MUX2_D2" , &GEN_MUX2_D2::step },
    { "GEN_MUX2_D4" , &GEN_MUX2_D4::step },
    { "GEN_MUX2N_D1" , &GEN_MUX2N_D1::step },
    { "GEN_MUX2N_D2" , &GEN_MUX2N_D2::step },
    { "GEN_MUX2N_D4" , &GEN_MUX2N_D4::step },
    { "GEN_MUX3_D1" , &GEN_MUX3_D1::step },
    { "GEN_MUX3_D2" , &GEN_MUX3_D2::step },
    { "GEN_MUX3_D4" , &GEN_MUX3_D4::step },
    { "GEN_MUX3N_D1" , &GEN_MUX3N_D1::step },
    { "GEN_MUX3N_D2" , &GEN_MUX3N_D2::step },
    { "GEN_MUX3N_D4" , &GEN_MUX3N_D4::step },
    { "GEN_MUX4_D1" , &GEN_MUX4_D1::step },
    { "GEN_MUX4_D2" , &GEN_MUX4_D2::step },
    { "GEN_MUX4_D4" , &GEN_MUX4_D4::step },
    { "GEN_MUX4N_D1" , &GEN_MUX4N_D1::step },
    { "GEN_MUX4N_D2" , &GEN_MUX4N_D2::step },
    { "GEN_MUX4N_D4" , &GEN_MUX4N_D4::step },
    { "GEN_NAND2_D1" , &GEN_NAND2_D1::step },
    { "GEN_NAND2_D2" , &GEN_NAND2_D2::step },
    { "GEN_NAND2_D4" , &GEN_NAND2_D4::step },
    { "GEN_NAND2_D8" , &GEN_NAND2_D8::step },
    { "GEN_NAND3_D1" , &GEN_NAND3_D1::step },
    { "GEN_NAND3_D2" , &GEN_NAND3_D2::step },
    { "GEN_NAND3_D4" , &GEN_NAND3_D4::step },
    { "GEN_NAND3_D8" , &GEN_NAND3_D8::step },
    { "GEN_NAND4_D1" , &GEN_NAND4_D1::step },
    { "GEN_NAND4_D2" , &GEN_NAND4_D2::step },
    { "GEN_NAND4_D4" , &GEN_NAND4_D4::step },
    { "GEN_NAND4_D8" , &GEN_NAND4_D8::step },
    { "GEN_NOR2_D1" , &GEN_NOR2_D1::step },
    { "GEN_NOR2_D2" , &GEN_NOR2_D2::step },
    { "GEN_NOR2_D4" , &GEN_NOR2_D4::step },
    { "GEN_NOR2_D8" , &GEN_NOR2_D8::step },
    { "GEN_NOR3_D1" , &GEN_NOR3_D1::step },
    { "GEN_NOR3_D2" , &GEN_NOR3_D2::step },
    { "GEN_NOR3_D4" , &GEN_NOR3_D4::step },
    { "GEN_NOR3_D8" , &GEN_NOR3_D8::step },
    { "GEN_NOR4_D1" , &GEN_NOR4_D1::step },
    { "GEN_NOR4_D2" , &GEN_NOR4_D2::step },
    { "GEN_NOR4_D4" , &GEN_NOR4_D4::step },
    { "GEN_NOR4_D8" , &GEN_NOR4_D8::step },
    { "GEN_OA211_D1" , &GEN_OA211_D1::step },
    { "GEN_OA211_D2" , &GEN_OA211_D2::step },
    { "GEN_OA211_D4" , &GEN_OA211_D4::step },
    { "GEN_OA21_D1" , &GEN_OA21_D1::step },
    { "GEN_OA21_D2" , &GEN_OA21_D2::step },
    { "GEN_OA21_D4" , &GEN_OA21_D4::step },
    { "GEN_OA221_D1" , &GEN_OA221_D1::step },
    { "GEN_OA221_D2" , &GEN_OA221_D2::step },
    { "GEN_OA221_D4" , &GEN_OA221_D4::step },
    { "GEN_OA222_D1" , &GEN_OA222_D1::step },
    { "GEN_OA222_D2" , &GEN_OA222_D2::step },
    { "GEN_OA222_D4" , &GEN_OA222_D4::step },
    { "GEN_OA22_D1" , &GEN_OA22_D1::step },
    { "GEN_OA22_D2" , &GEN_OA22_D2::step },
    { "GEN_OA22_D4" , &GEN_OA22_D4::step },
    { "GEN_OA31_D1" , &GEN_OA31_D1::step },
    { "GEN_OA31_D2" , &GEN_OA31_D2::step },
    { "GEN_OA31_D4" , &GEN_OA31_D4::step },
    { "GEN_OA32_D1" , &GEN_OA32_D1::step },
    { "GEN_OA32_D2" , &GEN_OA32_D2::step },
    { "GEN_OA32_D4" , &GEN_OA32_D4::step },
    { "GEN_OA33_D1" , &GEN_OA33_D1::step },
    { "GEN_OA33_D2" , &GEN_OA33_D2::step },
    { "GEN_OA33_D4" , &GEN_OA33_D4::step },
    { "GEN_OAI211_D1" , &GEN_OAI211_D1::step },
    { "GEN_OAI211_D2" , &GEN_OAI211_D2::step },
    { "GEN_OAI211_D4" , &GEN_OAI211_D4::step },
    { "GEN_OAI21_D1" , &GEN_OAI21_D1::step },
    { "GEN_OAI21_D2" , &GEN_OAI21_D2::step },
    { "GEN_OAI21_D4" , &GEN_OAI21_D4::step },
    { "GEN_OAI221_D1" , &GEN_OAI221_D1::step },
    { "GEN_OAI221_D2" , &GEN_OAI221_D2::step },
    { "GEN_OAI221_D4" , &GEN_OAI221_D4::step },
    { "GEN_OAI222_D1" , &GEN_OAI222_D1::step },
    { "GEN_OAI222_D2" , &GEN_OAI222_D2::step },
    { "GEN_OAI222_D4" , &GEN_OAI222_D4::step },
    { "GEN_OAI22_D1" , &GEN_OAI22_D1::step },
    { "GEN_OAI22_D2" , &GEN_OAI22_D2::step },
    { "GEN_OAI22_D4" , &GEN_OAI22_D4::step },
    { "GEN_OAI31_D1" , &GEN_OAI31_D1::step },
    { "GEN_OAI31_D2" , &GEN_OAI31_D2::step },
    { "GEN_OAI31_D4" , &GEN_OAI31_D4::step },
    { "GEN_OAI32_D1" , &GEN_OAI32_D1::step },
    { "GEN_OAI32_D2" , &GEN_OAI32_D2::step },
    { "GEN_OAI32_D4" , &GEN_OAI32_D4::step },
    { "GEN_OAI33_D1" , &GEN_OAI33_D1::step },
    { "GEN_OAI33_D2" , &GEN_OAI33_D2::step },
    { "GEN_OAI33_D4" , &GEN_OAI33_D4::step },
    { "GEN_OR2_D1" , &GEN_OR2_D1::step },
    { "GEN_OR2_D2" , &GEN_OR2_D2::step },
    { "GEN_OR2_D4" , &GEN_OR2_D4::step },
    { "GEN_OR2_D8" , &GEN_OR2_D8::step },
    { "GEN_OR3_D1" , &GEN_OR3_D1::step },
    { "GEN_OR3_D2" , &GEN_OR3_D2::step },
    { "GEN_OR3_D4" , &GEN_OR3_D4::step },
    { "GEN_OR3_D8" , &GEN_OR3_D8::step },
    { "GEN_OR4_D1" , &GEN_OR4_D1::step },
    { "GEN_OR4_D2" , &GEN_OR4_D2::step },
    { "GEN_OR4_D4" , &GEN_OR4_D4::step },
    { "GEN_OR4_D8" , &GEN_OR4_D8::step },
    { "GEN_SCAN_DFCLR_D1" , &GEN_SCAN_DFCLR_D1::step },
    { "GEN_SCAN_DFCLR_D2" , &GEN_SCAN_DFCLR_D2::step },
    { "GEN_SCAN_DFCLR_D4" , &GEN_SCAN_DFCLR_D4::step },
    { "GEN_SCAN_DFCLR_D8" , &GEN_SCAN_DFCLR_D8::step },
    { "GEN_SCAN_DF_D1" , &GEN_SCAN_DF_D1::step },
    { "GEN_SCAN_DF_D2" , &GEN_SCAN_DF_D2::step },
    { "GEN_SCAN_DF_D4" , &GEN_SCAN_DF_D4::step },
    { "GEN_SCAN_DF_D8" , &GEN_SCAN_DF_D8::step },
    { "GEN_SCAN_DFSET_D1" , &GEN_SCAN_DFSET_D1::step },
    { "GEN_SCAN_DFSET_D2" , &GEN_SCAN_DFSET_D2::step },
    { "GEN_SCAN_DFSET_D4" , &GEN_SCAN_DFSET_D4::step },
    { "GEN_SCAN_DFSET_D8" , &GEN_SCAN_DFSET_D8::step },
    { "GEN_XNOR2_D1" , &GEN_XNOR2_D1::step },
    { "GEN_XNOR2_D2" , &GEN_XNOR2_D2::step },
    { "GEN_XNOR2_D4" , &GEN_XNOR2_D4::step },
    { "GEN_XNOR2_D8" , &GEN_XNOR2_D8::step },
    { "GEN_XNOR3_D1" , &GEN_XNOR3_D1::step },
    { "GEN_XNOR3_D2" , &GEN_XNOR3_D2::step },
    { "GEN_XNOR3_D4" , &GEN_XNOR3_D4::step },
    { "GEN_XOR2_D1" , &GEN_XOR2_D1::step },
    { "GEN_XOR2_D2" , &GEN_XOR2_D2::step },
    { "GEN_XOR2_D4" , &GEN_XOR2_D4::step },
    { "GEN_XOR2_D8" , &GEN_XOR2_D8::step },
    { "GEN_XOR3_D1" , &GEN_XOR3_D1::step },
    { "GEN_XOR3_D2" , &GEN_XOR3_D2::step },
    { "GEN_XOR3_D4" , &GEN_XOR3_D4::step },
    { "GEN_CLKGATE_D1" , &GEN_CLKGATE_D1::step },
    { "GEN_SYNC2C_D1" , &GEN_SYNC2C_D1::step },
    { "GEN_SYNC3_D1" , &GEN_SYNC3_D1::step },
    { "GEN_SYNC3S_D1" , &GEN_SYNC3S_D1::step },
    { "GEN_RAMS_16X272" , &GEN_RAMS_16X272::step },
    { "GEN_RAMS_16X256" , &GEN_RAMS_16X256::step },
    { "GEN_RAMS_OLAT_80x14" , &GEN_RAMS_OLAT_80x14::step },
    { "GEN_RAMS_OLAT_80x65" , &GEN_RAMS_OLAT_80x65::step },
    { "GEN_RAMS_OLAT_160x16" , &GEN_RAMS_OLAT_160x16::step },
    { "GEN_RAMS_OLAT_160x65" , &GEN_RAMS_OLAT_160x65::step },
    { "GEN_RAMS_OLAT_8x65" , &GEN_RAMS_OLAT_8x65::step },
    { "GEN_RAMS_OLAT_128x6" , &GEN_RAMS_OLAT_128x6::step },
    { "GEN_RAMS_256x64" , &GEN_RAMS_256x64::step },
    { "GEN_RAMS_16x64" , &GEN_RAMS_16x64::step },
    { "GEN_RAMS_OLAT_128x11" , &GEN_RAMS_OLAT_128x11::step },
    { "GEN_RAMS_OLAT_61x65" , &GEN_RAMS_OLAT_61x65::step },
    { "GEN_RAMS_WT_IPASS_OLAT_80x9" , &GEN_RAMS_WT_IPASS_OLAT_80x9::step },
    { "GEN_RAMS_WT_IPASS_OLAT_80x15" , &GEN_RAMS_WT_IPASS_OLAT_80x15::step },
    { "GEN_RAMS_WT_IPASS_OLAT_60x21" , &GEN_RAMS_WT_IPASS_OLAT_60x21::step },
    { "GEN_RAMS_WT_256x8" , &GEN_RAMS_WT_256x8::step },
    { "GEN_RAMS_256x7" , &GEN_RAMS_256x7::step },
    { "GEN_RAMS_256x3" , &GEN_RAMS_256x3::step },
    { "GEN_RAMS_WT_IPASS_OLAT_19x4" , &GEN_RAMS_WT_IPASS_OLAT_19x4::step },
    { "GEN_RAMS_128x18" , &GEN_RAMS_128x18::step },
    { "GEN_SYNC3C_D1" , &GEN_SYNC3C_D1::step },
    { "GEN_SYNC3C_STRICT_D1" , &GEN_SYNC3C_STRICT_D1::step },
    { "GEN_RAMS_512x256" , &GEN_RAMS_512x256::step },
    { "GEN_RAMS_64x116" , &GEN_RAMS_64x116::step },
    { "GEN_RAMS_64x1088" , &GEN_RAMS_64x1088::step },
    { "GEN_RAMS_64x1024" , &GEN_RAMS_64x1024::step },
    { "GEN_RAMS_OLAT_256x14" , &GEN_RAMS_OLAT_256x14::step },
    { "GEN_RAMS_OLAT_256x16" , &GEN_RAMS_OLAT_256x16::step },
    { "GEN_RAMS_OLAT_256x257" , &GEN_RAMS_OLAT_256x257::step },
    { "GEN_RAMS_OLAT_8x257" , &GEN_RAMS_OLAT_8x257::step },
    { "GEN_RAMS_WT_IPASS_OLAT_80x72" , &GEN_RAMS_WT_IPASS_OLAT_80x72::step },
    { "GEN_RAMS_WT_IPASS_OLAT_80x17" , &GEN_RAMS_WT_IPASS_OLAT_80x17::step },
    { "GEN_RAMS_WT_IPASS_OLAT_60x168" , &GEN_RAMS_WT_IPASS_OLAT_60x168::step },
    { "GEN_RAMS_WT_IPASS_OLAT_20x32" , &GEN_RAMS_WT_IPASS_OLAT_20x32::step },
    { "GEN_RAMS_SP_WENABLE21_64x21" , &GEN_RAMS_SP_WENABLE21_64x21::step },
    { "GEN_RAMS_SP_WENABLE32_1024x32" , &GEN_RAMS_SP_WENABLE32_1024x32::step },
    { "GEN_RAMS_SP_WENABLE8_4096x32" , &GEN_RAMS_SP_WENABLE8_4096x32::step },
    { "GEN_RAMS_SP_WENABLE22_64x88" , &GEN_RAMS_SP_WENABLE22_64x88::step },
    { "GEN_RAMS_SP_WENABLE8_512x256" , &GEN_RAMS_SP_WENABLE8_512x256::step },
    { "GEN_RAMS_SP_WENABLE21_64x84" , &GEN_RAMS_SP_WENABLE21_64x84::step },
    { "GEN_RAMS_SP_WENABLE32_512x128" , &GEN_RAMS_SP_WENABLE32_512x128::step }
};