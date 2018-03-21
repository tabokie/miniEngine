/* This file was generated automatically by the Snowball to ISO C compiler */
/* http://snowballstem.org/ */


#include "header.h"

#ifdef __cplusplus
extern "C" {
#endif
extern int stem(struct SN_env * z);
#ifdef __cplusplus
}
#endif
static int r_exception2(struct SN_env * z);
static int r_exception1(struct SN_env * z);
static int r_Step_5(struct SN_env * z);
static int r_Step_4(struct SN_env * z);
static int r_Step_3(struct SN_env * z);
static int r_Step_2(struct SN_env * z);
static int r_Step_1c(struct SN_env * z);
static int r_Step_1b(struct SN_env * z);
static int r_Step_1a(struct SN_env * z);
static int r_R2(struct SN_env * z);
static int r_R1(struct SN_env * z);
static int r_shortv(struct SN_env * z);
static int r_mark_regions(struct SN_env * z);
static int r_postlude(struct SN_env * z);
static int r_prelude(struct SN_env * z);
#ifdef __cplusplus
extern "C" {
#endif


extern struct SN_env * create_env(void);
extern void close_env(struct SN_env * z);


#ifdef __cplusplus
}
#endif
static const symbol s_0_0[5] = { 'a', 'r', 's', 'e', 'n' };
static const symbol s_0_1[6] = { 'c', 'o', 'm', 'm', 'u', 'n' };
static const symbol s_0_2[5] = { 'g', 'e', 'n', 'e', 'r' };

static const struct among a_0[3] =
{
/*  0 */ { 5, s_0_0, -1, -1, 0},
/*  1 */ { 6, s_0_1, -1, -1, 0},
/*  2 */ { 5, s_0_2, -1, -1, 0}
};

static const symbol s_1_0[1] = { '\'' };
static const symbol s_1_1[3] = { '\'', 's', '\'' };
static const symbol s_1_2[2] = { '\'', 's' };

static const struct among a_1[3] =
{
/*  0 */ { 1, s_1_0, -1, 1, 0},
/*  1 */ { 3, s_1_1, 0, 1, 0},
/*  2 */ { 2, s_1_2, -1, 1, 0}
};

static const symbol s_2_0[3] = { 'i', 'e', 'd' };
static const symbol s_2_1[1] = { 's' };
static const symbol s_2_2[3] = { 'i', 'e', 's' };
static const symbol s_2_3[4] = { 's', 's', 'e', 's' };
static const symbol s_2_4[2] = { 's', 's' };
static const symbol s_2_5[2] = { 'u', 's' };

static const struct among a_2[6] =
{
/*  0 */ { 3, s_2_0, -1, 2, 0},
/*  1 */ { 1, s_2_1, -1, 3, 0},
/*  2 */ { 3, s_2_2, 1, 2, 0},
/*  3 */ { 4, s_2_3, 1, 1, 0},
/*  4 */ { 2, s_2_4, 1, -1, 0},
/*  5 */ { 2, s_2_5, 1, -1, 0}
};

static const symbol s_3_1[2] = { 'b', 'b' };
static const symbol s_3_2[2] = { 'd', 'd' };
static const symbol s_3_3[2] = { 'f', 'f' };
static const symbol s_3_4[2] = { 'g', 'g' };
static const symbol s_3_5[2] = { 'b', 'l' };
static const symbol s_3_6[2] = { 'm', 'm' };
static const symbol s_3_7[2] = { 'n', 'n' };
static const symbol s_3_8[2] = { 'p', 'p' };
static const symbol s_3_9[2] = { 'r', 'r' };
static const symbol s_3_10[2] = { 'a', 't' };
static const symbol s_3_11[2] = { 't', 't' };
static const symbol s_3_12[2] = { 'i', 'z' };

static const struct among a_3[13] =
{
/*  0 */ { 0, 0, -1, 3, 0},
/*  1 */ { 2, s_3_1, 0, 2, 0},
/*  2 */ { 2, s_3_2, 0, 2, 0},
/*  3 */ { 2, s_3_3, 0, 2, 0},
/*  4 */ { 2, s_3_4, 0, 2, 0},
/*  5 */ { 2, s_3_5, 0, 1, 0},
/*  6 */ { 2, s_3_6, 0, 2, 0},
/*  7 */ { 2, s_3_7, 0, 2, 0},
/*  8 */ { 2, s_3_8, 0, 2, 0},
/*  9 */ { 2, s_3_9, 0, 2, 0},
/* 10 */ { 2, s_3_10, 0, 1, 0},
/* 11 */ { 2, s_3_11, 0, 2, 0},
/* 12 */ { 2, s_3_12, 0, 1, 0}
};

static const symbol s_4_0[2] = { 'e', 'd' };
static const symbol s_4_1[3] = { 'e', 'e', 'd' };
static const symbol s_4_2[3] = { 'i', 'n', 'g' };
static const symbol s_4_3[4] = { 'e', 'd', 'l', 'y' };
static const symbol s_4_4[5] = { 'e', 'e', 'd', 'l', 'y' };
static const symbol s_4_5[5] = { 'i', 'n', 'g', 'l', 'y' };

static const struct among a_4[6] =
{
/*  0 */ { 2, s_4_0, -1, 2, 0},
/*  1 */ { 3, s_4_1, 0, 1, 0},
/*  2 */ { 3, s_4_2, -1, 2, 0},
/*  3 */ { 4, s_4_3, -1, 2, 0},
/*  4 */ { 5, s_4_4, 3, 1, 0},
/*  5 */ { 5, s_4_5, -1, 2, 0}
};

static const symbol s_5_0[4] = { 'a', 'n', 'c', 'i' };
static const symbol s_5_1[4] = { 'e', 'n', 'c', 'i' };
static const symbol s_5_2[3] = { 'o', 'g', 'i' };
static const symbol s_5_3[2] = { 'l', 'i' };
static const symbol s_5_4[3] = { 'b', 'l', 'i' };
static const symbol s_5_5[4] = { 'a', 'b', 'l', 'i' };
static const symbol s_5_6[4] = { 'a', 'l', 'l', 'i' };
static const symbol s_5_7[5] = { 'f', 'u', 'l', 'l', 'i' };
static const symbol s_5_8[6] = { 'l', 'e', 's', 's', 'l', 'i' };
static const symbol s_5_9[5] = { 'o', 'u', 's', 'l', 'i' };
static const symbol s_5_10[5] = { 'e', 'n', 't', 'l', 'i' };
static const symbol s_5_11[5] = { 'a', 'l', 'i', 't', 'i' };
static const symbol s_5_12[6] = { 'b', 'i', 'l', 'i', 't', 'i' };
static const symbol s_5_13[5] = { 'i', 'v', 'i', 't', 'i' };
static const symbol s_5_14[6] = { 't', 'i', 'o', 'n', 'a', 'l' };
static const symbol s_5_15[7] = { 'a', 't', 'i', 'o', 'n', 'a', 'l' };
static const symbol s_5_16[5] = { 'a', 'l', 'i', 's', 'm' };
static const symbol s_5_17[5] = { 'a', 't', 'i', 'o', 'n' };
static const symbol s_5_18[7] = { 'i', 'z', 'a', 't', 'i', 'o', 'n' };
static const symbol s_5_19[4] = { 'i', 'z', 'e', 'r' };
static const symbol s_5_20[4] = { 'a', 't', 'o', 'r' };
static const symbol s_5_21[7] = { 'i', 'v', 'e', 'n', 'e', 's', 's' };
static const symbol s_5_22[7] = { 'f', 'u', 'l', 'n', 'e', 's', 's' };
static const symbol s_5_23[7] = { 'o', 'u', 's', 'n', 'e', 's', 's' };

static const struct among a_5[24] =
{
/*  0 */ { 4, s_5_0, -1, 3, 0},
/*  1 */ { 4, s_5_1, -1, 2, 0},
/*  2 */ { 3, s_5_2, -1, 13, 0},
/*  3 */ { 2, s_5_3, -1, 16, 0},
/*  4 */ { 3, s_5_4, 3, 12, 0},
/*  5 */ { 4, s_5_5, 4, 4, 0},
/*  6 */ { 4, s_5_6, 3, 8, 0},
/*  7 */ { 5, s_5_7, 3, 14, 0},
/*  8 */ { 6, s_5_8, 3, 15, 0},
/*  9 */ { 5, s_5_9, 3, 10, 0},
/* 10 */ { 5, s_5_10, 3, 5, 0},
/* 11 */ { 5, s_5_11, -1, 8, 0},
/* 12 */ { 6, s_5_12, -1, 12, 0},
/* 13 */ { 5, s_5_13, -1, 11, 0},
/* 14 */ { 6, s_5_14, -1, 1, 0},
/* 15 */ { 7, s_5_15, 14, 7, 0},
/* 16 */ { 5, s_5_16, -1, 8, 0},
/* 17 */ { 5, s_5_17, -1, 7, 0},
/* 18 */ { 7, s_5_18, 17, 6, 0},
/* 19 */ { 4, s_5_19, -1, 6, 0},
/* 20 */ { 4, s_5_20, -1, 7, 0},
/* 21 */ { 7, s_5_21, -1, 11, 0},
/* 22 */ { 7, s_5_22, -1, 9, 0},
/* 23 */ { 7, s_5_23, -1, 10, 0}
};

static const symbol s_6_0[5] = { 'i', 'c', 'a', 't', 'e' };
static const symbol s_6_1[5] = { 'a', 't', 'i', 'v', 'e' };
static const symbol s_6_2[5] = { 'a', 'l', 'i', 'z', 'e' };
static const symbol s_6_3[5] = { 'i', 'c', 'i', 't', 'i' };
static const symbol s_6_4[4] = { 'i', 'c', 'a', 'l' };
static const symbol s_6_5[6] = { 't', 'i', 'o', 'n', 'a', 'l' };
static const symbol s_6_6[7] = { 'a', 't', 'i', 'o', 'n', 'a', 'l' };
static const symbol s_6_7[3] = { 'f', 'u', 'l' };
static const symbol s_6_8[4] = { 'n', 'e', 's', 's' };

static const struct among a_6[9] =
{
/*  0 */ { 5, s_6_0, -1, 4, 0},
/*  1 */ { 5, s_6_1, -1, 6, 0},
/*  2 */ { 5, s_6_2, -1, 3, 0},
/*  3 */ { 5, s_6_3, -1, 4, 0},
/*  4 */ { 4, s_6_4, -1, 4, 0},
/*  5 */ { 6, s_6_5, -1, 1, 0},
/*  6 */ { 7, s_6_6, 5, 2, 0},
/*  7 */ { 3, s_6_7, -1, 5, 0},
/*  8 */ { 4, s_6_8, -1, 5, 0}
};

static const symbol s_7_0[2] = { 'i', 'c' };
static const symbol s_7_1[4] = { 'a', 'n', 'c', 'e' };
static const symbol s_7_2[4] = { 'e', 'n', 'c', 'e' };
static const symbol s_7_3[4] = { 'a', 'b', 'l', 'e' };
static const symbol s_7_4[4] = { 'i', 'b', 'l', 'e' };
static const symbol s_7_5[3] = { 'a', 't', 'e' };
static const symbol s_7_6[3] = { 'i', 'v', 'e' };
static const symbol s_7_7[3] = { 'i', 'z', 'e' };
static const symbol s_7_8[3] = { 'i', 't', 'i' };
static const symbol s_7_9[2] = { 'a', 'l' };
static const symbol s_7_10[3] = { 'i', 's', 'm' };
static const symbol s_7_11[3] = { 'i', 'o', 'n' };
static const symbol s_7_12[2] = { 'e', 'r' };
static const symbol s_7_13[3] = { 'o', 'u', 's' };
static const symbol s_7_14[3] = { 'a', 'n', 't' };
static const symbol s_7_15[3] = { 'e', 'n', 't' };
static const symbol s_7_16[4] = { 'm', 'e', 'n', 't' };
static const symbol s_7_17[5] = { 'e', 'm', 'e', 'n', 't' };

static const struct among a_7[18] =
{
/*  0 */ { 2, s_7_0, -1, 1, 0},
/*  1 */ { 4, s_7_1, -1, 1, 0},
/*  2 */ { 4, s_7_2, -1, 1, 0},
/*  3 */ { 4, s_7_3, -1, 1, 0},
/*  4 */ { 4, s_7_4, -1, 1, 0},
/*  5 */ { 3, s_7_5, -1, 1, 0},
/*  6 */ { 3, s_7_6, -1, 1, 0},
/*  7 */ { 3, s_7_7, -1, 1, 0},
/*  8 */ { 3, s_7_8, -1, 1, 0},
/*  9 */ { 2, s_7_9, -1, 1, 0},
/* 10 */ { 3, s_7_10, -1, 1, 0},
/* 11 */ { 3, s_7_11, -1, 2, 0},
/* 12 */ { 2, s_7_12, -1, 1, 0},
/* 13 */ { 3, s_7_13, -1, 1, 0},
/* 14 */ { 3, s_7_14, -1, 1, 0},
/* 15 */ { 3, s_7_15, -1, 1, 0},
/* 16 */ { 4, s_7_16, 15, 1, 0},
/* 17 */ { 5, s_7_17, 16, 1, 0}
};

