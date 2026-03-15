/* Include files */

#include "flightControlSystem_sfun.h"
#include "c1_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c1_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c1_b_emlrtMCI = { 90,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c1_c_emlrtMCI = { 198,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtMCInfo c1_d_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c1_e_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c1_f_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRSInfo c1_emlrtRSI = { 18, /* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_b_emlrtRSI = { 19,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_c_emlrtRSI = { 22,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_d_emlrtRSI = { 27,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_e_emlrtRSI = { 28,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_f_emlrtRSI = { 46,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_g_emlrtRSI = { 54,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_h_emlrtRSI = { 70,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_i_emlrtRSI = { 94,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_j_emlrtRSI = { 95,/* lineNo */
  "Image Processing System/Linia na Punkty",/* fcnName */
  "#flightControlSystem:2825"          /* pathName */
};

static emlrtRSInfo c1_k_emlrtRSI = { 77,/* lineNo */
  "bwmorph",                           /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\bwmorph.m"/* pathName */
};

static emlrtRSInfo c1_l_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_m_emlrtRSI = { 256,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_n_emlrtRSI = { 143,/* lineNo */
  "bwlookup",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\bwlookup.m"/* pathName */
};

static emlrtRSInfo c1_o_emlrtRSI = { 24,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_p_emlrtRSI = { 66,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_q_emlrtRSI = { 69,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_r_emlrtRSI = { 87,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_s_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_t_emlrtRSI = { 132,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_u_emlrtRSI = { 249,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_v_emlrtRSI = { 248,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_w_emlrtRSI = { 247,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c1_x_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c1_y_emlrtRSI = { 143,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c1_ab_emlrtRSI = { 17,/* lineNo */
  "max",                               /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo c1_bb_emlrtRSI = { 58,/* lineNo */
  "minOrMax",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_cb_emlrtRSI = { 97,/* lineNo */
  "minOrMax",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo c1_db_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c1_eb_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c1_fb_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRTEInfo c1_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 32,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 189,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 191,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 247,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 248,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtBCInfo c1_emlrtBCI = { 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  23,                                  /* lineNo */
  18,                                  /* colNo */
  "x_all",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c1_b_emlrtBCI = { 0,/* iFirst */
  MAX_int32_T,                         /* iLast */
  29,                                  /* lineNo */
  22,                                  /* colNo */
  "x_all",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c1_i_emlrtRTEI = { 53,/* lineNo */
  17,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtRTEInfo c1_j_emlrtRTEI = { 72,/* lineNo */
  21,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtRTEInfo c1_k_emlrtRTEI = { 132,/* lineNo */
  17,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtRTEInfo c1_l_emlrtRTEI = { 135,/* lineNo */
  21,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtRTEInfo c1_m_emlrtRTEI = { 155,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtDCInfo c1_emlrtDCI = { 156,/* lineNo */
  34,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_c_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  156,                                 /* lineNo */
  34,                                  /* colNo */
  "selected_pts",                      /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_b_emlrtDCI = { 156,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_d_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  156,                                 /* lineNo */
  13,                                  /* colNo */
  "pts",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo c1_n_emlrtRTEI = { 163,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtRTEInfo c1_o_emlrtRTEI = { 175,/* lineNo */
  13,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825"          /* pName */
};

static emlrtDCInfo c1_c_emlrtDCI = { 179,/* lineNo */
  19,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_e_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  179,                                 /* lineNo */
  19,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_d_emlrtDCI = { 179,/* lineNo */
  22,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_f_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  179,                                 /* lineNo */
  22,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_e_emlrtDCI = { 181,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_g_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  181,                                 /* lineNo */
  23,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_f_emlrtDCI = { 181,/* lineNo */
  28,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_h_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  181,                                 /* lineNo */
  28,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_g_emlrtDCI = { 181,/* lineNo */
  45,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_i_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  181,                                 /* lineNo */
  45,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_h_emlrtDCI = { 181,/* lineNo */
  50,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_j_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  181,                                 /* lineNo */
  50,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_i_emlrtDCI = { 182,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_k_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  182,                                 /* lineNo */
  23,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_j_emlrtDCI = { 182,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_l_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  182,                                 /* lineNo */
  26,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_k_emlrtDCI = { 182,/* lineNo */
  45,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_m_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  182,                                 /* lineNo */
  45,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_l_emlrtDCI = { 182,/* lineNo */
  48,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_n_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  182,                                 /* lineNo */
  48,                                  /* colNo */
  "out_3",                             /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c1_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  20,                                  /* colNo */
  "x_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_m_emlrtDCI = { 47,/* lineNo */
  20,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  36,                                  /* colNo */
  "y_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_n_emlrtDCI = { 47,/* lineNo */
  36,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  22,                                  /* colNo */
  "x_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_o_emlrtDCI = { 62,/* lineNo */
  22,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  36,                                  /* colNo */
  "y_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_p_emlrtDCI = { 62,/* lineNo */
  36,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  25,                                  /* colNo */
  "x_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_q_emlrtDCI = { 54,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_t_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  164,                                 /* lineNo */
  35,                                  /* colNo */
  "pts",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_r_emlrtDCI = { 164,/* lineNo */
  35,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_u_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  164,                                 /* lineNo */
  20,                                  /* colNo */
  "pts_vector",                        /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_s_emlrtDCI = { 164,/* lineNo */
  20,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_v_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  165,                                 /* lineNo */
  35,                                  /* colNo */
  "pts",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_t_emlrtDCI = { 165,/* lineNo */
  35,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_w_emlrtBCI = { 1,/* iFirst */
  20,                                  /* iLast */
  165,                                 /* lineNo */
  20,                                  /* colNo */
  "pts_vector",                        /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_u_emlrtDCI = { 165,/* lineNo */
  20,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_x_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  147,                                 /* lineNo */
  57,                                  /* colNo */
  "selected_pts",                      /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_v_emlrtDCI = { 147,/* lineNo */
  57,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_y_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  147,                                 /* lineNo */
  83,                                  /* colNo */
  "prev_pts",                          /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_w_emlrtDCI = { 147,/* lineNo */
  83,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_ab_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  147,                                 /* lineNo */
  30,                                  /* colNo */
  "selected_pts",                      /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_x_emlrtDCI = { 147,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_bb_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  148,                                 /* lineNo */
  57,                                  /* colNo */
  "selected_pts",                      /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_y_emlrtDCI = { 148,/* lineNo */
  57,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_cb_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  148,                                 /* lineNo */
  83,                                  /* colNo */
  "prev_pts",                          /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_ab_emlrtDCI = { 148,/* lineNo */
  83,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_db_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  148,                                 /* lineNo */
  30,                                  /* colNo */
  "selected_pts",                      /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c1_bb_emlrtDCI = { 148,/* lineNo */
  30,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_eb_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  137,                                 /* lineNo */
  39,                                  /* colNo */
  "selected_pts",                      /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_cb_emlrtDCI = { 137,/* lineNo */
  39,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_fb_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  137,                                 /* lineNo */
  55,                                  /* colNo */
  "prev_pts",                          /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_db_emlrtDCI = { 137,/* lineNo */
  55,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_gb_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  176,                                 /* lineNo */
  23,                                  /* colNo */
  "pts",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_eb_emlrtDCI = { 176,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_hb_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  138,                                 /* lineNo */
  39,                                  /* colNo */
  "selected_pts",                      /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_fb_emlrtDCI = { 138,/* lineNo */
  39,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_ib_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  138,                                 /* lineNo */
  55,                                  /* colNo */
  "prev_pts",                          /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_gb_emlrtDCI = { 138,/* lineNo */
  55,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  51,                                  /* colNo */
  "y_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_hb_emlrtDCI = { 54,/* lineNo */
  51,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  26,                                  /* colNo */
  "x_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_ib_emlrtDCI = { 73,/* lineNo */
  26,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  39,                                  /* colNo */
  "y_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_jb_emlrtDCI = { 73,/* lineNo */
  39,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_mb_emlrtBCI = { 1,/* iFirst */
  10,                                  /* iLast */
  177,                                 /* lineNo */
  23,                                  /* colNo */
  "pts",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_kb_emlrtDCI = { 177,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  27,                                  /* colNo */
  "x_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_lb_emlrtDCI = { 92,/* lineNo */
  27,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c1_ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  44,                                  /* colNo */
  "y_s",                               /* aName */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c1_mb_emlrtDCI = { 92,/* lineNo */
  44,                                  /* colNo */
  "Image Processing System/Linia na Punkty",/* fName */
  "#flightControlSystem:2825",         /* pName */
  1                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  real_T c1_bwin[19200], boolean_T c1_bw[19200]);
static void c1_b_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200]);
static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[19200], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1]);
static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void c1_c_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200]);
static void c1_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_x_data[], int32_T c1_x_size[1], real32_T *
  c1_ex, int32_T *c1_idx);
static real32_T c1_sqrt(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_x);
static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier, real_T
  c1_y[19200]);
static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[19200]);
static void c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_y[19200]);
static void c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200]);
static void c1_e_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  real32_T c1_y[20]);
static void c1_f_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[20]);
static void c1_g_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  real32_T c1_y[20]);
static void c1_h_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[20]);
static real_T c1_i_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T *c1_svPtr);
static real_T c1_j_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr);
static void c1_k_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T *c1_svPtr, real32_T c1_y[20]);
static void c1_l_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, real32_T c1_y[20]);
static void c1_b_sqrt(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real32_T *c1_x);
static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c1_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_prev_pts_not_empty = false;
  chartInstance->c1_prev_count_not_empty = false;
  chartInstance->c1_doneDoubleBufferReInit = false;
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c1_c_postfixPredicateTree[7] = { 0, 1, -3, 2, -3, 3, -3 };

  static const int32_T c1_d_postfixPredicateTree[7] = { 0, 1, -3, 2, -3, 3, -3 };

  static const int32_T c1_c_condTxtEndIdx[4] = { 5579, 5596, 5606, 5623 };

  static const int32_T c1_c_condTxtStartIdx[4] = { 5573, 5583, 5600, 5610 };

  static const int32_T c1_d_condTxtEndIdx[4] = { 5676, 5692, 5701, 5717 };

  static const int32_T c1_d_condTxtStartIdx[4] = { 5671, 5680, 5696, 5705 };

  static const int32_T c1_b_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c1_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c1_b_condTxtEndIdx[2] = { 4142, 4160 };

  static const int32_T c1_b_condTxtStartIdx[2] = { 4129, 4146 };

  static const int32_T c1_condTxtEndIdx[2] = { 3183, 3209 };

  static const int32_T c1_condTxtStartIdx[2] = { 3159, 3187 };

  static const uint32_T c1_decisionTxtEndIdx = 0U;
  static const uint32_T c1_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c1_JITStateAnimation[0],
                        &chartInstance->c1_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c1_covrtInstance, 1U, 0U, 1U,
    142U);
  covrtChartInitFcn(chartInstance->c1_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c1_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c1_decisionTxtStartIdx, &c1_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c1_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c1_covrtInstance, "", 4U, 0U, 1U, 0U, 17U, 0U,
                  0U, 0U, 7U, 0U, 12U, 4U);
  covrtEmlFcnInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U,
                     "c1_flightControlSystem", 0, -1, 5877);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 245, 265, -1,
                    347, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 783, 800, -1,
                    946, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 1325, 1343, -1,
                    3846, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 1685, 1706, -1,
                    1787, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 1817, 1849,
                    3642, 3838, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 2415, 2446, -1,
                    2552, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 2856, 2888, -1,
                    3328, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 3156, 3209, -1,
                    3312, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 8U, 3354, 3372,
                    3476, 3633, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 9U, 3897, 3914, -1,
                    4116, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 10U, 3923, 3965, -1,
                    4108, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 11U, 4126, 4160, -1,
                    4942, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 12U, 4347, 4356, -1,
                    4670, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 13U, 4538, 4551, -1,
                    4649, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 14U, 4699, 4716, -1,
                    4922, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 15U, 5570, 5623, -1,
                    5865, false);
  covrtEmlIfInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 16U, 5668, 5717, -1,
                    5853, false);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 1582, 1602,
                     1799);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 2186, 2206,
                     2568);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 4198, 4217,
                     4934);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 4292, 4328,
                     4686);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 5016, 5035,
                     5083);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 5164, 5183,
                     5273);
  covrtEmlForInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 5482, 5501,
                     5873);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 3159, 3209,
                      2U, 0U, &c1_condTxtStartIdx[0], &c1_condTxtEndIdx[0], 3U,
                      &c1_postfixPredicateTree[0], false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 4129, 4160,
                      2U, 2U, &c1_b_condTxtStartIdx[0], &c1_b_condTxtEndIdx[0],
                      3U, &c1_b_postfixPredicateTree[0], false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 5573, 5623,
                      4U, 4U, &c1_c_condTxtStartIdx[0], &c1_c_condTxtEndIdx[0],
                      7U, &c1_c_postfixPredicateTree[0], false);
  covrtEmlMCDCInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 5671, 5717,
                      4U, 8U, &c1_d_condTxtStartIdx[0], &c1_d_condTxtEndIdx[0],
                      7U, &c1_d_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 0U, 786,
    800, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 1U, 1328,
    1343, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 2U, 1688,
    1706, -3, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 3U, 1820,
    1849, -3, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 4U, 2418,
    2446, -3, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 5U, 2859,
    2888, -3, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 6U, 3159,
    3183, -3, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 7U, 3187,
    3209, -3, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 8U, 3900,
    3914, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 9U, 3926,
    3965, -3, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 10U, 4129,
    4142, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 11U, 4146,
    4160, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 12U, 4350,
    4356, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 13U, 4541,
    4551, -3, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 14U, 4702,
    4716, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 15U, 5573,
    5579, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 16U, 5583,
    5596, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 17U, 5600,
    5606, -1, 5U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 18U, 5610,
    5623, -1, 3U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 19U, 5671,
    5676, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 20U, 5680,
    5692, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 21U, 5696,
    5701, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c1_covrtInstance, 4U, 0U, 22U, 5705,
    5717, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c1_covrtInstance);
}

static void enable_c1_flightControlSystem(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c1_b_st;
  emlrtStack c1_c_st;
  emlrtStack c1_d_st;
  emlrtStack c1_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c1_a;
  real_T c1_b_idx_start;
  real_T c1_b_num_pixels;
  real_T c1_b_p;
  real_T c1_b_sel_count;
  real_T c1_b_x;
  real_T c1_best_idx;
  real_T c1_c_k;
  real_T c1_c_num_pixels;
  real_T c1_c_sel_count;
  real_T c1_c_x;
  real_T c1_d;
  real_T c1_d1;
  real_T c1_d10;
  real_T c1_d11;
  real_T c1_d12;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  real_T c1_d5;
  real_T c1_d6;
  real_T c1_d7;
  real_T c1_d8;
  real_T c1_d9;
  real_T c1_d_sel_count;
  real_T c1_d_x;
  real_T c1_e_sel_count;
  real_T c1_e_x;
  real_T c1_idx_corner;
  real_T c1_idx_end;
  real_T c1_idx_start;
  real_T c1_num_pixels;
  real_T c1_sel_count;
  real_T c1_varargin_1;
  real_T c1_x;
  int32_T c1_ii_size[1];
  int32_T c1_jj_size[1];
  int32_T c1_x_all_size[1];
  int32_T c1_x_s_size[1];
  int32_T c1_y_all_size[1];
  int32_T c1_y_s_size[1];
  int32_T c1_b_k;
  int32_T c1_b_loop_ub;
  int32_T c1_c_loop_ub;
  int32_T c1_d_k;
  int32_T c1_d_loop_ub;
  int32_T c1_e_k;
  int32_T c1_e_loop_ub;
  int32_T c1_f_k;
  int32_T c1_f_loop_ub;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i2;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i3;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i4;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i5;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i6;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i7;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i8;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i9;
  int32_T c1_i90;
  int32_T c1_i_k;
  int32_T c1_idx;
  int32_T c1_iindx;
  int32_T c1_k;
  int32_T c1_loop_ub;
  int32_T c1_p;
  real32_T c1_y_s_data[19200];
  real32_T c1_b_pts[20];
  real32_T c1_b_pts_vector[20];
  real32_T c1_selected_pts[6];
  real32_T c1_swap_pts[6];
  real32_T c1_P_cand[2];
  real32_T c1_P_corner[2];
  real32_T c1_P_end[2];
  real32_T c1_P_start[2];
  real32_T c1_ab_a;
  real32_T c1_b_a;
  real32_T c1_b_c;
  real32_T c1_b_y;
  real32_T c1_bb_a;
  real32_T c1_c;
  real32_T c1_c_a;
  real32_T c1_c_c;
  real32_T c1_cb_a;
  real32_T c1_cross_prod;
  real32_T c1_d_a;
  real32_T c1_d_c;
  real32_T c1_d_end;
  real32_T c1_d_sq;
  real32_T c1_d_start;
  real32_T c1_db_a;
  real32_T c1_dd;
  real32_T c1_dist_to_line;
  real32_T c1_dx;
  real32_T c1_dy;
  real32_T c1_e_a;
  real32_T c1_e_c;
  real32_T c1_eb_a;
  real32_T c1_ex;
  real32_T c1_f;
  real32_T c1_f_a;
  real32_T c1_f_c;
  real32_T c1_f_x;
  real32_T c1_fb_a;
  real32_T c1_g_a;
  real32_T c1_g_c;
  real32_T c1_g_x;
  real32_T c1_h_a;
  real32_T c1_h_x;
  real32_T c1_i_a;
  real32_T c1_i_x;
  real32_T c1_j_a;
  real32_T c1_j_x;
  real32_T c1_k_a;
  real32_T c1_k_x;
  real32_T c1_l_a;
  real32_T c1_l_x;
  real32_T c1_len_line;
  real32_T c1_m_a;
  real32_T c1_m_x;
  real32_T c1_max_deviation;
  real32_T c1_max_dist_sq;
  real32_T c1_min_d;
  real32_T c1_n_a;
  real32_T c1_n_x;
  real32_T c1_o_a;
  real32_T c1_p_a;
  real32_T c1_px;
  real32_T c1_py;
  real32_T c1_q_a;
  real32_T c1_r;
  real32_T c1_r_a;
  real32_T c1_s_a;
  real32_T c1_t_a;
  real32_T c1_u_a;
  real32_T c1_v_a;
  real32_T c1_vx;
  real32_T c1_vy;
  real32_T c1_w_a;
  real32_T c1_x_a;
  real32_T c1_y;
  real32_T c1_y_a;
  boolean_T c1_endpoints_img[19200];
  boolean_T c1_points_cloud_img[19200];
  boolean_T c1_skel_base[19200];
  boolean_T c1_is_valid_corner;
  c1_st.tls = chartInstance->c1_fEmlrtCtx;
  c1_b_st.prev = &c1_st;
  c1_b_st.tls = c1_st.tls;
  c1_c_st.prev = &c1_b_st;
  c1_c_st.tls = c1_b_st.tls;
  c1_d_st.prev = &c1_c_st;
  c1_d_st.tls = c1_c_st.tls;
  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 0U) != 0U) {
    for (c1_i = 0; c1_i < 19200; c1_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 0U, (*
        chartInstance->c1_b_binaryImage)[c1_i]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_JITTransitionAnimation[0] = 0U;
  chartInstance->c1_sfEvent = CALL_EVENT;
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    chartInstance->c1_binaryImage[c1_i1] = (*chartInstance->c1_b_binaryImage)
      [c1_i1];
  }

  covrtEmlFcnEval(chartInstance->c1_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                     !chartInstance->c1_prev_pts_not_empty)) {
    memset(&chartInstance->c1_prev_pts[0], 0, 20U * sizeof(real32_T));
    chartInstance->c1_prev_pts_not_empty = true;
    chartInstance->c1_prev_count = 0.0;
    chartInstance->c1_prev_count_not_empty = true;
  }

  memset(&c1_b_pts_vector[0], 0, 20U * sizeof(real32_T));
  c1_b_st.site = &c1_emlrtRSI;
  c1_bwmorph(chartInstance, chartInstance->c1_binaryImage, c1_skel_base);
  c1_b_st.site = &c1_b_emlrtRSI;
  c1_b_bwmorph(chartInstance, c1_skel_base, c1_points_cloud_img);
  c1_b_st.site = &c1_c_emlrtRSI;
  c1_c_st.site = &c1_s_emlrtRSI;
  c1_eml_find(chartInstance, c1_points_cloud_img, chartInstance->c1_ii_data,
              c1_ii_size, chartInstance->c1_jj_data, c1_jj_size);
  c1_y_all_size[0] = c1_ii_size[0];
  c1_loop_ub = c1_ii_size[0] - 1;
  for (c1_i2 = 0; c1_i2 <= c1_loop_ub; c1_i2++) {
    chartInstance->c1_y_all_data[c1_i2] = (real_T)chartInstance->
      c1_ii_data[c1_i2];
  }

  c1_x_all_size[0] = c1_jj_size[0];
  c1_b_loop_ub = c1_jj_size[0] - 1;
  for (c1_i3 = 0; c1_i3 <= c1_b_loop_ub; c1_i3++) {
    chartInstance->c1_x_all_data[c1_i3] = (real_T)chartInstance->
      c1_jj_data[c1_i3];
  }

  if (c1_x_all_size[0] < 0) {
    emlrtDynamicBoundsCheckR2012b(c1_x_all_size[0], 0, MAX_int32_T, &c1_emlrtBCI,
      &c1_st);
  }

  c1_num_pixels = (real_T)c1_x_all_size[0];
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 1,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 0U, c1_num_pixels, 2.0, -1, 2U, c1_num_pixels < 2.0))) {
    c1_b_st.site = &c1_d_emlrtRSI;
    c1_c_bwmorph(chartInstance, c1_skel_base, c1_endpoints_img);
    c1_b_st.site = &c1_e_emlrtRSI;
    c1_c_st.site = &c1_s_emlrtRSI;
    c1_eml_find(chartInstance, c1_endpoints_img, chartInstance->c1_ii_data,
                c1_ii_size, chartInstance->c1_jj_data, c1_jj_size);
    c1_y_all_size[0] = c1_ii_size[0];
    c1_e_loop_ub = c1_ii_size[0] - 1;
    for (c1_i6 = 0; c1_i6 <= c1_e_loop_ub; c1_i6++) {
      chartInstance->c1_y_all_data[c1_i6] = (real_T)chartInstance->
        c1_ii_data[c1_i6];
    }

    c1_x_all_size[0] = c1_jj_size[0];
    c1_f_loop_ub = c1_jj_size[0] - 1;
    for (c1_i7 = 0; c1_i7 <= c1_f_loop_ub; c1_i7++) {
      chartInstance->c1_x_all_data[c1_i7] = (real_T)chartInstance->
        c1_jj_data[c1_i7];
    }

    if (c1_x_all_size[0] < 0) {
      emlrtDynamicBoundsCheckR2012b(c1_x_all_size[0], 0, MAX_int32_T,
        &c1_b_emlrtBCI, &c1_st);
    }

    c1_num_pixels = (real_T)c1_x_all_size[0];
  }

  c1_x_s_size[0] = c1_x_all_size[0];
  c1_c_loop_ub = c1_x_all_size[0] - 1;
  for (c1_i4 = 0; c1_i4 <= c1_c_loop_ub; c1_i4++) {
    chartInstance->c1_x_s_data[c1_i4] = (real32_T)chartInstance->
      c1_x_all_data[c1_i4];
  }

  c1_y_s_size[0] = c1_y_all_size[0];
  c1_d_loop_ub = c1_y_all_size[0] - 1;
  for (c1_i5 = 0; c1_i5 <= c1_d_loop_ub; c1_i5++) {
    c1_y_s_data[c1_i5] = (real32_T)chartInstance->c1_y_all_data[c1_i5];
  }

  memset(&c1_selected_pts[0], 0, 6U * sizeof(real32_T));
  c1_sel_count = 0.0;
  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 2,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 1U, c1_num_pixels, 2.0, -1, 5U, c1_num_pixels >= 2.0))) {
    c1_b_st.site = &c1_f_emlrtRSI;
    c1_c_st.site = &c1_ab_emlrtRSI;
    c1_d_st.site = &c1_bb_emlrtRSI;
    c1_maximum(chartInstance, &c1_d_st, c1_y_s_data, c1_y_s_size, &c1_ex,
               &c1_idx);
    c1_iindx = c1_idx;
    c1_idx_start = (real_T)c1_iindx;
    c1_b_idx_start = c1_idx_start;
    if (c1_b_idx_start != (real_T)(int32_T)muDoubleScalarFloor(c1_b_idx_start))
    {
      emlrtIntegerCheckR2012b(c1_b_idx_start, &c1_m_emlrtDCI, &c1_st);
    }

    c1_i15 = (int32_T)c1_b_idx_start;
    if ((c1_i15 < 1) || (c1_i15 > c1_x_s_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c1_i15, 1, c1_x_s_size[0], &c1_o_emlrtBCI,
        &c1_st);
    }

    c1_P_start[0] = chartInstance->c1_x_s_data[c1_i15 - 1];
    if (c1_b_idx_start != (real_T)(int32_T)muDoubleScalarFloor(c1_b_idx_start))
    {
      emlrtIntegerCheckR2012b(c1_b_idx_start, &c1_n_emlrtDCI, &c1_st);
    }

    c1_i17 = (int32_T)c1_b_idx_start;
    if ((c1_i17 < 1) || (c1_i17 > c1_y_s_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c1_i17, 1, c1_y_s_size[0], &c1_p_emlrtBCI,
        &c1_st);
    }

    c1_P_start[1] = c1_y_s_data[c1_i17 - 1];
    c1_max_dist_sq = -1.0F;
    c1_idx_end = -1.0;
    c1_b_num_pixels = c1_num_pixels;
    c1_i20 = (int32_T)c1_b_num_pixels;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_b_num_pixels, mxDOUBLE_CLASS,
      c1_i20, &c1_i_emlrtRTEI, &c1_st);
    for (c1_f_k = 0; c1_f_k < c1_i20; c1_f_k++) {
      c1_c_k = 1.0 + (real_T)c1_f_k;
      covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 0, 1);
      c1_b_st.site = &c1_g_emlrtRSI;
      if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
        emlrtIntegerCheckR2012b(c1_c_k, &c1_q_emlrtDCI, &c1_b_st);
      }

      c1_i31 = (int32_T)c1_c_k;
      if ((c1_i31 < 1) || (c1_i31 > c1_x_s_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c1_i31, 1, c1_x_s_size[0], &c1_s_emlrtBCI,
          &c1_b_st);
      }

      c1_b_a = chartInstance->c1_x_s_data[c1_i31 - 1] - c1_P_start[0];
      c1_c_st.site = &c1_eb_emlrtRSI;
      c1_c_a = c1_b_a;
      c1_d_a = c1_c_a;
      c1_e_a = c1_d_a;
      c1_f_a = c1_e_a;
      c1_b_c = c1_f_a * c1_f_a;
      c1_b_st.site = &c1_g_emlrtRSI;
      if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
        emlrtIntegerCheckR2012b(c1_c_k, &c1_hb_emlrtDCI, &c1_b_st);
      }

      c1_i53 = (int32_T)c1_c_k;
      if ((c1_i53 < 1) || (c1_i53 > c1_y_s_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c1_i53, 1, c1_y_s_size[0], &c1_jb_emlrtBCI,
          &c1_b_st);
      }

      c1_g_a = c1_y_s_data[c1_i53 - 1] - c1_P_start[1];
      c1_c_st.site = &c1_eb_emlrtRSI;
      c1_h_a = c1_g_a;
      c1_i_a = c1_h_a;
      c1_j_a = c1_i_a;
      c1_k_a = c1_j_a;
      c1_c_c = c1_k_a * c1_k_a;
      c1_d_sq = c1_b_c + c1_c_c;
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 3,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 2U, (real_T)
                          c1_d_sq, (real_T)c1_max_dist_sq, -3, 4U, c1_d_sq >
                          c1_max_dist_sq))) {
        c1_max_dist_sq = c1_d_sq;
        c1_idx_end = c1_c_k;
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 0, 0);
    if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 4,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c1_covrtInstance, 4U, 0U, 3U, (real_T)
                        c1_max_dist_sq, 400.0, -3, 4U, c1_max_dist_sq > 400.0F)))
    {
      if (c1_idx_end != (real_T)(int32_T)muDoubleScalarFloor(c1_idx_end)) {
        emlrtIntegerCheckR2012b(c1_idx_end, &c1_o_emlrtDCI, &c1_st);
      }

      c1_i28 = (int32_T)c1_idx_end;
      if ((c1_i28 < 1) || (c1_i28 > c1_x_s_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c1_i28, 1, c1_x_s_size[0], &c1_q_emlrtBCI,
          &c1_st);
      }

      c1_P_end[0] = chartInstance->c1_x_s_data[c1_i28 - 1];
      if (c1_idx_end != (real_T)(int32_T)muDoubleScalarFloor(c1_idx_end)) {
        emlrtIntegerCheckR2012b(c1_idx_end, &c1_p_emlrtDCI, &c1_st);
      }

      c1_i42 = (int32_T)c1_idx_end;
      if ((c1_i42 < 1) || (c1_i42 > c1_y_s_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c1_i42, 1, c1_y_s_size[0], &c1_r_emlrtBCI,
          &c1_st);
      }

      c1_P_end[1] = c1_y_s_data[c1_i42 - 1];
      c1_max_deviation = -1.0F;
      c1_idx_corner = -1.0;
      c1_vx = c1_P_end[0] - c1_P_start[0];
      c1_vy = c1_P_end[1] - c1_P_start[1];
      c1_f = c1_vx * c1_vx + c1_vy * c1_vy;
      c1_b_st.site = &c1_h_emlrtRSI;
      c1_b_sqrt(chartInstance, &c1_b_st, &c1_f);
      c1_len_line = c1_f + 0.001F;
      c1_c_num_pixels = c1_num_pixels;
      c1_i58 = (int32_T)c1_c_num_pixels;
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_c_num_pixels, mxDOUBLE_CLASS,
        c1_i58, &c1_j_emlrtRTEI, &c1_st);
      for (c1_i_k = 0; c1_i_k < c1_i58; c1_i_k++) {
        c1_c_k = 1.0 + (real_T)c1_i_k;
        covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 1, 1);
        if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
          emlrtIntegerCheckR2012b(c1_c_k, &c1_ib_emlrtDCI, &c1_st);
        }

        c1_i67 = (int32_T)c1_c_k;
        if ((c1_i67 < 1) || (c1_i67 > c1_x_s_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c1_i67, 1, c1_x_s_size[0],
            &c1_kb_emlrtBCI, &c1_st);
        }

        c1_px = chartInstance->c1_x_s_data[c1_i67 - 1];
        if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
          emlrtIntegerCheckR2012b(c1_c_k, &c1_jb_emlrtDCI, &c1_st);
        }

        c1_i72 = (int32_T)c1_c_k;
        if ((c1_i72 < 1) || (c1_i72 > c1_y_s_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c1_i72, 1, c1_y_s_size[0],
            &c1_lb_emlrtBCI, &c1_st);
        }

        c1_py = c1_y_s_data[c1_i72 - 1];
        c1_j_x = c1_vx * (c1_P_start[1] - c1_py) - (c1_P_start[0] - c1_px) *
          c1_vy;
        c1_k_x = c1_j_x;
        c1_l_x = c1_k_x;
        c1_cross_prod = muSingleScalarAbs(c1_l_x);
        c1_m_x = c1_cross_prod;
        c1_y = c1_len_line;
        c1_n_x = c1_m_x;
        c1_b_y = c1_y;
        c1_dist_to_line = c1_n_x / c1_b_y;
        if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 5,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 4U, 0U, 4U, (real_T)
                            c1_dist_to_line, (real_T)c1_max_deviation, -3, 4U,
                            c1_dist_to_line > c1_max_deviation))) {
          c1_max_deviation = c1_dist_to_line;
          c1_idx_corner = c1_c_k;
        }

        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 1, 0);
      c1_sel_count = 3.0;
      c1_i63 = 0;
      for (c1_i65 = 0; c1_i65 < 2; c1_i65++) {
        c1_selected_pts[c1_i63] = c1_P_start[c1_i65];
        c1_i63 += 3;
      }

      c1_is_valid_corner = false;
      memset(&c1_P_corner[0], 0, sizeof(real32_T) << 1);
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 6,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 5U, (real_T)
                          c1_max_deviation, 10.0, -3, 4U, c1_max_deviation >
                          10.0F))) {
        if (c1_idx_corner != (real_T)(int32_T)muDoubleScalarFloor(c1_idx_corner))
        {
          emlrtIntegerCheckR2012b(c1_idx_corner, &c1_lb_emlrtDCI, &c1_st);
        }

        c1_i71 = (int32_T)c1_idx_corner;
        if ((c1_i71 < 1) || (c1_i71 > c1_x_s_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c1_i71, 1, c1_x_s_size[0],
            &c1_nb_emlrtBCI, &c1_st);
        }

        c1_P_cand[0] = chartInstance->c1_x_s_data[c1_i71 - 1];
        if (c1_idx_corner != (real_T)(int32_T)muDoubleScalarFloor(c1_idx_corner))
        {
          emlrtIntegerCheckR2012b(c1_idx_corner, &c1_mb_emlrtDCI, &c1_st);
        }

        c1_i79 = (int32_T)c1_idx_corner;
        if ((c1_i79 < 1) || (c1_i79 > c1_y_s_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c1_i79, 1, c1_y_s_size[0],
            &c1_ob_emlrtBCI, &c1_st);
        }

        c1_P_cand[1] = c1_y_s_data[c1_i79 - 1];
        c1_b_st.site = &c1_i_emlrtRSI;
        c1_l_a = c1_P_cand[0] - c1_P_start[0];
        c1_c_st.site = &c1_eb_emlrtRSI;
        c1_m_a = c1_l_a;
        c1_n_a = c1_m_a;
        c1_o_a = c1_n_a;
        c1_p_a = c1_o_a;
        c1_d_c = c1_p_a * c1_p_a;
        c1_b_st.site = &c1_i_emlrtRSI;
        c1_q_a = c1_P_cand[1] - c1_P_start[1];
        c1_c_st.site = &c1_eb_emlrtRSI;
        c1_r_a = c1_q_a;
        c1_s_a = c1_r_a;
        c1_t_a = c1_s_a;
        c1_u_a = c1_t_a;
        c1_e_c = c1_u_a * c1_u_a;
        c1_d_start = c1_d_c + c1_e_c;
        c1_b_st.site = &c1_j_emlrtRSI;
        c1_v_a = c1_P_cand[0] - c1_P_end[0];
        c1_c_st.site = &c1_eb_emlrtRSI;
        c1_w_a = c1_v_a;
        c1_x_a = c1_w_a;
        c1_y_a = c1_x_a;
        c1_ab_a = c1_y_a;
        c1_f_c = c1_ab_a * c1_ab_a;
        c1_b_st.site = &c1_j_emlrtRSI;
        c1_bb_a = c1_P_cand[1] - c1_P_end[1];
        c1_c_st.site = &c1_eb_emlrtRSI;
        c1_cb_a = c1_bb_a;
        c1_db_a = c1_cb_a;
        c1_eb_a = c1_db_a;
        c1_fb_a = c1_eb_a;
        c1_g_c = c1_fb_a * c1_fb_a;
        c1_d_end = c1_f_c + c1_g_c;
        if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 0,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c1_covrtInstance, 4U, 0U, 6U,
                              (real_T)c1_d_start, 400.0, -3, 4U, c1_d_start >
                              400.0F)) && covrtEmlCondEval
            (chartInstance->c1_covrtInstance, 4U, 0, 1,
             covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance, 4U, 0U,
              7U, (real_T)c1_d_end, 400.0, -3, 4U, c1_d_end > 400.0F))) {
          covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, true);
          covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 7, true);
          c1_is_valid_corner = true;
          for (c1_i89 = 0; c1_i89 < 2; c1_i89++) {
            c1_P_corner[c1_i89] = c1_P_cand[c1_i89];
          }
        } else {
          covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 0, false);
          covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 7, false);
        }
      }

      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 8,
                         c1_is_valid_corner)) {
        c1_i70 = 0;
        for (c1_i73 = 0; c1_i73 < 2; c1_i73++) {
          c1_selected_pts[c1_i70 + 1] = c1_P_corner[c1_i73];
          c1_i70 += 3;
        }

        c1_i75 = 0;
        for (c1_i77 = 0; c1_i77 < 2; c1_i77++) {
          c1_selected_pts[c1_i75 + 2] = c1_P_end[c1_i77];
          c1_i75 += 3;
        }
      } else {
        for (c1_i69 = 0; c1_i69 < 2; c1_i69++) {
          c1_P_start[c1_i69] += c1_P_end[c1_i69];
        }

        for (c1_i74 = 0; c1_i74 < 2; c1_i74++) {
          c1_P_start[c1_i74] *= 0.5F;
        }

        c1_i76 = 0;
        for (c1_i78 = 0; c1_i78 < 2; c1_i78++) {
          c1_selected_pts[c1_i76 + 1] = c1_P_start[c1_i78];
          c1_i76 += 3;
        }

        c1_i80 = 0;
        for (c1_i81 = 0; c1_i81 < 2; c1_i81++) {
          c1_selected_pts[c1_i80 + 2] = c1_P_end[c1_i81];
          c1_i80 += 3;
        }
      }
    } else {
      c1_sel_count = 3.0;
      c1_i26 = 0;
      for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
        c1_selected_pts[c1_i26] = c1_P_start[c1_i27];
        c1_i26 += 3;
      }

      c1_i34 = 0;
      for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
        c1_selected_pts[c1_i34 + 1] = c1_P_start[c1_i36];
        c1_i34 += 3;
      }

      c1_i39 = 0;
      for (c1_i41 = 0; c1_i41 < 2; c1_i41++) {
        c1_selected_pts[c1_i39 + 2] = c1_P_start[c1_i41];
        c1_i39 += 3;
      }
    }
  }

  if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 9,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 8U, c1_sel_count, 3.0, -1, 0U, c1_sel_count == 3.0)) &&
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 10,
                     covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
        4U, 0U, 9U, (real_T)c1_selected_pts[3], (real_T)c1_selected_pts[5], -3,
        2U, c1_selected_pts[3] < c1_selected_pts[5]))) {
    for (c1_i8 = 0; c1_i8 < 6; c1_i8++) {
      c1_swap_pts[c1_i8] = c1_selected_pts[c1_i8];
    }

    c1_i9 = 0;
    for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
      c1_selected_pts[c1_i9] = c1_swap_pts[c1_i9 + 2];
      c1_i9 += 3;
    }

    c1_i12 = 0;
    for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
      c1_selected_pts[c1_i12 + 2] = c1_swap_pts[c1_i12];
      c1_i12 += 3;
    }
  }

  if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 2,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c1_covrtInstance, 4U, 0U, 10U,
                        c1_sel_count, 0.0, -1, 4U, c1_sel_count > 0.0)) &&
      covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 3,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c1_covrtInstance, 4U, 0U, 11U,
                        chartInstance->c1_prev_count, 0.0, -1, 4U,
                        chartInstance->c1_prev_count > 0.0))) {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 1, true);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 11, true);
    c1_b_sel_count = c1_sel_count;
    c1_i11 = (int32_T)c1_b_sel_count;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_b_sel_count, mxDOUBLE_CLASS,
      c1_i11, &c1_k_emlrtRTEI, &c1_st);
    for (c1_k = 0; c1_k < c1_i11; c1_k++) {
      c1_c_k = 1.0 + (real_T)c1_k;
      covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 2, 1);
      c1_min_d = 900.0F;
      c1_best_idx = -1.0;
      c1_varargin_1 = chartInstance->c1_prev_count;
      c1_x = c1_varargin_1;
      c1_b_x = c1_x;
      c1_c_x = c1_b_x;
      c1_a = c1_c_x;
      c1_d_x = c1_a;
      c1_e_x = c1_d_x;
      c1_d = c1_e_x;
      c1_i22 = (int32_T)c1_d;
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_d, mxDOUBLE_CLASS, c1_i22,
        &c1_l_emlrtRTEI, &c1_st);
      for (c1_p = 0; c1_p < c1_i22; c1_p++) {
        c1_b_p = 1.0 + (real_T)c1_p;
        covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 3, 1);
        if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 12,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 4U, 0U, 12U, c1_b_p,
                            3.0, -1, 3U, c1_b_p <= 3.0))) {
          if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
            emlrtIntegerCheckR2012b(c1_c_k, &c1_cb_emlrtDCI, &c1_st);
          }

          c1_i33 = (int32_T)c1_c_k;
          if ((c1_i33 < 1) || (c1_i33 > 3)) {
            emlrtDynamicBoundsCheckR2012b(c1_i33, 1, 3, &c1_eb_emlrtBCI, &c1_st);
          }

          if (c1_b_p != (real_T)(int32_T)muDoubleScalarFloor(c1_b_p)) {
            emlrtIntegerCheckR2012b(c1_b_p, &c1_db_emlrtDCI, &c1_st);
          }

          c1_i44 = (int32_T)c1_b_p;
          if ((c1_i44 < 1) || (c1_i44 > 10)) {
            emlrtDynamicBoundsCheckR2012b(c1_i44, 1, 10, &c1_fb_emlrtBCI, &c1_st);
          }

          c1_dx = c1_selected_pts[c1_i33 - 1] - chartInstance->
            c1_prev_pts[c1_i44 - 1];
          if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
            emlrtIntegerCheckR2012b(c1_c_k, &c1_fb_emlrtDCI, &c1_st);
          }

          c1_i50 = (int32_T)c1_c_k;
          if ((c1_i50 < 1) || (c1_i50 > 3)) {
            emlrtDynamicBoundsCheckR2012b(c1_i50, 1, 3, &c1_hb_emlrtBCI, &c1_st);
          }

          if (c1_b_p != (real_T)(int32_T)muDoubleScalarFloor(c1_b_p)) {
            emlrtIntegerCheckR2012b(c1_b_p, &c1_gb_emlrtDCI, &c1_st);
          }

          c1_i57 = (int32_T)c1_b_p;
          if ((c1_i57 < 1) || (c1_i57 > 10)) {
            emlrtDynamicBoundsCheckR2012b(c1_i57, 1, 10, &c1_ib_emlrtBCI, &c1_st);
          }

          c1_dy = c1_selected_pts[c1_i50 + 2] - chartInstance->
            c1_prev_pts[c1_i57 + 9];
          c1_dd = c1_dx * c1_dx + c1_dy * c1_dy;
          if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 13,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c1_covrtInstance, 4U, 0U, 13U,
                              (real_T)c1_dd, (real_T)c1_min_d, -3, 2U, c1_dd <
                              c1_min_d))) {
            c1_min_d = c1_dd;
            c1_best_idx = c1_b_p;
          }
        }

        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 3, 0);
      if (covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 14,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 14U,
                          c1_best_idx, -1.0, -1, 1U, c1_best_idx != -1.0))) {
        if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
          emlrtIntegerCheckR2012b(c1_c_k, &c1_v_emlrtDCI, &c1_st);
        }

        c1_i30 = (int32_T)c1_c_k;
        if ((c1_i30 < 1) || (c1_i30 > 3)) {
          emlrtDynamicBoundsCheckR2012b(c1_i30, 1, 3, &c1_x_emlrtBCI, &c1_st);
        }

        if (c1_best_idx != (real_T)(int32_T)muDoubleScalarFloor(c1_best_idx)) {
          emlrtIntegerCheckR2012b(c1_best_idx, &c1_w_emlrtDCI, &c1_st);
        }

        c1_i40 = (int32_T)c1_best_idx;
        if ((c1_i40 < 1) || (c1_i40 > 10)) {
          emlrtDynamicBoundsCheckR2012b(c1_i40, 1, 10, &c1_y_emlrtBCI, &c1_st);
        }

        if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
          emlrtIntegerCheckR2012b(c1_c_k, &c1_x_emlrtDCI, &c1_st);
        }

        c1_i48 = (int32_T)c1_c_k;
        if ((c1_i48 < 1) || (c1_i48 > 3)) {
          emlrtDynamicBoundsCheckR2012b(c1_i48, 1, 3, &c1_ab_emlrtBCI, &c1_st);
        }

        c1_selected_pts[c1_i48 - 1] = 0.7F * c1_selected_pts[c1_i30 - 1] + 0.3F *
          chartInstance->c1_prev_pts[c1_i40 - 1];
        if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
          emlrtIntegerCheckR2012b(c1_c_k, &c1_y_emlrtDCI, &c1_st);
        }

        c1_i55 = (int32_T)c1_c_k;
        if ((c1_i55 < 1) || (c1_i55 > 3)) {
          emlrtDynamicBoundsCheckR2012b(c1_i55, 1, 3, &c1_bb_emlrtBCI, &c1_st);
        }

        if (c1_best_idx != (real_T)(int32_T)muDoubleScalarFloor(c1_best_idx)) {
          emlrtIntegerCheckR2012b(c1_best_idx, &c1_ab_emlrtDCI, &c1_st);
        }

        c1_i61 = (int32_T)c1_best_idx;
        if ((c1_i61 < 1) || (c1_i61 > 10)) {
          emlrtDynamicBoundsCheckR2012b(c1_i61, 1, 10, &c1_cb_emlrtBCI, &c1_st);
        }

        if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
          emlrtIntegerCheckR2012b(c1_c_k, &c1_bb_emlrtDCI, &c1_st);
        }

        c1_i66 = (int32_T)c1_c_k;
        if ((c1_i66 < 1) || (c1_i66 > 3)) {
          emlrtDynamicBoundsCheckR2012b(c1_i66, 1, 3, &c1_db_emlrtBCI, &c1_st);
        }

        c1_selected_pts[c1_i66 + 2] = 0.7F * c1_selected_pts[c1_i55 + 2] + 0.3F *
          chartInstance->c1_prev_pts[c1_i61 + 9];
      }

      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 2, 0);
  } else {
    covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 1, false);
    covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 11, false);
  }

  memset(&c1_b_pts[0], 0, 20U * sizeof(real32_T));
  c1_c_sel_count = c1_sel_count;
  c1_i14 = (int32_T)c1_c_sel_count;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_c_sel_count, mxDOUBLE_CLASS, c1_i14,
    &c1_m_emlrtRTEI, &c1_st);
  for (c1_b_k = 0; c1_b_k < c1_i14; c1_b_k++) {
    c1_c_k = 1.0 + (real_T)c1_b_k;
    covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 4, 1);
    if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
      emlrtIntegerCheckR2012b(c1_c_k, &c1_emlrtDCI, &c1_st);
    }

    c1_i18 = (int32_T)c1_c_k;
    if ((c1_i18 < 1) || (c1_i18 > 3)) {
      emlrtDynamicBoundsCheckR2012b(c1_i18, 1, 3, &c1_c_emlrtBCI, &c1_st);
    }

    c1_e_k = c1_i18 - 1;
    if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
      emlrtIntegerCheckR2012b(c1_c_k, &c1_b_emlrtDCI, &c1_st);
    }

    c1_i21 = (int32_T)c1_c_k;
    if ((c1_i21 < 1) || (c1_i21 > 10)) {
      emlrtDynamicBoundsCheckR2012b(c1_i21, 1, 10, &c1_d_emlrtBCI, &c1_st);
    }

    c1_g_k = c1_i21 - 1;
    for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
      c1_b_pts[c1_g_k + 10 * c1_i25] = c1_selected_pts[c1_e_k + 3 * c1_i25];
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 4, 0);
  for (c1_i16 = 0; c1_i16 < 20; c1_i16++) {
    chartInstance->c1_prev_pts[c1_i16] = c1_b_pts[c1_i16];
  }

  chartInstance->c1_prev_count = c1_sel_count;
  c1_d_sel_count = c1_sel_count;
  c1_i19 = (int32_T)c1_d_sel_count;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_d_sel_count, mxDOUBLE_CLASS, c1_i19,
    &c1_n_emlrtRTEI, &c1_st);
  for (c1_d_k = 0; c1_d_k < c1_i19; c1_d_k++) {
    c1_c_k = 1.0 + (real_T)c1_d_k;
    covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 5, 1);
    if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
      emlrtIntegerCheckR2012b(c1_c_k, &c1_r_emlrtDCI, &c1_st);
    }

    c1_i24 = (int32_T)c1_c_k;
    if ((c1_i24 < 1) || (c1_i24 > 10)) {
      emlrtDynamicBoundsCheckR2012b(c1_i24, 1, 10, &c1_t_emlrtBCI, &c1_st);
    }

    c1_d1 = 2.0 * c1_c_k - 1.0;
    if (c1_d1 != (real_T)(int32_T)muDoubleScalarFloor(c1_d1)) {
      emlrtIntegerCheckR2012b(c1_d1, &c1_s_emlrtDCI, &c1_st);
    }

    c1_i32 = (int32_T)c1_d1;
    if ((c1_i32 < 1) || (c1_i32 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c1_i32, 1, 20, &c1_u_emlrtBCI, &c1_st);
    }

    c1_b_pts_vector[c1_i32 - 1] = c1_b_pts[c1_i24 - 1];
    if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
      emlrtIntegerCheckR2012b(c1_c_k, &c1_t_emlrtDCI, &c1_st);
    }

    c1_i45 = (int32_T)c1_c_k;
    if ((c1_i45 < 1) || (c1_i45 > 10)) {
      emlrtDynamicBoundsCheckR2012b(c1_i45, 1, 10, &c1_v_emlrtBCI, &c1_st);
    }

    c1_d2 = 2.0 * c1_c_k;
    if (c1_d2 != (real_T)(int32_T)muDoubleScalarFloor(c1_d2)) {
      emlrtIntegerCheckR2012b(c1_d2, &c1_u_emlrtDCI, &c1_st);
    }

    c1_i52 = (int32_T)c1_d2;
    if ((c1_i52 < 1) || (c1_i52 > 20)) {
      emlrtDynamicBoundsCheckR2012b(c1_i52, 1, 20, &c1_w_emlrtBCI, &c1_st);
    }

    c1_b_pts_vector[c1_i52 - 1] = c1_b_pts[c1_i45 + 9];
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 5, 0);
  memset(&c1_skel_base[0], 0, 19200U * sizeof(boolean_T));
  memset(&c1_endpoints_img[0], 0, 19200U * sizeof(boolean_T));
  c1_e_sel_count = c1_sel_count;
  c1_i23 = (int32_T)c1_e_sel_count;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, c1_e_sel_count, mxDOUBLE_CLASS, c1_i23,
    &c1_o_emlrtRTEI, &c1_st);
  for (c1_h_k = 0; c1_h_k < c1_i23; c1_h_k++) {
    c1_c_k = 1.0 + (real_T)c1_h_k;
    covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 6, 1);
    if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
      emlrtIntegerCheckR2012b(c1_c_k, &c1_eb_emlrtDCI, &c1_st);
    }

    c1_i37 = (int32_T)c1_c_k;
    if ((c1_i37 < 1) || (c1_i37 > 10)) {
      emlrtDynamicBoundsCheckR2012b(c1_i37, 1, 10, &c1_gb_emlrtBCI, &c1_st);
    }

    c1_f_x = c1_b_pts[c1_i37 - 1];
    c1_g_x = c1_f_x;
    c1_c = c1_g_x;
    c1_c = muSingleScalarRound(c1_c);
    if (c1_c_k != (real_T)(int32_T)muDoubleScalarFloor(c1_c_k)) {
      emlrtIntegerCheckR2012b(c1_c_k, &c1_kb_emlrtDCI, &c1_st);
    }

    c1_i49 = (int32_T)c1_c_k;
    if ((c1_i49 < 1) || (c1_i49 > 10)) {
      emlrtDynamicBoundsCheckR2012b(c1_i49, 1, 10, &c1_mb_emlrtBCI, &c1_st);
    }

    c1_h_x = c1_b_pts[c1_i49 + 9];
    c1_i_x = c1_h_x;
    c1_r = c1_i_x;
    c1_r = muSingleScalarRound(c1_r);
    if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 4,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c1_covrtInstance, 4U, 0U, 15U, (real_T)
                          c1_c, 1.0, -1, 5U, c1_c >= 1.0F)) && covrtEmlCondEval
        (chartInstance->c1_covrtInstance, 4U, 0, 5, covrtRelationalopUpdateFcn
         (chartInstance->c1_covrtInstance, 4U, 0U, 16U, (real_T)c1_c, 160.0, -1,
          3U, c1_c <= 160.0F)) && covrtEmlCondEval
        (chartInstance->c1_covrtInstance, 4U, 0, 6, covrtRelationalopUpdateFcn
         (chartInstance->c1_covrtInstance, 4U, 0U, 17U, (real_T)c1_r, 1.0, -1,
          5U, c1_r >= 1.0F)) && covrtEmlCondEval(chartInstance->c1_covrtInstance,
         4U, 0, 7, covrtRelationalopUpdateFcn(chartInstance->c1_covrtInstance,
          4U, 0U, 18U, (real_T)c1_r, 120.0, -1, 3U, c1_r <= 120.0F))) {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 2, true);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 15, true);
      c1_d3 = c1_r;
      if (c1_d3 != (real_T)(int32_T)muDoubleScalarFloor(c1_d3)) {
        emlrtIntegerCheckR2012b(c1_d3, &c1_c_emlrtDCI, &c1_st);
      }

      c1_i64 = (int32_T)(real32_T)c1_d3;
      if ((c1_i64 < 1) || (c1_i64 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c1_i64, 1, 120, &c1_e_emlrtBCI, &c1_st);
      }

      c1_d4 = c1_c;
      if (c1_d4 != (real_T)(int32_T)muDoubleScalarFloor(c1_d4)) {
        emlrtIntegerCheckR2012b(c1_d4, &c1_d_emlrtDCI, &c1_st);
      }

      c1_i68 = (int32_T)(real32_T)c1_d4;
      if ((c1_i68 < 1) || (c1_i68 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c1_i68, 1, 160, &c1_f_emlrtBCI, &c1_st);
      }

      c1_endpoints_img[((int32_T)(real32_T)c1_i64 + 120 * ((int32_T)(real32_T)
        c1_i68 - 1)) - 1] = true;
      if (covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 8,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 4U, 0U, 19U,
                            (real_T)c1_c, 1.0, -1, 4U, c1_c > 1.0F)) &&
          covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 9,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 4U, 0U, 20U,
                            (real_T)c1_c, 160.0, -1, 2U, c1_c < 160.0F)) &&
          covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 10,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 4U, 0U, 21U,
                            (real_T)c1_r, 1.0, -1, 4U, c1_r > 1.0F)) &&
          covrtEmlCondEval(chartInstance->c1_covrtInstance, 4U, 0, 11,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c1_covrtInstance, 4U, 0U, 22U,
                            (real_T)c1_r, 120.0, -1, 2U, c1_r < 120.0F))) {
        covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 3, true);
        covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 16, true);
        c1_d5 = c1_r - 1.0F;
        if (c1_d5 != (real_T)(int32_T)muDoubleScalarFloor(c1_d5)) {
          emlrtIntegerCheckR2012b(c1_d5, &c1_e_emlrtDCI, &c1_st);
        }

        c1_i82 = (int32_T)(real32_T)c1_d5;
        if ((c1_i82 < 1) || (c1_i82 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i82, 1, 120, &c1_g_emlrtBCI, &c1_st);
        }

        c1_d6 = c1_c;
        if (c1_d6 != (real_T)(int32_T)muDoubleScalarFloor(c1_d6)) {
          emlrtIntegerCheckR2012b(c1_d6, &c1_f_emlrtDCI, &c1_st);
        }

        c1_i83 = (int32_T)(real32_T)c1_d6;
        if ((c1_i83 < 1) || (c1_i83 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i83, 1, 160, &c1_h_emlrtBCI, &c1_st);
        }

        c1_endpoints_img[((int32_T)(real32_T)c1_i82 + 120 * ((int32_T)(real32_T)
          c1_i83 - 1)) - 1] = true;
        c1_d7 = c1_r + 1.0F;
        if (c1_d7 != (real_T)(int32_T)muDoubleScalarFloor(c1_d7)) {
          emlrtIntegerCheckR2012b(c1_d7, &c1_g_emlrtDCI, &c1_st);
        }

        c1_i84 = (int32_T)(real32_T)c1_d7;
        if ((c1_i84 < 1) || (c1_i84 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i84, 1, 120, &c1_i_emlrtBCI, &c1_st);
        }

        c1_d8 = c1_c;
        if (c1_d8 != (real_T)(int32_T)muDoubleScalarFloor(c1_d8)) {
          emlrtIntegerCheckR2012b(c1_d8, &c1_h_emlrtDCI, &c1_st);
        }

        c1_i85 = (int32_T)(real32_T)c1_d8;
        if ((c1_i85 < 1) || (c1_i85 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i85, 1, 160, &c1_j_emlrtBCI, &c1_st);
        }

        c1_endpoints_img[((int32_T)(real32_T)c1_i84 + 120 * ((int32_T)(real32_T)
          c1_i85 - 1)) - 1] = true;
        c1_d9 = c1_r;
        if (c1_d9 != (real_T)(int32_T)muDoubleScalarFloor(c1_d9)) {
          emlrtIntegerCheckR2012b(c1_d9, &c1_i_emlrtDCI, &c1_st);
        }

        c1_i86 = (int32_T)(real32_T)c1_d9;
        if ((c1_i86 < 1) || (c1_i86 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i86, 1, 120, &c1_k_emlrtBCI, &c1_st);
        }

        c1_d10 = c1_c - 1.0F;
        if (c1_d10 != (real_T)(int32_T)muDoubleScalarFloor(c1_d10)) {
          emlrtIntegerCheckR2012b(c1_d10, &c1_j_emlrtDCI, &c1_st);
        }

        c1_i87 = (int32_T)(real32_T)c1_d10;
        if ((c1_i87 < 1) || (c1_i87 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i87, 1, 160, &c1_l_emlrtBCI, &c1_st);
        }

        c1_endpoints_img[((int32_T)(real32_T)c1_i86 + 120 * ((int32_T)(real32_T)
          c1_i87 - 1)) - 1] = true;
        c1_d11 = c1_r;
        if (c1_d11 != (real_T)(int32_T)muDoubleScalarFloor(c1_d11)) {
          emlrtIntegerCheckR2012b(c1_d11, &c1_k_emlrtDCI, &c1_st);
        }

        c1_i88 = (int32_T)(real32_T)c1_d11;
        if ((c1_i88 < 1) || (c1_i88 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c1_i88, 1, 120, &c1_m_emlrtBCI, &c1_st);
        }

        c1_d12 = c1_c + 1.0F;
        if (c1_d12 != (real_T)(int32_T)muDoubleScalarFloor(c1_d12)) {
          emlrtIntegerCheckR2012b(c1_d12, &c1_l_emlrtDCI, &c1_st);
        }

        c1_i90 = (int32_T)(real32_T)c1_d12;
        if ((c1_i90 < 1) || (c1_i90 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c1_i90, 1, 160, &c1_n_emlrtBCI, &c1_st);
        }

        c1_endpoints_img[((int32_T)(real32_T)c1_i88 + 120 * ((int32_T)(real32_T)
          c1_i90 - 1)) - 1] = true;
      } else {
        covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 3, false);
        covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 16, false);
      }
    } else {
      covrtEmlMcdcEval(chartInstance->c1_covrtInstance, 4U, 0, 2, false);
      covrtEmlIfEval(chartInstance->c1_covrtInstance, 4U, 0, 15, false);
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c1_covrtInstance, 4U, 0, 6, 0);
  for (c1_i29 = 0; c1_i29 < 19200; c1_i29++) {
    (*chartInstance->c1_out)[c1_i29] = chartInstance->c1_binaryImage[c1_i29];
  }

  for (c1_i35 = 0; c1_i35 < 20; c1_i35++) {
    (*chartInstance->c1_pts_vector)[c1_i35] = c1_b_pts_vector[c1_i35];
  }

  for (c1_i38 = 0; c1_i38 < 20; c1_i38++) {
    (*chartInstance->c1_pts)[c1_i38] = c1_b_pts[c1_i38];
  }

  for (c1_i43 = 0; c1_i43 < 19200; c1_i43++) {
    (*chartInstance->c1_out_2)[c1_i43] = c1_points_cloud_img[c1_i43];
  }

  for (c1_i46 = 0; c1_i46 < 19200; c1_i46++) {
    (*chartInstance->c1_out_3)[c1_i46] = c1_endpoints_img[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 19200; c1_i47++) {
    (*chartInstance->c1_out_4)[c1_i47] = c1_skel_base[c1_i47];
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 1U) != 0U) {
    for (c1_i51 = 0; c1_i51 < 19200; c1_i51++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 1U, (*
        chartInstance->c1_out)[c1_i51]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 2U) != 0U) {
    for (c1_i54 = 0; c1_i54 < 20; c1_i54++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 2U,
        (real_T)(*chartInstance->c1_pts_vector)[c1_i54]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 3U) != 0U) {
    for (c1_i56 = 0; c1_i56 < 20; c1_i56++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 3U,
        (real_T)(*chartInstance->c1_pts)[c1_i56]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 4U) != 0U) {
    for (c1_i59 = 0; c1_i59 < 19200; c1_i59++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 4U,
        (real_T)(*chartInstance->c1_out_2)[c1_i59]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 5U) != 0U) {
    for (c1_i60 = 0; c1_i60 < 19200; c1_i60++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 5U,
        (real_T)(*chartInstance->c1_out_3)[c1_i60]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c1_covrtInstance, 6U) != 0U) {
    for (c1_i62 = 0; c1_i62 < 19200; c1_i62++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c1_covrtInstance, 6U,
        (real_T)(*chartInstance->c1_out_4)[c1_i62]);
    }
  }
}