static const symbol s_8_0[1] = { 'e' };
static const symbol s_8_1[1] = { 'l' };

static const struct among a_8[2] =
{
/*  0 */ { 1, s_8_0, -1, 1, 0},
/*  1 */ { 1, s_8_1, -1, 2, 0}
};

static const symbol s_9_0[7] = { 's', 'u', 'c', 'c', 'e', 'e', 'd' };
static const symbol s_9_1[7] = { 'p', 'r', 'o', 'c', 'e', 'e', 'd' };
static const symbol s_9_2[6] = { 'e', 'x', 'c', 'e', 'e', 'd' };
static const symbol s_9_3[7] = { 'c', 'a', 'n', 'n', 'i', 'n', 'g' };
static const symbol s_9_4[6] = { 'i', 'n', 'n', 'i', 'n', 'g' };
static const symbol s_9_5[7] = { 'e', 'a', 'r', 'r', 'i', 'n', 'g' };
static const symbol s_9_6[7] = { 'h', 'e', 'r', 'r', 'i', 'n', 'g' };
static const symbol s_9_7[6] = { 'o', 'u', 't', 'i', 'n', 'g' };

static const struct among a_9[8] =
{
/*  0 */ { 7, s_9_0, -1, -1, 0},
/*  1 */ { 7, s_9_1, -1, -1, 0},
/*  2 */ { 6, s_9_2, -1, -1, 0},
/*  3 */ { 7, s_9_3, -1, -1, 0},
/*  4 */ { 6, s_9_4, -1, -1, 0},
/*  5 */ { 7, s_9_5, -1, -1, 0},
/*  6 */ { 7, s_9_6, -1, -1, 0},
/*  7 */ { 6, s_9_7, -1, -1, 0}
};

static const symbol s_10_0[5] = { 'a', 'n', 'd', 'e', 's' };
static const symbol s_10_1[3] = { 'a', 'r', 'e' };
static const symbol s_10_2[3] = { 'a', 't', 'e' };
static const symbol s_10_3[5] = { 'a', 't', 'l', 'a', 's' };
static const symbol s_10_4[7] = { 'b', 'a', 'b', 'y', 's', 'a', 't' };
static const symbol s_10_5[6] = { 'b', 'e', 'a', 't', 'e', 'n' };
static const symbol s_10_6[6] = { 'b', 'e', 'c', 'a', 'm', 'e' };
static const symbol s_10_7[4] = { 'b', 'e', 'e', 'n' };
static const symbol s_10_8[5] = { 'b', 'e', 'g', 'a', 'n' };
static const symbol s_10_9[5] = { 'b', 'e', 'g', 'u', 'n' };
static const symbol s_10_10[4] = { 'b', 'i', 'a', 's' };
static const symbol s_10_11[6] = { 'b', 'i', 't', 't', 'e', 'n' };
static const symbol s_10_12[4] = { 'b', 'l', 'e', 'd' };
static const symbol s_10_13[4] = { 'b', 'l', 'e', 'w' };
static const symbol s_10_14[5] = { 'b', 'l', 'o', 'w', 'n' };
static const symbol s_10_15[6] = { 'b', 'o', 'u', 'g', 'h', 't' };
static const symbol s_10_16[5] = { 'b', 'r', 'o', 'k', 'e' };
static const symbol s_10_17[6] = { 'b', 'r', 'o', 'k', 'e', 'n' };
static const symbol s_10_18[7] = { 'b', 'r', 'o', 'u', 'g', 'h', 't' };
static const symbol s_10_19[5] = { 'b', 'u', 'i', 'l', 't' };
static const symbol s_10_20[4] = { 'c', 'a', 'm', 'e' };
static const symbol s_10_21[6] = { 'c', 'a', 'u', 'g', 'h', 't' };
static const symbol s_10_22[5] = { 'c', 'h', 'o', 's', 'e' };
static const symbol s_10_23[6] = { 'c', 'h', 'o', 's', 'e', 'n' };
static const symbol s_10_24[6] = { 'c', 'o', 's', 'm', 'o', 's' };
static const symbol s_10_25[5] = { 'd', 'e', 'a', 'l', 't' };
static const symbol s_10_26[3] = { 'd', 'i', 'd' };
static const symbol s_10_27[4] = { 'd', 'o', 'n', 'e' };
static const symbol s_10_28[4] = { 'd', 'o', 't', 'h' };
static const symbol s_10_29[5] = { 'd', 'r', 'a', 'n', 'k' };
static const symbol s_10_30[5] = { 'd', 'r', 'a', 'w', 'n' };
static const symbol s_10_31[4] = { 'd', 'r', 'e', 'w' };
static const symbol s_10_32[6] = { 'd', 'r', 'i', 'v', 'e', 'n' };
static const symbol s_10_33[5] = { 'd', 'r', 'o', 'v', 'e' };
static const symbol s_10_34[5] = { 'd', 'r', 'u', 'n', 'k' };
static const symbol s_10_35[7] = { 'd', 'r', 'u', 'n', 'k', 'e', 'n' };
static const symbol s_10_36[3] = { 'd', 'u', 'g' };
static const symbol s_10_37[5] = { 'd', 'y', 'i', 'n', 'g' };
static const symbol s_10_38[5] = { 'e', 'a', 'r', 'l', 'y' };
static const symbol s_10_39[5] = { 'e', 'a', 't', 'e', 'n' };
static const symbol s_10_40[6] = { 'f', 'a', 'l', 'l', 'e', 'n' };
static const symbol s_10_41[3] = { 'f', 'e', 'd' };
static const symbol s_10_42[4] = { 'f', 'e', 'l', 'l' };
static const symbol s_10_43[4] = { 'f', 'e', 'l', 't' };
static const symbol s_10_44[4] = { 'f', 'l', 'e', 'd' };
static const symbol s_10_45[4] = { 'f', 'l', 'e', 'w' };
static const symbol s_10_46[5] = { 'f', 'l', 'o', 'w', 'n' };
static const symbol s_10_47[6] = { 'f', 'o', 'r', 'g', 'o', 't' };
static const symbol s_10_48[9] = { 'f', 'o', 'r', 'g', 'o', 't', 't', 'e', 'n' };
static const symbol s_10_49[6] = { 'f', 'o', 'u', 'g', 'h', 't' };
static const symbol s_10_50[5] = { 'f', 'o', 'u', 'n', 'd' };
static const symbol s_10_51[5] = { 'f', 'r', 'o', 'z', 'e' };
static const symbol s_10_52[6] = { 'f', 'r', 'o', 'z', 'e', 'n' };
static const symbol s_10_53[4] = { 'g', 'a', 'v', 'e' };
static const symbol s_10_54[6] = { 'g', 'e', 'n', 't', 'l', 'y' };
static const symbol s_10_55[5] = { 'g', 'i', 'v', 'e', 'n' };
static const symbol s_10_56[4] = { 'g', 'o', 'n', 'e' };
static const symbol s_10_57[3] = { 'g', 'o', 't' };
static const symbol s_10_58[6] = { 'g', 'o', 't', 't', 'e', 'n' };
static const symbol s_10_59[4] = { 'g', 'r', 'e', 'w' };
static const symbol s_10_60[5] = { 'g', 'r', 'o', 'w', 'n' };
static const symbol s_10_61[3] = { 'h', 'a', 'd' };
static const symbol s_10_62[4] = { 'h', 'a', 't', 'h' };
static const symbol s_10_63[5] = { 'h', 'e', 'a', 'r', 'd' };
static const symbol s_10_64[4] = { 'h', 'e', 'l', 'd' };
static const symbol s_10_65[3] = { 'h', 'i', 'd' };
static const symbol s_10_66[4] = { 'h', 'o', 'l', 'p' };
static const symbol s_10_67[4] = { 'h', 'o', 'w', 'e' };
static const symbol s_10_68[4] = { 'h', 'u', 'n', 'g' };
static const symbol s_10_69[4] = { 'i', 'd', 'l', 'y' };
static const symbol s_10_70[2] = { 'i', 's' };
static const symbol s_10_71[4] = { 'k', 'e', 'p', 't' };
static const symbol s_10_72[4] = { 'k', 'e', 'w', 'n' };
static const symbol s_10_73[5] = { 'k', 'n', 'e', 'l', 't' };
static const symbol s_10_74[5] = { 'k', 'n', 'o', 'w', 'n' };
static const symbol s_10_75[4] = { 'l', 'a', 'i', 'd' };
static const symbol s_10_76[6] = { 'l', 'e', 'a', 'r', 'n', 't' };
static const symbol s_10_77[3] = { 'l', 'e', 'd' };
static const symbol s_10_78[4] = { 'l', 'e', 'f', 't' };
static const symbol s_10_79[4] = { 'l', 'e', 'n', 't' };
static const symbol s_10_80[3] = { 'l', 'i', 't' };
static const symbol s_10_81[5] = { 'l', 'y', 'i', 'n', 'g' };
static const symbol s_10_82[4] = { 'm', 'a', 'd', 'e' };
static const symbol s_10_83[5] = { 'm', 'e', 'a', 'n', 't' };
static const symbol s_10_84[3] = { 'm', 'e', 't' };
static const symbol s_10_85[8] = { 'm', 'i', 's', 't', 'a', 'k', 'e', 'n' };
static const symbol s_10_86[7] = { 'm', 'i', 's', 't', 'o', 'o', 'k' };
static const symbol s_10_87[4] = { 'n', 'e', 'w', 's' };
static const symbol s_10_88[4] = { 'o', 'n', 'l', 'y' };
static const symbol s_10_89[9] = { 'o', 'v', 'e', 'r', 's', 'l', 'e', 'p', 't' };
static const symbol s_10_90[4] = { 'p', 'a', 'i', 'd' };
static const symbol s_10_91[3] = { 'r', 'a', 'n' };
static const symbol s_10_92[4] = { 'r', 'a', 'n', 'g' };
static const symbol s_10_93[6] = { 'r', 'i', 'd', 'd', 'e', 'n' };
static const symbol s_10_94[5] = { 'r', 'i', 's', 'e', 'n' };
static const symbol s_10_95[4] = { 'r', 'o', 'd', 'e' };
static const symbol s_10_96[4] = { 'r', 'o', 's', 'e' };
static const symbol s_10_97[4] = { 'r', 'u', 'n', 'g' };
static const symbol s_10_98[4] = { 's', 'a', 'i', 'd' };
static const symbol s_10_99[5] = { 's', 'a', 'i', 't', 'h' };
static const symbol s_10_100[4] = { 's', 'a', 'n', 'g' };
static const symbol s_10_101[4] = { 's', 'a', 'n', 'k' };
static const symbol s_10_102[3] = { 's', 'a', 't' };
static const symbol s_10_103[3] = { 's', 'a', 'w' };
static const symbol s_10_104[4] = { 's', 'e', 'e', 'n' };
static const symbol s_10_105[4] = { 's', 'e', 'n', 't' };
static const symbol s_10_106[6] = { 's', 'h', 'a', 'k', 'e', 'n' };
static const symbol s_10_107[5] = { 's', 'h', 'o', 'n', 'e' };
static const symbol s_10_108[5] = { 's', 'h', 'o', 'o', 'k' };
static const symbol s_10_109[4] = { 's', 'h', 'o', 't' };
static const symbol s_10_110[6] = { 's', 'h', 'o', 'u', 'l', 'd' };
static const symbol s_10_111[5] = { 's', 'h', 'o', 'w', 'n' };
static const symbol s_10_112[6] = { 's', 'i', 'n', 'g', 'l', 'y' };
static const symbol s_10_113[5] = { 's', 'k', 'i', 'e', 's' };
static const symbol s_10_114[4] = { 's', 'k', 'i', 's' };
static const symbol s_10_115[3] = { 's', 'k', 'y' };
static const symbol s_10_116[5] = { 's', 'l', 'e', 'p', 't' };
static const symbol s_10_117[5] = { 's', 'm', 'e', 'l', 't' };
static const symbol s_10_118[4] = { 's', 'o', 'l', 'd' };
static const symbol s_10_119[6] = { 's', 'o', 'u', 'g', 'h', 't' };
static const symbol s_10_120[4] = { 's', 'p', 'a', 't' };
static const symbol s_10_121[5] = { 's', 'p', 'e', 'l', 't' };
static const symbol s_10_122[5] = { 's', 'p', 'e', 'n', 't' };
static const symbol s_10_123[5] = { 's', 'p', 'i', 'l', 't' };
static const symbol s_10_124[6] = { 's', 'p', 'o', 'i', 'l', 't' };
static const symbol s_10_125[5] = { 's', 'p', 'o', 'k', 'e' };
static const symbol s_10_126[6] = { 's', 'p', 'o', 'k', 'e', 'n' };
static const symbol s_10_127[5] = { 's', 't', 'o', 'l', 'e' };
static const symbol s_10_128[6] = { 's', 't', 'o', 'l', 'e', 'n' };
static const symbol s_10_129[5] = { 's', 't', 'o', 'o', 'd' };
static const symbol s_10_130[6] = { 's', 't', 'r', 'u', 'c', 'k' };
static const symbol s_10_131[4] = { 's', 'u', 'n', 'g' };
static const symbol s_10_132[4] = { 's', 'u', 'n', 'k' };
static const symbol s_10_133[6] = { 's', 'u', 'n', 'k', 'e', 'n' };
static const symbol s_10_134[4] = { 's', 'w', 'a', 'm' };
static const symbol s_10_135[5] = { 's', 'w', 'e', 'p', 't' };
static const symbol s_10_136[4] = { 's', 'w', 'u', 'm' };
static const symbol s_10_137[5] = { 't', 'a', 'k', 'e', 'n' };
static const symbol s_10_138[6] = { 't', 'a', 'u', 'g', 'h', 't' };
static const symbol s_10_139[4] = { 't', 'h', 'e', 'e' };
static const symbol s_10_140[5] = { 't', 'h', 'i', 'n', 'e' };
static const symbol s_10_141[4] = { 't', 'h', 'o', 'u' };
static const symbol s_10_142[7] = { 't', 'h', 'o', 'u', 'g', 'h', 't' };
static const symbol s_10_143[5] = { 't', 'h', 'r', 'e', 'w' };
static const symbol s_10_144[6] = { 't', 'h', 'r', 'o', 'w', 'n' };
static const symbol s_10_145[3] = { 't', 'h', 'y' };
static const symbol s_10_146[7] = { 't', 'h', 'y', 's', 'e', 'l', 'f' };
static const symbol s_10_147[4] = { 't', 'o', 'l', 'd' };
static const symbol s_10_148[4] = { 't', 'o', 'o', 'k' };
static const symbol s_10_149[4] = { 't', 'o', 'r', 'e' };
static const symbol s_10_150[4] = { 't', 'o', 'r', 'n' };
static const symbol s_10_151[5] = { 't', 'y', 'i', 'n', 'g' };
static const symbol s_10_152[4] = { 'u', 'g', 'l', 'y' };
static const symbol s_10_153[10] = { 'u', 'n', 'd', 'e', 'r', 's', 't', 'o', 'o', 'd' };
static const symbol s_10_154[5] = { 'w', 'a', 'k', 'e', 'n' };
static const symbol s_10_155[3] = { 'w', 'a', 's' };
static const symbol s_10_156[4] = { 'w', 'e', 'n', 't' };
static const symbol s_10_157[4] = { 'w', 'e', 'p', 't' };
static const symbol s_10_158[4] = { 'w', 'e', 'r', 'e' };
static const symbol s_10_159[4] = { 'w', 'o', 'k', 'e' };
static const symbol s_10_160[3] = { 'w', 'o', 'n' };
static const symbol s_10_161[4] = { 'w', 'o', 'r', 'e' };
static const symbol s_10_162[4] = { 'w', 'o', 'r', 'n' };
static const symbol s_10_163[5] = { 'w', 'o', 'u', 'l', 'd' };
static const symbol s_10_164[7] = { 'w', 'r', 'i', 't', 't', 'e', 'n' };
static const symbol s_10_165[5] = { 'w', 'r', 'o', 't', 'e' };
static const symbol s_10_166[2] = { 'y', 'e' };