static void ext_mode_exec_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_update_jit_animation_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_do_animation_call_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_e_y = NULL;
  const mxArray *c1_f_y = NULL;
  const mxArray *c1_g_y = NULL;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(8, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_out, 0, 0U, 1, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", *chartInstance->c1_out_2, 11, 0U, 1,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", *chartInstance->c1_out_3, 11, 0U, 1,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", *chartInstance->c1_out_4, 11, 0U, 1,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", *chartInstance->c1_pts, 1, 0U, 1, 0U,
    2, 10, 2), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", *chartInstance->c1_pts_vector, 1, 0U,
    1, 0U, 2, 1, 20), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_h_y = NULL;
  if (!chartInstance->c1_prev_count_not_empty) {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", &chartInstance->c1_prev_count, 0,
      0U, 0, 0U, 0), false);
  }

  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_i_y = NULL;
  if (!chartInstance->c1_prev_pts_not_empty) {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", chartInstance->c1_prev_pts, 1, 0U,
      1, 0U, 2, 10, 2), false);
  }

  sf_mex_setcell(c1_y, 7, c1_i_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_flightControlSystem
  (SFc1_flightControlSystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  real32_T c1_fv[20];
  real32_T c1_fv1[20];
  real32_T c1_fv2[20];
  boolean_T c1_bv[19200];
  boolean_T c1_bv1[19200];
  boolean_T c1_bv2[19200];
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "out",
                      chartInstance->c1_dv);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    (*chartInstance->c1_out)[c1_i] = chartInstance->c1_dv[c1_i];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "out_2", c1_bv);
  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    (*chartInstance->c1_out_2)[c1_i1] = c1_bv[c1_i1];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "out_3", c1_bv1);
  for (c1_i2 = 0; c1_i2 < 19200; c1_i2++) {
    (*chartInstance->c1_out_3)[c1_i2] = c1_bv1[c1_i2];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                        "out_4", c1_bv2);
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    (*chartInstance->c1_out_4)[c1_i3] = c1_bv2[c1_i3];
  }

  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
                        "pts", c1_fv);
  for (c1_i4 = 0; c1_i4 < 20; c1_i4++) {
    (*chartInstance->c1_pts)[c1_i4] = c1_fv[c1_i4];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "pts_vector", c1_fv1);
  for (c1_i5 = 0; c1_i5 < 20; c1_i5++) {
    (*chartInstance->c1_pts_vector)[c1_i5] = c1_fv1[c1_i5];
  }

  chartInstance->c1_prev_count = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "prev_count",
    &chartInstance->c1_prev_count_not_empty);
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)),
                        "prev_pts", &chartInstance->c1_prev_pts_not_empty,
                        c1_fv2);
  for (c1_i6 = 0; c1_i6 < 20; c1_i6++) {
    chartInstance->c1_prev_pts[c1_i6] = c1_fv2[c1_i6];
  }

  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void c1_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  real_T c1_bwin[19200], boolean_T c1_bw[19200])
{
  static boolean_T c1_lut1[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  static boolean_T c1_lut2[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, false, false, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, false, false, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  static boolean_T c1_lut3[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, false, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  static boolean_T c1_lut4[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, false, false, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  static boolean_T c1_lut5[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, false, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, false, true,
    true, true, true, true, true, true };

  static boolean_T c1_lut6[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, false, false,
    true, true, false, false, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, false, false,
    true, true, false, false, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  static boolean_T c1_lut7[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    false, true, false, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    false, true, false, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  static boolean_T c1_lut8[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, false, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, false, true, true, true, true, true,
    true, true, true, true, true, true };

  real_T c1_sizeIn[2];
  real_T c1_b_k;
  real_T c1_c_i;
  real_T c1_d_i;
  int32_T c1_b_i;
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_k;
  boolean_T c1_in[19200];
  boolean_T c1_last_aout[19200];
  boolean_T c1_lut[512];
  boolean_T c1_b_p;
  boolean_T c1_c_p;
  boolean_T c1_exitg1;
  boolean_T c1_p;
  boolean_T c1_x1;
  boolean_T c1_x2;
  (void)chartInstance;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_bw[c1_i] = (c1_bwin[c1_i] != 0.0);
  }

  do {
    for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
      c1_last_aout[c1_i1] = c1_bw[c1_i1];
    }

    for (c1_b_i = 0; c1_b_i < 8; c1_b_i++) {
      c1_c_i = (real_T)c1_b_i + 1.0;
      c1_d_i = c1_c_i;
      switch ((int32_T)c1_d_i) {
       case 1:
        for (c1_i3 = 0; c1_i3 < 512; c1_i3++) {
          c1_lut[c1_i3] = c1_lut1[c1_i3];
        }
        break;

       case 2:
        for (c1_i4 = 0; c1_i4 < 512; c1_i4++) {
          c1_lut[c1_i4] = c1_lut2[c1_i4];
        }
        break;

       case 3:
        for (c1_i5 = 0; c1_i5 < 512; c1_i5++) {
          c1_lut[c1_i5] = c1_lut3[c1_i5];
        }
        break;

       case 4:
        for (c1_i6 = 0; c1_i6 < 512; c1_i6++) {
          c1_lut[c1_i6] = c1_lut4[c1_i6];
        }
        break;

       case 5:
        for (c1_i7 = 0; c1_i7 < 512; c1_i7++) {
          c1_lut[c1_i7] = c1_lut5[c1_i7];
        }
        break;

       case 6:
        for (c1_i8 = 0; c1_i8 < 512; c1_i8++) {
          c1_lut[c1_i8] = c1_lut6[c1_i8];
        }
        break;

       case 7:
        for (c1_i9 = 0; c1_i9 < 512; c1_i9++) {
          c1_lut[c1_i9] = c1_lut7[c1_i9];
        }
        break;

       default:
        for (c1_i2 = 0; c1_i2 < 512; c1_i2++) {
          c1_lut[c1_i2] = c1_lut8[c1_i2];
        }
        break;
      }

      for (c1_i10 = 0; c1_i10 < 19200; c1_i10++) {
        c1_in[c1_i10] = c1_bw[c1_i10];
      }

      for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
        c1_sizeIn[c1_i11] = 120.0 + 40.0 * (real_T)c1_i11;
      }

      bwlookup_tbb_boolean(&c1_in[0], &c1_sizeIn[0], 2.0, &c1_lut[0], 512.0,
                           &c1_bw[0]);
    }

    c1_p = false;
    c1_b_p = true;
    c1_k = 0;
    c1_exitg1 = false;
    while ((!c1_exitg1) && (c1_k < 19200)) {
      c1_b_k = (real_T)c1_k + 1.0;
      c1_x1 = c1_last_aout[(int32_T)c1_b_k - 1];
      c1_x2 = c1_bw[(int32_T)c1_b_k - 1];
      c1_c_p = ((int32_T)c1_x1 == (int32_T)c1_x2);
      if (!c1_c_p) {
        c1_b_p = false;
        c1_exitg1 = true;
      } else {
        c1_k++;
      }
    }

    if (c1_b_p) {
      c1_p = true;
    }
  } while (!c1_p);
}

static void c1_b_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200])
{
  static real_T c1_b_lut[512] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
    1.0, 1.0, 2.0, 1.0, 2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0, 1.0, 2.0,
    1.0, 1.0, 2.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0,
    2.0, 3.0, 2.0, 2.0, 1.0, 1.0, 2.0, 1.0, 2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 3.0,
    3.0, 3.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 3.0, 3.0, 3.0,
    2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0, 2.0, 3.0, 3.0, 4.0, 3.0, 3.0,
    3.0, 3.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 2.0, 1.0, 1.0, 2.0,
    1.0, 2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0, 2.0, 2.0,
    2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0,
    2.0, 2.0, 2.0, 3.0, 2.0, 3.0, 3.0, 3.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0, 1.0,
    2.0, 1.0, 1.0, 2.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 3.0, 3.0,
    3.0, 3.0, 4.0, 3.0, 3.0, 2.0, 2.0, 3.0, 2.0, 3.0, 3.0, 3.0, 2.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0,
    3.0, 3.0, 3.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 3.0, 3.0,
    3.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0, 1.0, 2.0, 1.0, 1.0, 2.0, 2.0, 3.0, 2.0,
    2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 2.0, 2.0, 1.0, 1.0,
    2.0, 1.0, 2.0, 2.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 2.0, 2.0, 1.0, 2.0, 1.0, 1.0,
    1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.0 };

  static boolean_T c1_c_lut[512] = { false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true };

  static boolean_T c1_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, true, true, true, false, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    false, true, true, true, false, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, false, true, true, true, false,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, true, true, true,
    false, true, true, true, true, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true };

  real_T c1_sizeIn[2];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  boolean_T c1_C[19200];
  boolean_T c1_E[19200];
  boolean_T c1_Vp[19200];
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_bw[c1_i] = c1_bwin[c1_i];
  }

  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_sizeIn[c1_i1] = 120.0 + 40.0 * (real_T)c1_i1;
  }

  bwlookup_tbb_boolean(&c1_bw[0], &c1_sizeIn[0], 2.0, &c1_lut[0], 512.0, &c1_C[0]);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_sizeIn[c1_i2] = 120.0 + 40.0 * (real_T)c1_i2;
  }

  bwlookup_tbb_real64(&c1_bw[0], &c1_sizeIn[0], 2.0, &c1_b_lut[0], 512.0,
                      &chartInstance->c1_B[0]);
  for (c1_i3 = 0; c1_i3 < 19200; c1_i3++) {
    c1_E[c1_i3] = (chartInstance->c1_B[c1_i3] == 1.0);
  }

  for (c1_i4 = 0; c1_i4 < 19200; c1_i4++) {
    chartInstance->c1_FC[c1_i4] = (real_T)!c1_E[c1_i4] * (real_T)c1_C[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 19200; c1_i5++) {
    c1_Vp[c1_i5] = (chartInstance->c1_B[c1_i5] == 2.0);
  }

  for (c1_i6 = 0; c1_i6 < 19200; c1_i6++) {
    c1_C[c1_i6] = !c1_E[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 19200; c1_i7++) {
    c1_Vp[c1_i7] = (c1_Vp[c1_i7] && c1_C[c1_i7]);
  }

  for (c1_i8 = 0; c1_i8 < 19200; c1_i8++) {
    c1_C[c1_i8] = (chartInstance->c1_B[c1_i8] > 2.0);
  }

  for (c1_i9 = 0; c1_i9 < 19200; c1_i9++) {
    c1_E[c1_i9] = !c1_E[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 19200; c1_i10++) {
    c1_C[c1_i10] = (c1_C[c1_i10] && c1_E[c1_i10]);
  }

  for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
    c1_sizeIn[c1_i11] = 120.0 + 40.0 * (real_T)c1_i11;
  }

  bwlookup_tbb_boolean(&c1_C[0], &c1_sizeIn[0], 2.0, &c1_c_lut[0], 512.0, &c1_E
                       [0]);
  for (c1_i12 = 0; c1_i12 < 19200; c1_i12++) {
    c1_C[c1_i12] = (chartInstance->c1_FC[c1_i12] != 0.0);
  }

  for (c1_i13 = 0; c1_i13 < 19200; c1_i13++) {
    c1_C[c1_i13] = (c1_C[c1_i13] && c1_Vp[c1_i13]);
  }

  for (c1_i14 = 0; c1_i14 < 19200; c1_i14++) {
    c1_C[c1_i14] = (c1_C[c1_i14] && c1_E[c1_i14]);
  }

  for (c1_i15 = 0; c1_i15 < 19200; c1_i15++) {
    c1_bw[c1_i15] = (chartInstance->c1_FC[c1_i15] != 0.0);
  }

  for (c1_i16 = 0; c1_i16 < 19200; c1_i16++) {
    c1_C[c1_i16] = !c1_C[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 19200; c1_i17++) {
    c1_bw[c1_i17] = (c1_bw[c1_i17] && c1_C[c1_i17]);
  }
}

static void c1_eml_find(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_x[19200], int32_T c1_i_data[], int32_T c1_i_size[1], int32_T
  c1_j_data[], int32_T c1_j_size[1])
{
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_idx;
  int32_T c1_ii;
  int32_T c1_jj;
  boolean_T c1_b;
  boolean_T c1_b1;
  boolean_T c1_exitg1;
  boolean_T c1_guard1;
  c1_idx = 0;
  c1_ii = 1;
  c1_jj = 1;
  c1_exitg1 = false;
  while ((!c1_exitg1) && (c1_jj <= 160)) {
    c1_guard1 = false;
    if (c1_x[(c1_ii + 120 * (c1_jj - 1)) - 1]) {
      c1_idx++;
      c1_i_data[c1_idx - 1] = c1_ii;
      c1_j_data[c1_idx - 1] = c1_jj;
      if (c1_idx >= 19200) {
        c1_exitg1 = true;
      } else {
        c1_guard1 = true;
      }
    } else {
      c1_guard1 = true;
    }

    if (c1_guard1) {
      c1_ii++;
      if (c1_ii > 120) {
        c1_ii = 1;
        c1_jj++;
      }
    }
  }

  c1_b = (c1_idx < 1);
  if (c1_b) {
    c1_i = 0;
  } else {
    c1_i = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_i_size[0] = c1_i;
  c1_b1 = (c1_idx < 1);
  if (c1_b1) {
    c1_i1 = 0;
  } else {
    c1_i1 = c1_idx;
  }

  c1_indexShapeCheck(chartInstance);
  c1_j_size[0] = c1_i1;
  c1_indexShapeCheck(chartInstance);
}

static void c1_indexShapeCheck(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_c_bwmorph(SFc1_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c1_bwin[19200], boolean_T c1_bw[19200])
{
  static boolean_T c1_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, false, true, true, true, true, false, true, false,
    false, false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, false,
    false, true, false, true, true, false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, false, false,
    false, false, false, false, true, true, false, true, false, false, false,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, false, false, false, false, false, false, false,
    true, true, false, true, false, false, false, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, false, false, false, true, false, true, true, false, false, false,
    false, false, false, false, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, false, false,
    true, false, true, true, false, false, false, false, false, false, false,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, false,
    false, false, false, true, true, false, true, false, false, false, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, false, false, false, true, false,
    true, true, true, true, false, true, true, true, true, false };

  real_T c1_sizeIn[2];
  int32_T c1_i;
  int32_T c1_i1;
  int32_T c1_i2;
  boolean_T c1_in[19200];
  (void)chartInstance;
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_bw[c1_i] = c1_bwin[c1_i];
  }

  for (c1_i1 = 0; c1_i1 < 19200; c1_i1++) {
    c1_in[c1_i1] = c1_bw[c1_i1];
  }

  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_sizeIn[c1_i2] = 120.0 + 40.0 * (real_T)c1_i2;
  }

  bwlookup_tbb_boolean(&c1_in[0], &c1_sizeIn[0], 2.0, &c1_lut[0], 512.0, &c1_bw
                       [0]);
}

static void c1_maximum(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_x_data[], int32_T c1_x_size[1], real32_T *
  c1_ex, int32_T *c1_idx)
{
  static char_T c1_cv1[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  static char_T c1_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_a;
  int32_T c1_b_idx;
  int32_T c1_b_last;
  int32_T c1_c;
  int32_T c1_c_idx;
  int32_T c1_d_idx;
  int32_T c1_k;
  int32_T c1_last;
  int32_T c1_nx;
  real32_T c1_b_ex;
  real32_T c1_c_ex;
  real32_T c1_d_ex;
  boolean_T c1_b;
  (void)chartInstance;
  c1_st.prev = c1_sp;
  c1_st.tls = c1_sp->tls;
  c1_st.site = &c1_cb_emlrtRSI;
  if ((c1_x_size[0] == 1) || (c1_x_size[0] != 1)) {
    c1_b = true;
  } else {
    c1_b = false;
  }

  if (!c1_b) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c1_st, &c1_b_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_c_y)));
  }

  if (c1_x_size[0] < 1) {
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c1_d_y = NULL;
    sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c1_st, &c1_c_emlrtMCI, "error", 0U, 2U, 14, c1_b_y, 14,
                sf_mex_call(&c1_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c1_st, NULL, "message", 1U, 1U, 14, c1_d_y)));
  }

  c1_last = c1_x_size[0] - 1;
  c1_a = c1_last;
  c1_c = (uint16_T)c1_a + 1;
  c1_nx = c1_c;
  if (c1_nx <= 2) {
    if (c1_nx == 1) {
      c1_c_ex = c1_x_data[0];
      c1_c_idx = 1;
    } else if (c1_x_data[0] < c1_x_data[c1_last]) {
      c1_c_ex = c1_x_data[c1_last];
      c1_c_idx = c1_last + 1;
    } else {
      c1_c_ex = c1_x_data[0];
      c1_c_idx = 1;
    }
  } else {
    c1_b_last = c1_last + 1;
    c1_b_ex = c1_x_data[0];
    c1_b_idx = 1;
    for (c1_k = 2; c1_k <= c1_b_last; c1_k++) {
      if (c1_b_ex < c1_x_data[c1_k - 1]) {
        c1_b_ex = c1_x_data[c1_k - 1];
        c1_b_idx = c1_k;
      }
    }

    c1_c_ex = c1_b_ex;
    c1_c_idx = c1_b_idx;
  }

  c1_d_ex = c1_c_ex;
  c1_d_idx = c1_c_idx;
  *c1_ex = c1_d_ex;
  *c1_idx = c1_d_idx;
}

static real32_T c1_sqrt(SFc1_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c1_sp, real32_T c1_x)
{
  real32_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, c1_sp, &c1_b_x);
  return c1_b_x;
}

const mxArray *sf_c1_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier, real_T
  c1_y[19200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_b_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[19200])
{
  int32_T c1_i;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), chartInstance->c1_b_dv, 1, 0, 0U,
                1, 0U, 2, 120, 160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_y[c1_i] = chartInstance->c1_b_dv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T c1_y[19200])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_d_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T c1_y[19200])
{
  int32_T c1_i;
  boolean_T c1_bv[19200];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c1_i = 0; c1_i < 19200; c1_i++) {
    c1_y[c1_i] = c1_bv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  real32_T c1_y[20])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_f_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[20])
{
  int32_T c1_i;
  real32_T c1_fv[20];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv, 0, 1, 0U, 1, 0U, 2, 10, 2);
  for (c1_i = 0; c1_i < 20; c1_i++) {
    c1_y[c1_i] = c1_fv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  real32_T c1_y[20])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_h_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real32_T c1_y[20])
{
  int32_T c1_i;
  real32_T c1_fv[20];
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv, 0, 1, 0U, 1, 0U, 2, 1, 20);
  for (c1_i = 0; c1_i < 20; c1_i++) {
    c1_y[c1_i] = c1_fv[c1_i];
  }

  sf_mex_destroy(&c1_u);
}