static const struct among a_10[167] =
{
/*  0 */ { 5, s_10_0, -1, -1, 0},
/*  1 */ { 3, s_10_1, -1, 133, 0},
/*  2 */ { 3, s_10_2, -1, 87, 0},
/*  3 */ { 5, s_10_3, -1, -1, 0},
/*  4 */ { 7, s_10_4, -1, 58, 0},
/*  5 */ { 6, s_10_5, -1, 145, 0},
/*  6 */ { 6, s_10_6, -1, 147, 0},
/*  7 */ { 4, s_10_7, -1, 132, 0},
/*  8 */ { 5, s_10_8, -1, 116, 0},
/*  9 */ { 5, s_10_9, -1, 117, 0},
/* 10 */ { 4, s_10_10, -1, -1, 0},
/* 11 */ { 6, s_10_11, -1, 88, 0},
/* 12 */ { 4, s_10_12, -1, 26, 0},
/* 13 */ { 4, s_10_13, -1, 68, 0},
/* 14 */ { 5, s_10_14, -1, 67, 0},
/* 15 */ { 6, s_10_15, -1, 31, 0},
/* 16 */ { 5, s_10_16, -1, 104, 0},
/* 17 */ { 6, s_10_17, 16, 105, 0},
/* 18 */ { 7, s_10_18, -1, 30, 0},
/* 19 */ { 5, s_10_19, -1, 56, 0},
/* 20 */ { 4, s_10_20, -1, 146, 0},
/* 21 */ { 6, s_10_21, -1, 28, 0},
/* 22 */ { 5, s_10_22, -1, 112, 0},
/* 23 */ { 6, s_10_23, 22, 113, 0},
/* 24 */ { 6, s_10_24, -1, -1, 0},
/* 25 */ { 5, s_10_25, -1, 42, 0},
/* 26 */ { 3, s_10_26, -1, 141, 0},
/* 27 */ { 4, s_10_27, -1, 142, 0},
/* 28 */ { 4, s_10_28, -1, 156, 0},
/* 29 */ { 5, s_10_29, -1, 127, 0},
/* 30 */ { 5, s_10_30, -1, 65, 0},
/* 31 */ { 4, s_10_31, -1, 66, 0},
/* 32 */ { 6, s_10_32, -1, 91, 0},
/* 33 */ { 5, s_10_33, -1, 90, 0},
/* 34 */ { 5, s_10_34, -1, 128, 0},
/* 35 */ { 7, s_10_35, 34, 129, 0},
/* 36 */ { 3, s_10_36, -1, 63, 0},
/* 37 */ { 5, s_10_37, -1, 3, 0},
/* 38 */ { 5, s_10_38, -1, 9, 0},
/* 39 */ { 5, s_10_39, -1, 86, 0},
/* 40 */ { 6, s_10_40, -1, 115, 0},
/* 41 */ { 3, s_10_41, -1, 25, 0},
/* 42 */ { 4, s_10_42, -1, 114, 0},
/* 43 */ { 4, s_10_43, -1, 41, 0},
/* 44 */ { 4, s_10_44, -1, 23, 0},
/* 45 */ { 4, s_10_45, -1, 76, 0},
/* 46 */ { 5, s_10_46, -1, 75, 0},
/* 47 */ { 6, s_10_47, -1, 80, 0},
/* 48 */ { 9, s_10_48, 47, 81, 0},
/* 49 */ { 6, s_10_49, -1, 32, 0},
/* 50 */ { 5, s_10_50, -1, 20, 0},
/* 51 */ { 5, s_10_51, -1, 108, 0},
/* 52 */ { 6, s_10_52, 51, 109, 0},
/* 53 */ { 4, s_10_53, -1, 95, 0},
/* 54 */ { 6, s_10_54, -1, 7, 0},
/* 55 */ { 5, s_10_55, -1, 94, 0},
/* 56 */ { 4, s_10_56, -1, 143, 0},
/* 57 */ { 3, s_10_57, -1, 78, 0},
/* 58 */ { 6, s_10_58, 57, 79, 0},
/* 59 */ { 4, s_10_59, -1, 72, 0},
/* 60 */ { 5, s_10_60, -1, 71, 0},
/* 61 */ { 3, s_10_61, -1, 21, 0},
/* 62 */ { 4, s_10_62, -1, 157, 0},
/* 63 */ { 5, s_10_63, -1, 22, 0},
/* 64 */ { 4, s_10_64, -1, 19, 0},
/* 65 */ { 3, s_10_65, -1, 89, 0},
/* 66 */ { 4, s_10_66, -1, 159, 0},
/* 67 */ { 4, s_10_67, -1, -1, 0},
/* 68 */ { 4, s_10_68, -1, 62, 0},
/* 69 */ { 4, s_10_69, -1, 6, 0},
/* 70 */ { 2, s_10_70, -1, 134, 0},
/* 71 */ { 4, s_10_71, -1, 35, 0},
/* 72 */ { 4, s_10_72, -1, 74, 0},
/* 73 */ { 5, s_10_73, -1, 40, 0},
/* 74 */ { 5, s_10_74, -1, 73, 0},
/* 75 */ { 4, s_10_75, -1, 13, 0},
/* 76 */ { 6, s_10_76, -1, 44, 0},
/* 77 */ { 3, s_10_77, -1, 24, 0},
/* 78 */ { 4, s_10_78, -1, 52, 0},
/* 79 */ { 4, s_10_79, -1, 55, 0},
/* 80 */ { 3, s_10_80, -1, 50, 0},
/* 81 */ { 5, s_10_81, -1, 4, 0},
/* 82 */ { 4, s_10_82, -1, 27, 0},
/* 83 */ { 5, s_10_83, -1, 43, 0},
/* 84 */ { 3, s_10_84, -1, 51, 0},
/* 85 */ { 8, s_10_85, -1, 101, 0},
/* 86 */ { 7, s_10_86, -1, 100, 0},
/* 87 */ { 4, s_10_87, -1, -1, 0},
/* 88 */ { 4, s_10_88, -1, 10, 0},
/* 89 */ { 9, s_10_89, -1, 37, 0},
/* 90 */ { 4, s_10_90, -1, 12, 0},
/* 91 */ { 3, s_10_91, -1, 148, 0},
/* 92 */ { 4, s_10_92, 91, 120, 0},
/* 93 */ { 6, s_10_93, -1, 84, 0},
/* 94 */ { 5, s_10_94, -1, 93, 0},
/* 95 */ { 4, s_10_95, -1, 85, 0},
/* 96 */ { 4, s_10_96, -1, 92, 0},
/* 97 */ { 4, s_10_97, -1, 121, 0},
/* 98 */ { 4, s_10_98, -1, 14, 0},
/* 99 */ { 5, s_10_99, -1, 158, 0},
/*100 */ { 4, s_10_100, -1, 122, 0},
/*101 */ { 4, s_10_101, -1, 124, 0},
/*102 */ { 3, s_10_102, -1, 57, 0},
/*103 */ { 3, s_10_103, -1, 131, 0},
/*104 */ { 4, s_10_104, -1, 130, 0},
/*105 */ { 4, s_10_105, -1, 54, 0},
/*106 */ { 6, s_10_106, -1, 96, 0},
/*107 */ { 5, s_10_107, -1, 61, 0},
/*108 */ { 5, s_10_108, -1, 97, 0},
/*109 */ { 4, s_10_109, -1, 59, 0},
/*110 */ { 6, s_10_110, -1, 149, 0},
/*111 */ { 5, s_10_111, -1, 77, 0},
/*112 */ { 6, s_10_112, -1, 11, 0},
/*113 */ { 5, s_10_113, -1, 2, 0},
/*114 */ { 4, s_10_114, -1, 1, 0},
/*115 */ { 3, s_10_115, -1, -1, 0},
/*116 */ { 5, s_10_116, -1, 36, 0},
/*117 */ { 5, s_10_117, -1, 48, 0},
/*118 */ { 4, s_10_118, -1, 18, 0},
/*119 */ { 6, s_10_119, -1, 33, 0},
/*120 */ { 4, s_10_120, -1, 49, 0},
/*121 */ { 5, s_10_121, -1, 47, 0},
/*122 */ { 5, s_10_122, -1, 53, 0},
/*123 */ { 5, s_10_123, -1, 46, 0},
/*124 */ { 6, s_10_124, -1, 45, 0},
/*125 */ { 5, s_10_125, -1, 106, 0},
/*126 */ { 6, s_10_126, 125, 107, 0},
/*127 */ { 5, s_10_127, -1, 110, 0},
/*128 */ { 6, s_10_128, 127, 111, 0},
/*129 */ { 5, s_10_129, -1, 15, 0},
/*130 */ { 6, s_10_130, -1, 64, 0},
/*131 */ { 4, s_10_131, -1, 123, 0},
/*132 */ { 4, s_10_132, -1, 125, 0},
/*133 */ { 6, s_10_133, 132, 126, 0},
/*134 */ { 4, s_10_134, -1, 118, 0},
/*135 */ { 5, s_10_135, -1, 39, 0},
/*136 */ { 4, s_10_136, -1, 119, 0},
/*137 */ { 5, s_10_137, -1, 99, 0},
/*138 */ { 6, s_10_138, -1, 29, 0},
/*139 */ { 4, s_10_139, -1, 154, 0},
/*140 */ { 5, s_10_140, -1, 155, 0},
/*141 */ { 4, s_10_141, -1, 152, 0},
/*142 */ { 7, s_10_142, 141, 34, 0},
/*143 */ { 5, s_10_143, -1, 70, 0},
/*144 */ { 6, s_10_144, -1, 69, 0},
/*145 */ { 3, s_10_145, -1, 151, 0},
/*146 */ { 7, s_10_146, 145, 160, 0},
/*147 */ { 4, s_10_147, -1, 17, 0},
/*148 */ { 4, s_10_148, -1, 98, 0},
/*149 */ { 4, s_10_149, -1, 138, 0},
/*150 */ { 4, s_10_150, -1, 137, 0},
/*151 */ { 5, s_10_151, -1, 5, 0},
/*152 */ { 4, s_10_152, -1, 8, 0},
/*153 */ { 10, s_10_153, -1, 16, 0},
/*154 */ { 5, s_10_154, -1, 103, 0},
/*155 */ { 3, s_10_155, -1, 135, 0},
/*156 */ { 4, s_10_156, -1, 144, 0},
/*157 */ { 4, s_10_157, -1, 38, 0},
/*158 */ { 4, s_10_158, -1, 136, 0},
/*159 */ { 4, s_10_159, -1, 102, 0},
/*160 */ { 3, s_10_160, -1, 60, 0},
/*161 */ { 4, s_10_161, -1, 140, 0},
/*162 */ { 4, s_10_162, -1, 139, 0},
/*163 */ { 5, s_10_163, -1, 150, 0},
/*164 */ { 7, s_10_164, -1, 82, 0},
/*165 */ { 5, s_10_165, -1, 83, 0},
/*166 */ { 2, s_10_166, -1, 153, 0}
};

static const unsigned char g_v[] = { 17, 65, 16, 1 };

static const unsigned char g_v_WXY[] = { 1, 17, 65, 208, 1 };

static const unsigned char g_valid_LI[] = { 55, 141, 2 };

static const symbol s_0[] = { 'Y' };
static const symbol s_1[] = { 'Y' };
static const symbol s_2[] = { 's', 's' };
static const symbol s_3[] = { 'i' };
static const symbol s_4[] = { 'i', 'e' };
static const symbol s_5[] = { 'e', 'e' };
static const symbol s_6[] = { 'e' };
static const symbol s_7[] = { 'e' };
static const symbol s_8[] = { 'i' };
static const symbol s_9[] = { 't', 'i', 'o', 'n' };
static const symbol s_10[] = { 'e', 'n', 'c', 'e' };
static const symbol s_11[] = { 'a', 'n', 'c', 'e' };
static const symbol s_12[] = { 'a', 'b', 'l', 'e' };
static const symbol s_13[] = { 'e', 'n', 't' };
static const symbol s_14[] = { 'i', 'z', 'e' };
static const symbol s_15[] = { 'a', 't', 'e' };
static const symbol s_16[] = { 'a', 'l' };
static const symbol s_17[] = { 'f', 'u', 'l' };
static const symbol s_18[] = { 'o', 'u', 's' };
static const symbol s_19[] = { 'i', 'v', 'e' };
static const symbol s_20[] = { 'b', 'l', 'e' };
static const symbol s_21[] = { 'o', 'g' };
static const symbol s_22[] = { 'f', 'u', 'l' };
static const symbol s_23[] = { 'l', 'e', 's', 's' };
static const symbol s_24[] = { 't', 'i', 'o', 'n' };
static const symbol s_25[] = { 'a', 't', 'e' };
static const symbol s_26[] = { 'a', 'l' };
static const symbol s_27[] = { 'i', 'c' };
static const symbol s_28[] = { 's', 'k', 'i' };
static const symbol s_29[] = { 's', 'k', 'y' };
static const symbol s_30[] = { 'd', 'i', 'e' };
static const symbol s_31[] = { 'l', 'i', 'e' };
static const symbol s_32[] = { 't', 'i', 'e' };
static const symbol s_33[] = { 'i', 'd', 'l' };
static const symbol s_34[] = { 'g', 'e', 'n', 't', 'l' };
static const symbol s_35[] = { 'u', 'g', 'l', 'i' };
static const symbol s_36[] = { 'e', 'a', 'r', 'l', 'i' };
static const symbol s_37[] = { 'o', 'n', 'l', 'i' };
static const symbol s_38[] = { 's', 'i', 'n', 'g', 'l' };
static const symbol s_39[] = { 'p', 'a', 'y' };
static const symbol s_40[] = { 'l', 'a', 'y' };
static const symbol s_41[] = { 's', 'a', 'y' };
static const symbol s_42[] = { 's', 't', 'a', 'n', 'd' };
static const symbol s_43[] = { 'u', 'n', 'd', 'e', 'r', 't', 'a', 'n', 'd' };
static const symbol s_44[] = { 't', 'e', 'l', 'l' };
static const symbol s_45[] = { 's', 'e', 'l', 'l' };
static const symbol s_46[] = { 'h', 'o', 'l', 'd' };
static const symbol s_47[] = { 'f', 'i', 'n', 'd' };
static const symbol s_48[] = { 'h', 'a', 'v', 'e' };
static const symbol s_49[] = { 'h', 'e', 'a', 'r' };
static const symbol s_50[] = { 'f', 'l', 'y' };
static const symbol s_51[] = { 'l', 'e', 'a', 'd' };
static const symbol s_52[] = { 'f', 'e', 'e', 'd' };
static const symbol s_53[] = { 'b', 'l', 'e', 'e', 'd' };
static const symbol s_54[] = { 'm', 'a', 'k', 'e' };
static const symbol s_55[] = { 'c', 'a', 't', 'c', 'h' };
static const symbol s_56[] = { 't', 'e', 'a', 'c', 'h' };
static const symbol s_57[] = { 'b', 'r', 'i', 'n', 'g' };
static const symbol s_58[] = { 'b', 'u', 'y' };
static const symbol s_59[] = { 'f', 'i', 'g', 'h', 't' };
static const symbol s_60[] = { 's', 'e', 'e', 'k' };
static const symbol s_61[] = { 't', 'h', 'i', 'n', 'k' };
static const symbol s_62[] = { 'k', 'e', 'e', 'p' };
static const symbol s_63[] = { 's', 'l', 'e', 'e', 'p' };
static const symbol s_64[] = { 'o', 'v', 'e', 'r', 's', 'l', 'e', 'e', 'p' };
static const symbol s_65[] = { 'w', 'e', 'e', 'p' };
static const symbol s_66[] = { 's', 'w', 'e', 'e', 'p' };
static const symbol s_67[] = { 'k', 'n', 'e', 'e', 'l' };
static const symbol s_68[] = { 'f', 'e', 'e', 'l' };
static const symbol s_69[] = { 'd', 'e', 'a', 'l' };
static const symbol s_70[] = { 'm', 'e', 'a', 'n' };
static const symbol s_71[] = { 'l', 'e', 'a', 'r', 'n' };
static const symbol s_72[] = { 's', 'p', 'o', 'i', 'l' };
static const symbol s_73[] = { 's', 'p', 'i', 'l', 'l' };
static const symbol s_74[] = { 's', 'p', 'e', 'l', 'l' };
static const symbol s_75[] = { 's', 'm', 'e', 'l', 'l' };
static const symbol s_76[] = { 's', 'p', 'i', 't' };
static const symbol s_77[] = { 'l', 'i', 'g', 'h', 't' };
static const symbol s_78[] = { 'm', 'e', 'e', 't' };
static const symbol s_79[] = { 'l', 'e', 'a', 'v', 'e' };
static const symbol s_80[] = { 's', 'p', 'e', 'n', 'd' };
static const symbol s_81[] = { 's', 'e', 'n', 'd' };
static const symbol s_82[] = { 'l', 'e', 'n', 'd' };
static const symbol s_83[] = { 'b', 'u', 'i', 'l', 'd' };
static const symbol s_84[] = { 's', 'i', 't' };
static const symbol s_85[] = { 'b', 'a', 'b', 'y', 's', 'i', 't' };
static const symbol s_86[] = { 's', 'h', 'o', 'o', 't' };
static const symbol s_87[] = { 'w', 'i', 'n' };
static const symbol s_88[] = { 's', 'h', 'i', 'n', 'e' };
static const symbol s_89[] = { 'h', 'a', 'n', 'g' };
static const symbol s_90[] = { 'd', 'i', 'g' };
static const symbol s_91[] = { 's', 't', 'r', 'i', 'k', 'e' };
static const symbol s_92[] = { 'd', 'r', 'a', 'w' };
static const symbol s_93[] = { 'd', 'r', 'a', 'w' };
static const symbol s_94[] = { 'b', 'l', 'o', 'w' };
static const symbol s_95[] = { 'b', 'l', 'o', 'w' };
static const symbol s_96[] = { 't', 'h', 'r', 'o', 'w' };
static const symbol s_97[] = { 't', 'h', 'r', 'o', 'w' };
static const symbol s_98[] = { 'g', 'r', 'o', 'w' };
static const symbol s_99[] = { 'g', 'r', 'o', 'w' };
static const symbol s_100[] = { 'k', 'n', 'o', 'w' };
static const symbol s_101[] = { 'k', 'n', 'o', 'w' };
static const symbol s_102[] = { 'f', 'l', 'y' };
static const symbol s_103[] = { 'f', 'l', 'y' };
static const symbol s_104[] = { 's', 'h', 'o', 'w' };
static const symbol s_105[] = { 'g', 'e', 't' };
static const symbol s_106[] = { 'g', 'e', 't' };
static const symbol s_107[] = { 'f', 'o', 'r', 'g', 'e', 't' };
static const symbol s_108[] = { 'f', 'o', 'r', 'g', 'e', 't' };
static const symbol s_109[] = { 'w', 'r', 'i', 't', 'e' };
static const symbol s_110[] = { 'w', 'r', 'i', 't', 'e' };
static const symbol s_111[] = { 'r', 'i', 'd', 'e' };
static const symbol s_112[] = { 'r', 'i', 'd', 'e' };
static const symbol s_113[] = { 'e', 'a', 't' };
static const symbol s_114[] = { 'e', 'a', 't' };
static const symbol s_115[] = { 'b', 'i', 't', 'e' };
static const symbol s_116[] = { 'h', 'i', 'd', 'e' };
static const symbol s_117[] = { 'd', 'r', 'i', 'v', 'e' };
static const symbol s_118[] = { 'd', 'r', 'i', 'v', 'e' };
static const symbol s_119[] = { 'r', 'i', 's', 'e' };
static const symbol s_120[] = { 'r', 'i', 's', 'e' };
static const symbol s_121[] = { 'g', 'i', 'v', 'e' };
static const symbol s_122[] = { 'g', 'i', 'v', 'e' };
static const symbol s_123[] = { 's', 'h', 'a', 'k', 'e' };
static const symbol s_124[] = { 's', 'h', 'a', 'k', 'e' };
static const symbol s_125[] = { 't', 'a', 'k', 'e' };
static const symbol s_126[] = { 't', 'a', 'k', 'e' };
static const symbol s_127[] = { 'm', 'i', 's', 't', 'a', 'k' };
static const symbol s_128[] = { 'm', 'i', 's', 't', 'a', 'k' };
static const symbol s_129[] = { 'w', 'a', 'k', 'e' };
static const symbol s_130[] = { 'w', 'a', 'k', 'e' };
static const symbol s_131[] = { 'b', 'r', 'e', 'a', 'k' };
static const symbol s_132[] = { 'b', 'r', 'e', 'a', 'k' };
static const symbol s_133[] = { 's', 'p', 'e', 'a', 'k' };
static const symbol s_134[] = { 's', 'p', 'e', 'a', 'k' };
static const symbol s_135[] = { 'f', 'r', 'e', 'e', 'z' };
static const symbol s_136[] = { 'f', 'r', 'e', 'e', 'z' };
static const symbol s_137[] = { 's', 't', 'e', 'a', 'l' };
static const symbol s_138[] = { 's', 't', 'e', 'a', 'l' };
static const symbol s_139[] = { 'c', 'h', 'o', 'o', 's' };
static const symbol s_140[] = { 'c', 'h', 'o', 'o', 's' };
static const symbol s_141[] = { 'f', 'a', 'l', 'l' };
static const symbol s_142[] = { 'f', 'a', 'l', 'l' };
static const symbol s_143[] = { 'b', 'e', 'g', 'i', 'n' };
static const symbol s_144[] = { 'b', 'e', 'g', 'i', 'n' };
static const symbol s_145[] = { 's', 'w', 'i', 'm' };
static const symbol s_146[] = { 's', 'w', 'i', 'm' };
static const symbol s_147[] = { 'r', 'i', 'n', 'g' };
static const symbol s_148[] = { 'r', 'i', 'n', 'g' };
static const symbol s_149[] = { 's', 'i', 'n', 'g' };
static const symbol s_150[] = { 's', 'i', 'n', 'g' };
static const symbol s_151[] = { 's', 'i', 'n', 'k' };
static const symbol s_152[] = { 's', 'i', 'n', 'k' };
static const symbol s_153[] = { 's', 'i', 'n', 'k' };
static const symbol s_154[] = { 'd', 'r', 'i', 'n', 'k' };
static const symbol s_155[] = { 'd', 'r', 'i', 'n', 'k' };
static const symbol s_156[] = { 's', 'e', 'e' };
static const symbol s_157[] = { 'b', 'e' };
static const symbol s_158[] = { 'b', 'e' };
static const symbol s_159[] = { 'b', 'e' };
static const symbol s_160[] = { 'b', 'e' };
static const symbol s_161[] = { 'b', 'e' };
static const symbol s_162[] = { 't', 'e', 'a', 'r' };
static const symbol s_163[] = { 't', 'e', 'a', 'r' };
static const symbol s_164[] = { 'w', 'e', 'a', 'r' };
static const symbol s_165[] = { 'w', 'e', 'a', 'r' };
static const symbol s_166[] = { 'd', 'o' };
static const symbol s_167[] = { 'd', 'o' };
static const symbol s_168[] = { 'g', 'o' };
static const symbol s_169[] = { 'g', 'o' };
static const symbol s_170[] = { 'b', 'e', 'a', 't' };
static const symbol s_171[] = { 'c', 'o', 'm', 'e' };
static const symbol s_172[] = { 'b', 'e', 'c', 'o', 'm' };
static const symbol s_173[] = { 'r', 'u', 'n' };
static const symbol s_174[] = { 's', 'h', 'a', 'l', 'l' };
static const symbol s_175[] = { 'w', 'i', 'l', 'l' };
static const symbol s_176[] = { 'y', 'o', 'u', 'r' };
static const symbol s_177[] = { 'y', 'o', 'u' };
static const symbol s_178[] = { 'y', 'o', 'u' };
static const symbol s_179[] = { 'y', 'o', 'u' };
static const symbol s_180[] = { 'y', 'o', 'u', 'r' };
static const symbol s_181[] = { 'd', 'o' };
static const symbol s_182[] = { 'h', 'a', 'v', 'e' };
static const symbol s_183[] = { 's', 'a', 'y' };
static const symbol s_184[] = { 'h', 'e', 'l', 'p' };
static const symbol s_185[] = { 'y', 'o', 'u', 'r', 's', 'e', 'l', 'f' };
static const symbol s_186[] = { 'y' };