static real_T c1_i_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T *c1_svPtr)
{
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
    c1_svPtr);
  sf_mex_destroy(&c1_nullptr);
  return c1_y;
}

static real_T c1_j_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr)
{
  real_T c1_d;
  real_T c1_y;
  (void)chartInstance;
  if (mxIsEmpty(c1_u)) {
    *c1_svPtr = false;
  } else {
    *c1_svPtr = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_k_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_nullptr, const char_T *c1_identifier,
  boolean_T *c1_svPtr, real32_T c1_y[20])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char_T *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nullptr), &c1_thisId,
                        c1_svPtr, c1_y);
  sf_mex_destroy(&c1_nullptr);
}

static void c1_l_emlrt_marshallIn(SFc1_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  boolean_T *c1_svPtr, real32_T c1_y[20])
{
  int32_T c1_i;
  real32_T c1_fv[20];
  (void)chartInstance;
  if (mxIsEmpty(c1_u)) {
    *c1_svPtr = false;
  } else {
    *c1_svPtr = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_fv, 0, 1, 0U, 1, 0U, 2, 10,
                  2);
    for (c1_i = 0; c1_i < 20; c1_i++) {
      c1_y[c1_i] = c1_fv[c1_i];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sqrt(SFc1_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c1_sp, real32_T *c1_x)
{
  static char_T c1_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c1_cv1[4] = { 's', 'q', 'r', 't' };

  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_y = NULL;
  real32_T c1_b_x;
  boolean_T c1_b_p;
  boolean_T c1_p;
  (void)chartInstance;
  c1_b_x = *c1_x;
  if (c1_b_x < 0.0F) {
    c1_p = true;
  } else {
    c1_p = false;
  }

  c1_b_p = c1_p;
  if (c1_b_p) {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_cv1, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c1_sp, &c1_f_emlrtMCI, "error", 0U, 2U, 14, c1_y, 14,
                sf_mex_call(c1_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c1_sp, NULL, "message", 1U, 2U, 14, c1_b_y, 14, c1_c_y)));
  }

  *c1_x = muSingleScalarSqrt(*c1_x);
}

static void init_dsm_address_info(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c1_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_out = (real_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_b_binaryImage = (real_T (*)[19200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c1_pts_vector = (real32_T (*)[20])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_pts = (real32_T (*)[20])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_out_2 = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_out_3 = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_out_4 = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c1_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2892683215U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3427227229U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4188015390U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(33381198U);
}

mxArray *sf_c1_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c1_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("bwlookup_tbb_boolean");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNrNVMsKgkAUvVqGtQg/wWWriB7Urtm66BtMzCAyFRuj/rJP6RO6OpY2DAVO4AwMl3PhXM+Z4wx"
    "ozgZwDXGvTIAeViygA1tGibVaZf3uG9u46S0J8v459Z0d1sg7FdjLrk60j9l8qOb3BPO12vx+2W"
    "frsZbjj0nOn9T4XQG/U+NbiOKMFrrf59Oa/jnh+SL9xod+htGDOy31t+9jIeVjpoyPpZSPuTI+R"
    "o3uRULPiuifFPrJD/0DLoccowf3Evg0Tisf8n4sIsdn32/kJw0urh9nEa3m3OH7e65x77le4pwT"
    "wgESgR6RH53zY73M2CEp6vb0l3NRJZ9f997k8jFf+eBPp0QucGS5QPi3XJ5xvD5h"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sWFlgouwxZB2SxTz2TaVFHB";
}

static void sf_opaque_initialize_c1_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_flightControlSystem(void *chartInstanceVar)
{
  enable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_flightControlSystem(void *chartInstanceVar)
{
  disable_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c1_flightControlSystem
    ((SFc1_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c1_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c1_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc1_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c1_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c1_flightControlSystem((SFc1_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_flightControlSystem
      ((SFc1_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c1_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [23] = {
    "eNrdWU1vG0UYHqdp5FalSi/AAUGPvYDSpBU9VODEH9RSQiLspFIvYbL72jvK7Mx2PvzR38LP4AA",
    "/gAsnLkj8AJCQuHDkBu+s165ZL8nuOihuV1qv310/835/zJpU2gcEj7t4Rh8SsoHXKp5rZHLcTO",
    "jK3Dm5v06eJvTRbUK8gCrTFj1Jih+e9KEPomN7PTYqiBU2PKKKhroEX0FD+Aq05NYwKYoJz0QPF",
    "AgPF4ikMoX4ahZazsR5ywrPcdbPA+YFnUBa7u/hgtQ/FHz8X3wja46QY4Mp8EwLwDeBkrYftDjt",
    "X2wFZYb1ALxzbcPCttJgOjZyquoDyw2LODRH4LWFNhStoC/Rt2OogboZFY4QpjtTtAwjzqjIb+u",
    "A6g5EGB0GjiMfPw+tQevl5Iv8zpigRipGeTPkdRfhObFHHOU8wLDmhe1sQtOAM9vvM9F31lU2BI",
    "H6Y5zksFWvLgegaB8ORcEcdNo1R7GDZ3GZPwfbLixL5aANJ17RpbAx3+YALaRL8m15ok4518WwX",
    "RntwwB4zL9BDS2BnfAvANaa+V15QpXLgoKZZAV7aSHB1qXwWX4PD1KouOB+icUzB5yFLqTARzPP",
    "RJ8tdFlMWm1kWMc0auzv5+S3iG0LA6pHPchd+xRlGlDgOK4K8vWZpmfcodFKJtYy9wogSkOJ7ln",
    "RGEp1jjYuWmRf28plQjE0+H1ogIG4YDQxuk8otzllDjVWOBcexxorVjG+iHX5UwrsUS8A3/UTxu",
    "EAtFtA567P2Ed2UdsBM+MGaE+xKG8mWQ0+NhJnpe44gmNxLuRQtJQMO8lEcEFcAWDVoEpgW9jDt",
    "qTGLRQ+n9QKXnZdZJUZz0JqOD1zsfEFCOwsTlfXCamHWdUUOLqhQMtgO+wVtnahmTY4To2bcQ74",
    "8Tz6fqXYPHovoXdmudTWXYWeotiGBU5Ku2fxsAddFkJ8o0NxppiQyeH4bpHXfG+tXcx3Db9VSuL",
    "Ikrhnc7j1DPu8O4fbTGjv4WmPs37girBRknfGaPdwUY47OeydJX8aRxZwr+08vT6Yw1cy+JK56z",
    "L+qc3h3knxWU/hNhKbffvNj3//8F31+1+f/vbzk8a9P5bh/3u1WDzfTegPpvPZrIMNFop8nnh4L",
    "xUPjtbPW7wv7XD0Ym+7M+q+2u7Sk9azvXi9J5fIW03JO6Xv42mwwMX1UnltP9lrOZrayR4gXn9O",
    "3o1L7HFrLp4I+fPz5fCf1NJ+zLLXjX/Z6waRuHeYj9vrk/9RLY3Pkv9myt+ORh1Ot1P5d316PF5",
    "Kj52V0ePTpfR4tDJ6PCiVFxFuvlZD/q1aus5nyX875QdHow6nA5xipVrsT+Xl2awth1/sW7n1UT",
    "A49aSdvi5x6/xEivWftYR2GE4YiTLkydJnLaXP5lSZ+7wWX78Or8Quq+Kfy/K+mvJPdeofDLqV8",
    "As5n/iF8Cv1y5syR6867irtkmeur5TEbZD/bx9xlbhl9Su6X3nTf3/RPEBSv99cYT0uqk9F9q2r",
    "ptcvBfvHRwn92eydcj1g3M94q5U83gfay3r6lsT3XwXtN91HN539kj/FXuzsCsrHmk1eyU1vHyn",
    "3f8zskQKqs98VXkcfyjtf3knlt6OHTPhyqD9+uP14a5m+9g/+sjSq",
    ""
  };

  static char newstr [1629] = "";
  newstr[0] = '\0';
  for (i = 0; i < 23; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c1_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c1_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(4291468468U));
  ssSetChecksum1(S,(3104356549U));
  ssSetChecksum2(S,(3588570340U));
  ssSetChecksum3(S,(3943777336U));
}

static void mdlRTW_c1_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c1_flightControlSystem(SimStruct *S)
{
  SFc1_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc1_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c1_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c1_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c1_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c1_flightControlSystem(chartInstance);
}

void c1_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