static int r_prelude(struct SN_env * z) { /* forwardmode */
    z->B[0] = 0; /* unset Y_found, line 26 */
    {   int c1 = z->c; /* do, line 27 */
        z->bra = z->c; /* [, line 27 */
        if (z->c == z->l || z->p[z->c] != '\'') goto lab0; /* literal, line 27 */
        z->c++;
        z->ket = z->c; /* ], line 27 */
        {   int ret = slice_del(z); /* delete, line 27 */
            if (ret < 0) return ret;
        }
    lab0:
        z->c = c1;
    }
    {   int c2 = z->c; /* do, line 28 */
        z->bra = z->c; /* [, line 28 */
        if (z->c == z->l || z->p[z->c] != 'y') goto lab1; /* literal, line 28 */
        z->c++;
        z->ket = z->c; /* ], line 28 */
        {   int ret = slice_from_s(z, 1, s_0); /* <-, line 28 */
            if (ret < 0) return ret;
        }
        z->B[0] = 1; /* set Y_found, line 28 */
    lab1:
        z->c = c2;
    }
    {   int c3 = z->c; /* do, line 29 */
        while(1) { /* repeat, line 29 */
            int c4 = z->c;
            while(1) { /* goto, line 29 */
                int c5 = z->c;
                if (in_grouping(z, g_v, 97, 121, 0)) goto lab4; /* grouping v, line 29 */
                z->bra = z->c; /* [, line 29 */
                if (z->c == z->l || z->p[z->c] != 'y') goto lab4; /* literal, line 29 */
                z->c++;
                z->ket = z->c; /* ], line 29 */
                z->c = c5;
                break;
            lab4:
                z->c = c5;
                if (z->c >= z->l) goto lab3;
                z->c++; /* goto, line 29 */
            }
            {   int ret = slice_from_s(z, 1, s_1); /* <-, line 29 */
                if (ret < 0) return ret;
            }
            z->B[0] = 1; /* set Y_found, line 29 */
            continue;
        lab3:
            z->c = c4;
            break;
        }
        z->c = c3;
    }
    return 1;
}

static int r_mark_regions(struct SN_env * z) { /* forwardmode */
    z->I[0] = z->l; /* $p1 = <integer expression>, line 33 */
    z->I[1] = z->l; /* $p2 = <integer expression>, line 34 */
    {   int c1 = z->c; /* do, line 35 */
        {   int c2 = z->c; /* or, line 41 */
            if (z->c + 4 >= z->l || z->p[z->c + 4] >> 5 != 3 || !((2375680 >> (z->p[z->c + 4] & 0x1f)) & 1)) goto lab2; /* among, line 36 */
            if (!(find_among(z, a_0, 3))) goto lab2;
            goto lab1;
        lab2:
            z->c = c2;
            {    /* gopast */ /* grouping v, line 41 */
                int ret = out_grouping(z, g_v, 97, 121, 1);
                if (ret < 0) goto lab0;
                z->c += ret;
            }
            {    /* gopast */ /* non v, line 41 */
                int ret = in_grouping(z, g_v, 97, 121, 1);
                if (ret < 0) goto lab0;
                z->c += ret;
            }
        }
    lab1:
        z->I[0] = z->c; /* setmark p1, line 42 */
        {    /* gopast */ /* grouping v, line 43 */
            int ret = out_grouping(z, g_v, 97, 121, 1);
            if (ret < 0) goto lab0;
            z->c += ret;
        }
        {    /* gopast */ /* non v, line 43 */
            int ret = in_grouping(z, g_v, 97, 121, 1);
            if (ret < 0) goto lab0;
            z->c += ret;
        }
        z->I[1] = z->c; /* setmark p2, line 43 */
    lab0:
        z->c = c1;
    }
    return 1;
}

static int r_shortv(struct SN_env * z) { /* backwardmode */
    {   int m1 = z->l - z->c; (void)m1; /* or, line 51 */
        if (out_grouping_b(z, g_v_WXY, 89, 121, 0)) goto lab1; /* non v_WXY, line 50 */
        if (in_grouping_b(z, g_v, 97, 121, 0)) goto lab1; /* grouping v, line 50 */
        if (out_grouping_b(z, g_v, 97, 121, 0)) goto lab1; /* non v, line 50 */
        goto lab0;
    lab1:
        z->c = z->l - m1;
        if (out_grouping_b(z, g_v, 97, 121, 0)) return 0; /* non v, line 52 */
        if (in_grouping_b(z, g_v, 97, 121, 0)) return 0; /* grouping v, line 52 */
        if (z->c > z->lb) return 0; /* atlimit, line 52 */
    }
lab0:
    return 1;
}

static int r_R1(struct SN_env * z) { /* backwardmode */
    if (!(z->I[0] <= z->c)) return 0; /* $p1 <= <integer expression>, line 55 */
    return 1;
}

static int r_R2(struct SN_env * z) { /* backwardmode */
    if (!(z->I[1] <= z->c)) return 0; /* $p2 <= <integer expression>, line 56 */
    return 1;
}

static int r_Step_1a(struct SN_env * z) { /* backwardmode */
    int among_var;
    {   int m1 = z->l - z->c; (void)m1; /* try, line 59 */
        z->ket = z->c; /* [, line 60 */
        if (z->c <= z->lb || (z->p[z->c - 1] != 39 && z->p[z->c - 1] != 115)) { z->c = z->l - m1; goto lab0; } /* substring, line 60 */
        among_var = find_among_b(z, a_1, 3);
        if (!(among_var)) { z->c = z->l - m1; goto lab0; }
        z->bra = z->c; /* ], line 60 */
        switch (among_var) { /* among, line 60 */
            case 0: { z->c = z->l - m1; goto lab0; }
            case 1:
                {   int ret = slice_del(z); /* delete, line 62 */
                    if (ret < 0) return ret;
                }
                break;
        }
    lab0:
        ;
    }
    z->ket = z->c; /* [, line 65 */
    if (z->c <= z->lb || (z->p[z->c - 1] != 100 && z->p[z->c - 1] != 115)) return 0; /* substring, line 65 */
    among_var = find_among_b(z, a_2, 6);
    if (!(among_var)) return 0;
    z->bra = z->c; /* ], line 65 */
    switch (among_var) { /* among, line 65 */
        case 0: return 0;
        case 1:
            {   int ret = slice_from_s(z, 2, s_2); /* <-, line 66 */
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {   int m2 = z->l - z->c; (void)m2; /* or, line 68 */
                {   int ret = z->c - 2; /* hop, line 68 */
                    if (z->lb > ret || ret > z->l) goto lab2;
                    z->c = ret;
                }
                {   int ret = slice_from_s(z, 1, s_3); /* <-, line 68 */
                    if (ret < 0) return ret;
                }
                goto lab1;
            lab2:
                z->c = z->l - m2;
                {   int ret = slice_from_s(z, 2, s_4); /* <-, line 68 */
                    if (ret < 0) return ret;
                }
            }
        lab1:
            break;
        case 3:
            if (z->c <= z->lb) return 0;
            z->c--; /* next, line 69 */
            {    /* gopast */ /* grouping v, line 69 */
                int ret = out_grouping_b(z, g_v, 97, 121, 1);
                if (ret < 0) return 0;
                z->c -= ret;
            }
            {   int ret = slice_del(z); /* delete, line 69 */
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_Step_1b(struct SN_env * z) { /* backwardmode */
    int among_var;
    z->ket = z->c; /* [, line 75 */
    if (z->c - 1 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((33554576 >> (z->p[z->c - 1] & 0x1f)) & 1)) return 0; /* substring, line 75 */
    among_var = find_among_b(z, a_4, 6);
    if (!(among_var)) return 0;
    z->bra = z->c; /* ], line 75 */
    switch (among_var) { /* among, line 75 */
        case 0: return 0;
        case 1:
            {   int ret = r_R1(z); /* call R1, line 77 */
                if (ret <= 0) return ret;
            }
            {   int ret = slice_from_s(z, 2, s_5); /* <-, line 77 */
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {   int m_test1 = z->l - z->c; /* test, line 80 */
                {    /* gopast */ /* grouping v, line 80 */
                    int ret = out_grouping_b(z, g_v, 97, 121, 1);
                    if (ret < 0) return 0;
                    z->c -= ret;
                }
                z->c = z->l - m_test1;
            }
            {   int ret = slice_del(z); /* delete, line 80 */
                if (ret < 0) return ret;
            }
            {   int m_test2 = z->l - z->c; /* test, line 81 */
                if (z->c - 1 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((68514004 >> (z->p[z->c - 1] & 0x1f)) & 1)) among_var = 3; else /* substring, line 81 */
                among_var = find_among_b(z, a_3, 13);
                if (!(among_var)) return 0;
                z->c = z->l - m_test2;
            }
            switch (among_var) { /* among, line 81 */
                case 0: return 0;
                case 1:
                    {   int ret;
                        {   int saved_c = z->c;
                            ret = insert_s(z, z->c, z->c, 1, s_6); /* <+, line 83 */
                            z->c = saved_c;
                        }
                        if (ret < 0) return ret;
                    }
                    break;
                case 2:
                    z->ket = z->c; /* [, line 86 */
                    if (z->c <= z->lb) return 0;
                    z->c--; /* next, line 86 */
                    z->bra = z->c; /* ], line 86 */
                    {   int ret = slice_del(z); /* delete, line 86 */
                        if (ret < 0) return ret;
                    }
                    break;
                case 3:
                    if (z->c != z->I[0]) return 0; /* atmark, line 87 */
                    {   int m_test3 = z->l - z->c; /* test, line 87 */
                        {   int ret = r_shortv(z); /* call shortv, line 87 */
                            if (ret <= 0) return ret;
                        }
                        z->c = z->l - m_test3;
                    }
                    {   int ret;
                        {   int saved_c = z->c;
                            ret = insert_s(z, z->c, z->c, 1, s_7); /* <+, line 87 */
                            z->c = saved_c;
                        }
                        if (ret < 0) return ret;
                    }
                    break;
            }
            break;
    }
    return 1;
}

static int r_Step_1c(struct SN_env * z) { /* backwardmode */
    z->ket = z->c; /* [, line 94 */
    {   int m1 = z->l - z->c; (void)m1; /* or, line 94 */
        if (z->c <= z->lb || z->p[z->c - 1] != 'y') goto lab1; /* literal, line 94 */
        z->c--;
        goto lab0;
    lab1:
        z->c = z->l - m1;
        if (z->c <= z->lb || z->p[z->c - 1] != 'Y') return 0; /* literal, line 94 */
        z->c--;
    }
lab0:
    z->bra = z->c; /* ], line 94 */
    if (out_grouping_b(z, g_v, 97, 121, 0)) return 0; /* non v, line 95 */
    {   int m2 = z->l - z->c; (void)m2; /* not, line 95 */
        if (z->c > z->lb) goto lab2; /* atlimit, line 95 */
        return 0;
    lab2:
        z->c = z->l - m2;
    }
    {   int ret = slice_from_s(z, 1, s_8); /* <-, line 96 */
        if (ret < 0) return ret;
    }
    return 1;
}

static int r_Step_2(struct SN_env * z) { /* backwardmode */
    int among_var;
    z->ket = z->c; /* [, line 100 */
    if (z->c - 1 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((815616 >> (z->p[z->c - 1] & 0x1f)) & 1)) return 0; /* substring, line 100 */
    among_var = find_among_b(z, a_5, 24);
    if (!(among_var)) return 0;
    z->bra = z->c; /* ], line 100 */
    {   int ret = r_R1(z); /* call R1, line 100 */
        if (ret <= 0) return ret;
    }
    switch (among_var) { /* among, line 100 */
        case 0: return 0;
        case 1:
            {   int ret = slice_from_s(z, 4, s_9); /* <-, line 101 */
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {   int ret = slice_from_s(z, 4, s_10); /* <-, line 102 */
                if (ret < 0) return ret;
            }
            break;
        case 3:
            {   int ret = slice_from_s(z, 4, s_11); /* <-, line 103 */
                if (ret < 0) return ret;
            }
            break;
        case 4:
            {   int ret = slice_from_s(z, 4, s_12); /* <-, line 104 */
                if (ret < 0) return ret;
            }
            break;
        case 5:
            {   int ret = slice_from_s(z, 3, s_13); /* <-, line 105 */
                if (ret < 0) return ret;
            }
            break;
        case 6:
            {   int ret = slice_from_s(z, 3, s_14); /* <-, line 107 */
                if (ret < 0) return ret;
            }
            break;
        case 7:
            {   int ret = slice_from_s(z, 3, s_15); /* <-, line 109 */
                if (ret < 0) return ret;
            }
            break;
        case 8:
            {   int ret = slice_from_s(z, 2, s_16); /* <-, line 111 */
                if (ret < 0) return ret;
            }
            break;
        case 9:
            {   int ret = slice_from_s(z, 3, s_17); /* <-, line 112 */
                if (ret < 0) return ret;
            }
            break;
        case 10:
            {   int ret = slice_from_s(z, 3, s_18); /* <-, line 114 */
                if (ret < 0) return ret;
            }
            break;
        case 11:
            {   int ret = slice_from_s(z, 3, s_19); /* <-, line 116 */
                if (ret < 0) return ret;
            }
            break;
        case 12:
            {   int ret = slice_from_s(z, 3, s_20); /* <-, line 118 */
                if (ret < 0) return ret;
            }
            break;
        case 13:
            if (z->c <= z->lb || z->p[z->c - 1] != 'l') return 0; /* literal, line 119 */
            z->c--;
            {   int ret = slice_from_s(z, 2, s_21); /* <-, line 119 */
                if (ret < 0) return ret;
            }
            break;
        case 14:
            {   int ret = slice_from_s(z, 3, s_22); /* <-, line 120 */
                if (ret < 0) return ret;
            }
            break;
        case 15:
            {   int ret = slice_from_s(z, 4, s_23); /* <-, line 121 */
                if (ret < 0) return ret;
            }
            break;
        case 16:
            if (in_grouping_b(z, g_valid_LI, 99, 116, 0)) return 0; /* grouping valid_LI, line 122 */
            {   int ret = slice_del(z); /* delete, line 122 */
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_Step_3(struct SN_env * z) { /* backwardmode */
    int among_var;
    z->ket = z->c; /* [, line 127 */
    if (z->c - 2 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((528928 >> (z->p[z->c - 1] & 0x1f)) & 1)) return 0; /* substring, line 127 */
    among_var = find_among_b(z, a_6, 9);
    if (!(among_var)) return 0;
    z->bra = z->c; /* ], line 127 */
    {   int ret = r_R1(z); /* call R1, line 127 */
        if (ret <= 0) return ret;
    }
    switch (among_var) { /* among, line 127 */
        case 0: return 0;
        case 1:
            {   int ret = slice_from_s(z, 4, s_24); /* <-, line 128 */
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {   int ret = slice_from_s(z, 3, s_25); /* <-, line 129 */
                if (ret < 0) return ret;
            }
            break;
        case 3:
            {   int ret = slice_from_s(z, 2, s_26); /* <-, line 130 */
                if (ret < 0) return ret;
            }
            break;
        case 4:
            {   int ret = slice_from_s(z, 2, s_27); /* <-, line 132 */
                if (ret < 0) return ret;
            }
            break;
        case 5:
            {   int ret = slice_del(z); /* delete, line 134 */
                if (ret < 0) return ret;
            }
            break;
        case 6:
            {   int ret = r_R2(z); /* call R2, line 136 */
                if (ret <= 0) return ret;
            }
            {   int ret = slice_del(z); /* delete, line 136 */
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_Step_4(struct SN_env * z) { /* backwardmode */
    int among_var;
    z->ket = z->c; /* [, line 141 */
    if (z->c - 1 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((1864232 >> (z->p[z->c - 1] & 0x1f)) & 1)) return 0; /* substring, line 141 */
    among_var = find_among_b(z, a_7, 18);
    if (!(among_var)) return 0;
    z->bra = z->c; /* ], line 141 */
    {   int ret = r_R2(z); /* call R2, line 141 */
        if (ret <= 0) return ret;
    }
    switch (among_var) { /* among, line 141 */
        case 0: return 0;
        case 1:
            {   int ret = slice_del(z); /* delete, line 144 */
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {   int m1 = z->l - z->c; (void)m1; /* or, line 145 */
                if (z->c <= z->lb || z->p[z->c - 1] != 's') goto lab1; /* literal, line 145 */
                z->c--;
                goto lab0;
            lab1:
                z->c = z->l - m1;
                if (z->c <= z->lb || z->p[z->c - 1] != 't') return 0; /* literal, line 145 */
                z->c--;
            }
        lab0:
            {   int ret = slice_del(z); /* delete, line 145 */
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_Step_5(struct SN_env * z) { /* backwardmode */
    int among_var;
    z->ket = z->c; /* [, line 150 */
    if (z->c <= z->lb || (z->p[z->c - 1] != 101 && z->p[z->c - 1] != 108)) return 0; /* substring, line 150 */
    among_var = find_among_b(z, a_8, 2);
    if (!(among_var)) return 0;
    z->bra = z->c; /* ], line 150 */
    switch (among_var) { /* among, line 150 */
        case 0: return 0;
        case 1:
            {   int m1 = z->l - z->c; (void)m1; /* or, line 151 */
                {   int ret = r_R2(z); /* call R2, line 151 */
                    if (ret == 0) goto lab1;
                    if (ret < 0) return ret;
                }
                goto lab0;
            lab1:
                z->c = z->l - m1;
                {   int ret = r_R1(z); /* call R1, line 151 */
                    if (ret <= 0) return ret;
                }
                {   int m2 = z->l - z->c; (void)m2; /* not, line 151 */
                    {   int ret = r_shortv(z); /* call shortv, line 151 */
                        if (ret == 0) goto lab2;
                        if (ret < 0) return ret;
                    }
                    return 0;
                lab2:
                    z->c = z->l - m2;
                }
            }
        lab0:
            {   int ret = slice_del(z); /* delete, line 151 */
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {   int ret = r_R2(z); /* call R2, line 152 */
                if (ret <= 0) return ret;
            }
            if (z->c <= z->lb || z->p[z->c - 1] != 'l') return 0; /* literal, line 152 */
            z->c--;
            {   int ret = slice_del(z); /* delete, line 152 */
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_exception2(struct SN_env * z) { /* backwardmode */
    z->ket = z->c; /* [, line 158 */
    if (z->c - 5 <= z->lb || (z->p[z->c - 1] != 100 && z->p[z->c - 1] != 103)) return 0; /* substring, line 158 */
    if (!(find_among_b(z, a_9, 8))) return 0;
    z->bra = z->c; /* ], line 158 */
    if (z->c > z->lb) return 0; /* atlimit, line 158 */
    return 1;
}

static int r_exception1(struct SN_env * z) { /* forwardmode */
    int among_var;
    z->bra = z->c; /* [, line 170 */
    if (z->c + 1 >= z->l || z->p[z->c + 1] >> 5 != 3 || !((50199474 >> (z->p[z->c + 1] & 0x1f)) & 1)) return 0; /* substring, line 170 */
    among_var = find_among(z, a_10, 167);
    if (!(among_var)) return 0;
    z->ket = z->c; /* ], line 170 */
    if (z->c < z->l) return 0; /* atlimit, line 170 */
    switch (among_var) { /* among, line 170 */
        case 0: return 0;
        case 1:
            {   int ret = slice_from_s(z, 3, s_28); /* <-, line 174 */
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {   int ret = slice_from_s(z, 3, s_29); /* <-, line 175 */
                if (ret < 0) return ret;
            }
            break;
        case 3:
            {   int ret = slice_from_s(z, 3, s_30); /* <-, line 176 */
                if (ret < 0) return ret;
            }
            break;
        case 4:
            {   int ret = slice_from_s(z, 3, s_31); /* <-, line 177 */
                if (ret < 0) return ret;
            }
            break;
        case 5:
            {   int ret = slice_from_s(z, 3, s_32); /* <-, line 178 */
                if (ret < 0) return ret;
            }
            break;
        case 6:
            {   int ret = slice_from_s(z, 3, s_33); /* <-, line 182 */
                if (ret < 0) return ret;
            }
            break;
        case 7:
            {   int ret = slice_from_s(z, 5, s_34); /* <-, line 183 */
                if (ret < 0) return ret;
            }
            break;
        case 8:
            {   int ret = slice_from_s(z, 4, s_35); /* <-, line 184 */
                if (ret < 0) return ret;
            }
            break;
        case 9:
            {   int ret = slice_from_s(z, 5, s_36); /* <-, line 185 */
                if (ret < 0) return ret;
            }
            break;
        case 10:
            {   int ret = slice_from_s(z, 4, s_37); /* <-, line 186 */
                if (ret < 0) return ret;
            }
            break;
        case 11:
            {   int ret = slice_from_s(z, 5, s_38); /* <-, line 187 */
                if (ret < 0) return ret;
            }
            break;
        case 12:
            {   int ret = slice_from_s(z, 3, s_39); /* <-, line 190 */
                if (ret < 0) return ret;
            }
            break;
        case 13:
            {   int ret = slice_from_s(z, 3, s_40); /* <-, line 191 */
                if (ret < 0) return ret;
            }
            break;
        case 14:
            {   int ret = slice_from_s(z, 3, s_41); /* <-, line 192 */
                if (ret < 0) return ret;
            }
            break;
        case 15:
            {   int ret = slice_from_s(z, 5, s_42); /* <-, line 193 */
                if (ret < 0) return ret;
            }
            break;
        case 16:
            {   int ret = slice_from_s(z, 9, s_43); /* <-, line 194 */
                if (ret < 0) return ret;
            }
            break;
        case 17:
            {   int ret = slice_from_s(z, 4, s_44); /* <-, line 195 */
                if (ret < 0) return ret;
            }
            break;
        case 18:
            {   int ret = slice_from_s(z, 4, s_45); /* <-, line 196 */
                if (ret < 0) return ret;
            }
            break;
        case 19:
            {   int ret = slice_from_s(z, 4, s_46); /* <-, line 197 */
                if (ret < 0) return ret;
            }
            break;
        case 20:
            {   int ret = slice_from_s(z, 4, s_47); /* <-, line 198 */
                if (ret < 0) return ret;
            }
            break;
        case 21:
            {   int ret = slice_from_s(z, 4, s_48); /* <-, line 199 */
                if (ret < 0) return ret;
            }
            break;
        case 22:
            {   int ret = slice_from_s(z, 4, s_49); /* <-, line 200 */
                if (ret < 0) return ret;
            }
            break;
        case 23:
            {   int ret = slice_from_s(z, 3, s_50); /* <-, line 201 */
                if (ret < 0) return ret;
            }
            break;
        case 24:
            {   int ret = slice_from_s(z, 4, s_51); /* <-, line 202 */
                if (ret < 0) return ret;
            }
            break;
        case 25:
            {   int ret = slice_from_s(z, 4, s_52); /* <-, line 203 */
                if (ret < 0) return ret;
            }
            break;
        case 26:
            {   int ret = slice_from_s(z, 5, s_53); /* <-, line 204 */
                if (ret < 0) return ret;
            }
            break;
        case 27:
            {   int ret = slice_from_s(z, 4, s_54); /* <-, line 205 */
                if (ret < 0) return ret;
            }
            break;
        case 28:
            {   int ret = slice_from_s(z, 5, s_55); /* <-, line 206 */
                if (ret < 0) return ret;
            }
            break;
        case 29:
            {   int ret = slice_from_s(z, 5, s_56); /* <-, line 207 */
                if (ret < 0) return ret;
            }
            break;
        case 30:
            {   int ret = slice_from_s(z, 5, s_57); /* <-, line 208 */
                if (ret < 0) return ret;
            }
            break;
        case 31:
            {   int ret = slice_from_s(z, 3, s_58); /* <-, line 209 */
                if (ret < 0) return ret;
            }
            break;
        case 32:
            {   int ret = slice_from_s(z, 5, s_59); /* <-, line 210 */
                if (ret < 0) return ret;
            }
            break;
        case 33:
            {   int ret = slice_from_s(z, 4, s_60); /* <-, line 211 */
                if (ret < 0) return ret;
            }
            break;
        case 34:
            {   int ret = slice_from_s(z, 5, s_61); /* <-, line 212 */
                if (ret < 0) return ret;
            }
            break;
        case 35:
            {   int ret = slice_from_s(z, 4, s_62); /* <-, line 213 */
                if (ret < 0) return ret;
            }
            break;
        case 36:
            {   int ret = slice_from_s(z, 5, s_63); /* <-, line 214 */
                if (ret < 0) return ret;
            }
            break;
        case 37:
            {   int ret = slice_from_s(z, 9, s_64); /* <-, line 215 */
                if (ret < 0) return ret;
            }
            break;
        case 38:
            {   int ret = slice_from_s(z, 4, s_65); /* <-, line 216 */
                if (ret < 0) return ret;
            }
            break;
        case 39:
            {   int ret = slice_from_s(z, 5, s_66); /* <-, line 217 */
                if (ret < 0) return ret;
            }
            break;
        case 40:
            {   int ret = slice_from_s(z, 5, s_67); /* <-, line 218 */
                if (ret < 0) return ret;
            }
            break;
        case 41:
            {   int ret = slice_from_s(z, 4, s_68); /* <-, line 219 */
                if (ret < 0) return ret;
            }
            break;
        case 42:
            {   int ret = slice_from_s(z, 4, s_69); /* <-, line 220 */
                if (ret < 0) return ret;
            }
            break;
        case 43:
            {   int ret = slice_from_s(z, 4, s_70); /* <-, line 221 */
                if (ret < 0) return ret;
            }
            break;
        case 44:
            {   int ret = slice_from_s(z, 5, s_71); /* <-, line 222 */
                if (ret < 0) return ret;
            }
            break;
        case 45:
            {   int ret = slice_from_s(z, 5, s_72); /* <-, line 223 */
                if (ret < 0) return ret;
            }
            break;
        case 46:
            {   int ret = slice_from_s(z, 5, s_73); /* <-, line 224 */
                if (ret < 0) return ret;
            }
            break;
        case 47:
            {   int ret = slice_from_s(z, 5, s_74); /* <-, line 225 */
                if (ret < 0) return ret;
            }
            break;
        case 48:
            {   int ret = slice_from_s(z, 5, s_75); /* <-, line 226 */
                if (ret < 0) return ret;
            }
            break;
        case 49:
            {   int ret = slice_from_s(z, 4, s_76); /* <-, line 227 */
                if (ret < 0) return ret;
            }
            break;
        case 50:
            {   int ret = slice_from_s(z, 5, s_77); /* <-, line 228 */
                if (ret < 0) return ret;
            }
            break;
        case 51:
            {   int ret = slice_from_s(z, 4, s_78); /* <-, line 229 */
                if (ret < 0) return ret;
            }
            break;
        case 52:
            {   int ret = slice_from_s(z, 5, s_79); /* <-, line 230 */
                if (ret < 0) return ret;
            }
            break;
        case 53:
            {   int ret = slice_from_s(z, 5, s_80); /* <-, line 231 */
                if (ret < 0) return ret;
            }
            break;
        case 54:
            {   int ret = slice_from_s(z, 4, s_81); /* <-, line 232 */
                if (ret < 0) return ret;
            }
            break;
        case 55:
            {   int ret = slice_from_s(z, 4, s_82); /* <-, line 233 */
                if (ret < 0) return ret;
            }
            break;
        case 56:
            {   int ret = slice_from_s(z, 5, s_83); /* <-, line 234 */
                if (ret < 0) return ret;
            }
            break;
        case 57:
            {   int ret = slice_from_s(z, 3, s_84); /* <-, line 235 */
                if (ret < 0) return ret;
            }
            break;
        case 58:
            {   int ret = slice_from_s(z, 7, s_85); /* <-, line 236 */
                if (ret < 0) return ret;
            }
            break;
        case 59:
            {   int ret = slice_from_s(z, 5, s_86); /* <-, line 237 */
                if (ret < 0) return ret;
            }
            break;
        case 60:
            {   int ret = slice_from_s(z, 3, s_87); /* <-, line 238 */
                if (ret < 0) return ret;
            }
            break;
        case 61:
            {   int ret = slice_from_s(z, 5, s_88); /* <-, line 239 */
                if (ret < 0) return ret;
            }
            break;
        case 62:
            {   int ret = slice_from_s(z, 4, s_89); /* <-, line 240 */
                if (ret < 0) return ret;
            }
            break;
        case 63:
            {   int ret = slice_from_s(z, 3, s_90); /* <-, line 241 */
                if (ret < 0) return ret;
            }
            break;
        case 64:
            {   int ret = slice_from_s(z, 6, s_91); /* <-, line 242 */
                if (ret < 0) return ret;
            }
            break;
        case 65:
            {   int ret = slice_from_s(z, 4, s_92); /* <-, line 243 */
                if (ret < 0) return ret;
            }
            break;
        case 66:
            {   int ret = slice_from_s(z, 4, s_93); /* <-, line 244 */
                if (ret < 0) return ret;
            }
            break;
        case 67:
            {   int ret = slice_from_s(z, 4, s_94); /* <-, line 245 */
                if (ret < 0) return ret;
            }
            break;
        case 68:
            {   int ret = slice_from_s(z, 4, s_95); /* <-, line 246 */
                if (ret < 0) return ret;
            }
            break;
        case 69:
            {   int ret = slice_from_s(z, 5, s_96); /* <-, line 247 */
                if (ret < 0) return ret;
            }
            break;
        case 70:
            {   int ret = slice_from_s(z, 5, s_97); /* <-, line 248 */
                if (ret < 0) return ret;
            }
            break;
        case 71:
            {   int ret = slice_from_s(z, 4, s_98); /* <-, line 249 */
                if (ret < 0) return ret;
            }
            break;
        case 72:
            {   int ret = slice_from_s(z, 4, s_99); /* <-, line 250 */
                if (ret < 0) return ret;
            }
            break;
        case 73:
            {   int ret = slice_from_s(z, 4, s_100); /* <-, line 251 */
                if (ret < 0) return ret;
            }
            break;
        case 74:
            {   int ret = slice_from_s(z, 4, s_101); /* <-, line 252 */
                if (ret < 0) return ret;
            }
            break;
        case 75:
            {   int ret = slice_from_s(z, 3, s_102); /* <-, line 253 */
                if (ret < 0) return ret;
            }
            break;
        case 76:
            {   int ret = slice_from_s(z, 3, s_103); /* <-, line 254 */
                if (ret < 0) return ret;
            }
            break;
        case 77:
            {   int ret = slice_from_s(z, 4, s_104); /* <-, line 255 */
                if (ret < 0) return ret;
            }
            break;
        case 78:
            {   int ret = slice_from_s(z, 3, s_105); /* <-, line 256 */
                if (ret < 0) return ret;
            }
            break;
        case 79:
            {   int ret = slice_from_s(z, 3, s_106); /* <-, line 257 */
                if (ret < 0) return ret;
            }
            break;
        case 80:
            {   int ret = slice_from_s(z, 6, s_107); /* <-, line 258 */
                if (ret < 0) return ret;
            }
            break;
        case 81:
            {   int ret = slice_from_s(z, 6, s_108); /* <-, line 259 */
                if (ret < 0) return ret;
            }
            break;
        case 82:
            {   int ret = slice_from_s(z, 5, s_109); /* <-, line 260 */
                if (ret < 0) return ret;
            }
            break;
        case 83:
            {   int ret = slice_from_s(z, 5, s_110); /* <-, line 261 */
                if (ret < 0) return ret;
            }
            break;
        case 84:
            {   int ret = slice_from_s(z, 4, s_111); /* <-, line 262 */
                if (ret < 0) return ret;
            }
            break;
        case 85:
            {   int ret = slice_from_s(z, 4, s_112); /* <-, line 263 */
                if (ret < 0) return ret;
            }
            break;
        case 86:
            {   int ret = slice_from_s(z, 3, s_113); /* <-, line 264 */
                if (ret < 0) return ret;
            }
            break;
        case 87:
            {   int ret = slice_from_s(z, 3, s_114); /* <-, line 265 */
                if (ret < 0) return ret;
            }
            break;
        case 88:
            {   int ret = slice_from_s(z, 4, s_115); /* <-, line 266 */
                if (ret < 0) return ret;
            }
            break;
        case 89:
            {   int ret = slice_from_s(z, 4, s_116); /* <-, line 267 */
                if (ret < 0) return ret;
            }
            break;
        case 90:
            {   int ret = slice_from_s(z, 5, s_117); /* <-, line 268 */
                if (ret < 0) return ret;
            }
            break;
        case 91:
            {   int ret = slice_from_s(z, 5, s_118); /* <-, line 269 */
                if (ret < 0) return ret;
            }
            break;
        case 92:
            {   int ret = slice_from_s(z, 4, s_119); /* <-, line 270 */
                if (ret < 0) return ret;
            }
            break;
        case 93:
            {   int ret = slice_from_s(z, 4, s_120); /* <-, line 271 */
                if (ret < 0) return ret;
            }
            break;
        case 94:
            {   int ret = slice_from_s(z, 4, s_121); /* <-, line 272 */
                if (ret < 0) return ret;
            }
            break;
        case 95:
            {   int ret = slice_from_s(z, 4, s_122); /* <-, line 273 */
                if (ret < 0) return ret;
            }
            break;
        case 96:
            {   int ret = slice_from_s(z, 5, s_123); /* <-, line 274 */
                if (ret < 0) return ret;
            }
            break;
        case 97:
            {   int ret = slice_from_s(z, 5, s_124); /* <-, line 275 */
                if (ret < 0) return ret;
            }
            break;
        case 98:
            {   int ret = slice_from_s(z, 4, s_125); /* <-, line 276 */
                if (ret < 0) return ret;
            }
            break;
        case 99:
            {   int ret = slice_from_s(z, 4, s_126); /* <-, line 277 */
                if (ret < 0) return ret;
            }
            break;
        case 100:
            {   int ret = slice_from_s(z, 6, s_127); /* <-, line 278 */
                if (ret < 0) return ret;
            }
            break;
        case 101:
            {   int ret = slice_from_s(z, 6, s_128); /* <-, line 279 */
                if (ret < 0) return ret;
            }
            break;
        case 102:
            {   int ret = slice_from_s(z, 4, s_129); /* <-, line 280 */
                if (ret < 0) return ret;
            }
            break;
        case 103:
            {   int ret = slice_from_s(z, 4, s_130); /* <-, line 281 */
                if (ret < 0) return ret;
            }
            break;
        case 104:
            {   int ret = slice_from_s(z, 5, s_131); /* <-, line 282 */
                if (ret < 0) return ret;
            }
            break;
        case 105:
            {   int ret = slice_from_s(z, 5, s_132); /* <-, line 283 */
                if (ret < 0) return ret;
            }
            break;
        case 106:
            {   int ret = slice_from_s(z, 5, s_133); /* <-, line 284 */
                if (ret < 0) return ret;
            }
            break;
        case 107:
            {   int ret = slice_from_s(z, 5, s_134); /* <-, line 285 */
                if (ret < 0) return ret;
            }
            break;
        case 108:
            {   int ret = slice_from_s(z, 5, s_135); /* <-, line 286 */
                if (ret < 0) return ret;
            }
            break;
        case 109:
            {   int ret = slice_from_s(z, 5, s_136); /* <-, line 287 */
                if (ret < 0) return ret;
            }
            break;
        case 110:
            {   int ret = slice_from_s(z, 5, s_137); /* <-, line 288 */
                if (ret < 0) return ret;
            }
            break;
        case 111:
            {   int ret = slice_from_s(z, 5, s_138); /* <-, line 289 */
                if (ret < 0) return ret;
            }
            break;
        case 112:
            {   int ret = slice_from_s(z, 5, s_139); /* <-, line 290 */
                if (ret < 0) return ret;
            }
            break;
        case 113:
            {   int ret = slice_from_s(z, 5, s_140); /* <-, line 291 */
                if (ret < 0) return ret;
            }
            break;
        case 114:
            {   int ret = slice_from_s(z, 4, s_141); /* <-, line 292 */
                if (ret < 0) return ret;
            }
            break;
        case 115:
            {   int ret = slice_from_s(z, 4, s_142); /* <-, line 293 */
                if (ret < 0) return ret;
            }
            break;
        case 116:
            {   int ret = slice_from_s(z, 5, s_143); /* <-, line 294 */
                if (ret < 0) return ret;
            }
            break;
        case 117:
            {   int ret = slice_from_s(z, 5, s_144); /* <-, line 295 */
                if (ret < 0) return ret;
            }
            break;
        case 118:
            {   int ret = slice_from_s(z, 4, s_145); /* <-, line 296 */
                if (ret < 0) return ret;
            }
            break;
        case 119:
            {   int ret = slice_from_s(z, 4, s_146); /* <-, line 297 */
                if (ret < 0) return ret;
            }
            break;
        case 120:
            {   int ret = slice_from_s(z, 4, s_147); /* <-, line 298 */
                if (ret < 0) return ret;
            }
            break;
        case 121:
            {   int ret = slice_from_s(z, 4, s_148); /* <-, line 299 */
                if (ret < 0) return ret;
            }
            break;
        case 122:
            {   int ret = slice_from_s(z, 4, s_149); /* <-, line 300 */
                if (ret < 0) return ret;
            }
            break;
        case 123:
            {   int ret = slice_from_s(z, 4, s_150); /* <-, line 301 */
                if (ret < 0) return ret;
            }
            break;
        case 124:
            {   int ret = slice_from_s(z, 4, s_151); /* <-, line 302 */
                if (ret < 0) return ret;
            }
            break;
        case 125:
            {   int ret = slice_from_s(z, 4, s_152); /* <-, line 303 */
                if (ret < 0) return ret;
            }
            break;
        case 126:
            {   int ret = slice_from_s(z, 4, s_153); /* <-, line 304 */
                if (ret < 0) return ret;
            }
            break;
        case 127:
            {   int ret = slice_from_s(z, 5, s_154); /* <-, line 305 */
                if (ret < 0) return ret;
            }
            break;
        case 128:
            {   int ret = slice_from_s(z, 5, s_155); /* <-, line 306 */
                if (ret < 0) return ret;
            }
            break;
        case 129:
            {   int ret = slice_from_s(z, 0, 0); /* <-, line 307 */
                if (ret < 0) return ret;
            }
            break;
        case 130:
            {   int ret = slice_from_s(z, 0, 0); /* <-, line 308 */
                if (ret < 0) return ret;
            }
            break;
        case 131:
            {   int ret = slice_from_s(z, 3, s_156); /* <-, line 309 */
                if (ret < 0) return ret;
            }
            break;
        case 132:
            {   int ret = slice_from_s(z, 2, s_157); /* <-, line 310 */
                if (ret < 0) return ret;
            }
            break;
        case 133:
            {   int ret = slice_from_s(z, 2, s_158); /* <-, line 311 */
                if (ret < 0) return ret;
            }
            break;
        case 134:
            {   int ret = slice_from_s(z, 2, s_159); /* <-, line 312 */
                if (ret < 0) return ret;
            }
            break;
        case 135:
            {   int ret = slice_from_s(z, 2, s_160); /* <-, line 313 */
                if (ret < 0) return ret;
            }
            break;
        case 136:
            {   int ret = slice_from_s(z, 2, s_161); /* <-, line 314 */
                if (ret < 0) return ret;
            }
            break;
        case 137:
            {   int ret = slice_from_s(z, 4, s_162); /* <-, line 315 */
                if (ret < 0) return ret;
            }
            break;
        case 138:
            {   int ret = slice_from_s(z, 4, s_163); /* <-, line 316 */
                if (ret < 0) return ret;
            }
            break;
        case 139:
            {   int ret = slice_from_s(z, 4, s_164); /* <-, line 317 */
                if (ret < 0) return ret;
            }
            break;
        case 140:
            {   int ret = slice_from_s(z, 4, s_165); /* <-, line 318 */
                if (ret < 0) return ret;
            }
            break;
        case 141:
            {   int ret = slice_from_s(z, 2, s_166); /* <-, line 319 */
                if (ret < 0) return ret;
            }
            break;
        case 142:
            {   int ret = slice_from_s(z, 2, s_167); /* <-, line 320 */
                if (ret < 0) return ret;
            }
            break;
        case 143:
            {   int ret = slice_from_s(z, 2, s_168); /* <-, line 321 */
                if (ret < 0) return ret;
            }
            break;
        case 144:
            {   int ret = slice_from_s(z, 2, s_169); /* <-, line 322 */
                if (ret < 0) return ret;
            }
            break;
        case 145:
            {   int ret = slice_from_s(z, 4, s_170); /* <-, line 323 */
                if (ret < 0) return ret;
            }
            break;
        case 146:
            {   int ret = slice_from_s(z, 4, s_171); /* <-, line 324 */
                if (ret < 0) return ret;
            }
            break;
        case 147:
            {   int ret = slice_from_s(z, 5, s_172); /* <-, line 325 */
                if (ret < 0) return ret;
            }
            break;
        case 148:
            {   int ret = slice_from_s(z, 3, s_173); /* <-, line 326 */
                if (ret < 0) return ret;
            }
            break;
        case 149:
            {   int ret = slice_from_s(z, 5, s_174); /* <-, line 327 */
                if (ret < 0) return ret;
            }
            break;
        case 150:
            {   int ret = slice_from_s(z, 4, s_175); /* <-, line 328 */
                if (ret < 0) return ret;
            }
            break;
        case 151:
            {   int ret = slice_from_s(z, 4, s_176); /* <-, line 331 */
                if (ret < 0) return ret;
            }
            break;
        case 152:
            {   int ret = slice_from_s(z, 3, s_177); /* <-, line 332 */
                if (ret < 0) return ret;
            }
            break;
        case 153:
            {   int ret = slice_from_s(z, 3, s_178); /* <-, line 333 */
                if (ret < 0) return ret;
            }
            break;
        case 154:
            {   int ret = slice_from_s(z, 3, s_179); /* <-, line 334 */
                if (ret < 0) return ret;
            }
            break;
        case 155:
            {   int ret = slice_from_s(z, 4, s_180); /* <-, line 335 */
                if (ret < 0) return ret;
            }
            break;
        case 156:
            {   int ret = slice_from_s(z, 2, s_181); /* <-, line 336 */
                if (ret < 0) return ret;
            }
            break;
        case 157:
            {   int ret = slice_from_s(z, 4, s_182); /* <-, line 337 */
                if (ret < 0) return ret;
            }
            break;
        case 158:
            {   int ret = slice_from_s(z, 3, s_183); /* <-, line 338 */
                if (ret < 0) return ret;
            }
            break;
        case 159:
            {   int ret = slice_from_s(z, 4, s_184); /* <-, line 339 */
                if (ret < 0) return ret;
            }
            break;
        case 160:
            {   int ret = slice_from_s(z, 8, s_185); /* <-, line 340 */
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_postlude(struct SN_env * z) { /* forwardmode */
    if (!(z->B[0])) return 0; /* Boolean test Y_found, line 355 */
    while(1) { /* repeat, line 355 */
        int c1 = z->c;
        while(1) { /* goto, line 355 */
            int c2 = z->c;
            z->bra = z->c; /* [, line 355 */
            if (z->c == z->l || z->p[z->c] != 'Y') goto lab1; /* literal, line 355 */
            z->c++;
            z->ket = z->c; /* ], line 355 */
            z->c = c2;
            break;
        lab1:
            z->c = c2;
            if (z->c >= z->l) goto lab0;
            z->c++; /* goto, line 355 */
        }
        {   int ret = slice_from_s(z, 1, s_186); /* <-, line 355 */
            if (ret < 0) return ret;
        }
        continue;
    lab0:
        z->c = c1;
        break;
    }
    return 1;
}

extern int stem(struct SN_env * z) { /* forwardmode */
    {   int c1 = z->c; /* or, line 359 */
        {   int ret = r_exception1(z); /* call exception1, line 359 */
            if (ret == 0) goto lab1;
            if (ret < 0) return ret;
        }
        goto lab0;
    lab1:
        z->c = c1;
        {   int c2 = z->c; /* not, line 360 */
            {   int ret = z->c + 3; /* hop, line 360 */
                if (0 > ret || ret > z->l) goto lab3;
                z->c = ret;
            }
            goto lab2;
        lab3:
            z->c = c2;
        }
        goto lab0;
    lab2:
        z->c = c1;
        {   int c3 = z->c; /* do, line 361 */
            {   int ret = r_prelude(z); /* call prelude, line 361 */
                if (ret == 0) goto lab4;
                if (ret < 0) return ret;
            }
        lab4:
            z->c = c3;
        }
        {   int c4 = z->c; /* do, line 362 */
            {   int ret = r_mark_regions(z); /* call mark_regions, line 362 */
                if (ret == 0) goto lab5;
                if (ret < 0) return ret;
            }
        lab5:
            z->c = c4;
        }
        z->lb = z->c; z->c = z->l; /* backwards, line 363 */

        {   int m5 = z->l - z->c; (void)m5; /* do, line 365 */
            {   int ret = r_Step_1a(z); /* call Step_1a, line 365 */
                if (ret == 0) goto lab6;
                if (ret < 0) return ret;
            }
        lab6:
            z->c = z->l - m5;
        }
        {   int m6 = z->l - z->c; (void)m6; /* or, line 367 */
            {   int ret = r_exception2(z); /* call exception2, line 367 */
                if (ret == 0) goto lab8;
                if (ret < 0) return ret;
            }
            goto lab7;
        lab8:
            z->c = z->l - m6;
            {   int m7 = z->l - z->c; (void)m7; /* do, line 369 */
                {   int ret = r_Step_1b(z); /* call Step_1b, line 369 */
                    if (ret == 0) goto lab9;
                    if (ret < 0) return ret;
                }
            lab9:
                z->c = z->l - m7;
            }
            {   int m8 = z->l - z->c; (void)m8; /* do, line 370 */
                {   int ret = r_Step_1c(z); /* call Step_1c, line 370 */
                    if (ret == 0) goto lab10;
                    if (ret < 0) return ret;
                }
            lab10:
                z->c = z->l - m8;
            }
            {   int m9 = z->l - z->c; (void)m9; /* do, line 372 */
                {   int ret = r_Step_2(z); /* call Step_2, line 372 */
                    if (ret == 0) goto lab11;
                    if (ret < 0) return ret;
                }
            lab11:
                z->c = z->l - m9;
            }
            {   int m10 = z->l - z->c; (void)m10; /* do, line 373 */
                {   int ret = r_Step_3(z); /* call Step_3, line 373 */
                    if (ret == 0) goto lab12;
                    if (ret < 0) return ret;
                }
            lab12:
                z->c = z->l - m10;
            }
            {   int m11 = z->l - z->c; (void)m11; /* do, line 374 */
                {   int ret = r_Step_4(z); /* call Step_4, line 374 */
                    if (ret == 0) goto lab13;
                    if (ret < 0) return ret;
                }
            lab13:
                z->c = z->l - m11;
            }
            {   int m12 = z->l - z->c; (void)m12; /* do, line 376 */
                {   int ret = r_Step_5(z); /* call Step_5, line 376 */
                    if (ret == 0) goto lab14;
                    if (ret < 0) return ret;
                }
            lab14:
                z->c = z->l - m12;
            }
        }
    lab7:
        z->c = z->lb;
        {   int c13 = z->c; /* do, line 379 */
            {   int ret = r_postlude(z); /* call postlude, line 379 */
                if (ret == 0) goto lab15;
                if (ret < 0) return ret;
            }
        lab15:
            z->c = c13;
        }
    }
lab0:
    return 1;
}

extern struct SN_env * create_env(void) { return SN_create_env(0, 2, 1); }

extern void close_env(struct SN_env * z) { SN_close_env(z, 0); }

