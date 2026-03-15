/* Include files */

#include "flightControlSystem_sfun.h"
#include "c6_flightControlSystem.h"
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
static emlrtMCInfo c6_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c6_b_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRSInfo c6_emlrtRSI = { 8,  /* lineNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fcnName */
  "#flightControlSystem:2978"          /* pathName */
};

static emlrtRSInfo c6_b_emlrtRSI = { 11,/* lineNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fcnName */
  "#flightControlSystem:2978"          /* pathName */
};

static emlrtRSInfo c6_c_emlrtRSI = { 14,/* lineNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fcnName */
  "#flightControlSystem:2978"          /* pathName */
};

static emlrtRSInfo c6_d_emlrtRSI = { 15,/* lineNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fcnName */
  "#flightControlSystem:2978"          /* pathName */
};

static emlrtRSInfo c6_e_emlrtRSI = { 39,/* lineNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fcnName */
  "#flightControlSystem:2978"          /* pathName */
};

static emlrtRSInfo c6_f_emlrtRSI = { 58,/* lineNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fcnName */
  "#flightControlSystem:2978"          /* pathName */
};

static emlrtRSInfo c6_g_emlrtRSI = { 77,/* lineNo */
  "bwmorph",                           /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\bwmorph.m"/* pathName */
};

static emlrtRSInfo c6_h_emlrtRSI = { 24,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_i_emlrtRSI = { 109,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_j_emlrtRSI = { 143,/* lineNo */
  "bwlookup",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\bwlookup.m"/* pathName */
};

static emlrtRSInfo c6_k_emlrtRSI = { 33,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_l_emlrtRSI = { 322,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_m_emlrtRSI = { 325,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_n_emlrtRSI = { 281,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_o_emlrtRSI = { 289,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_p_emlrtRSI = { 295,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_q_emlrtRSI = { 301,/* lineNo */
  "algbwmorph",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\+images\\+internal\\algbwmorph.m"/* pathName */
};

static emlrtRSInfo c6_r_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c6_s_emlrtRSI = { 132,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c6_t_emlrtRSI = { 249,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c6_u_emlrtRSI = { 248,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c6_v_emlrtRSI = { 247,/* lineNo */
  "find",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c6_w_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo c6_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c6_b_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c6_c_emlrtRTEI = { 189,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c6_d_emlrtRTEI = { 191,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c6_e_emlrtRTEI = { 247,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c6_f_emlrtRTEI = { 248,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtBCInfo c6_emlrtBCI = { 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  46,                                  /* lineNo */
  19,                                  /* colNo */
  "x_pts",                             /* aName */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fName */
  "#flightControlSystem:2978",         /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c6_g_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fName */
  "#flightControlSystem:2978"          /* pName */
};

static emlrtBCInfo c6_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  31,                                  /* colNo */
  "x_pts",                             /* aName */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fName */
  "#flightControlSystem:2978",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c6_emlrtDCI = { 49, /* lineNo */
  31,                                  /* colNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fName */
  "#flightControlSystem:2978",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c6_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "y_pts",                             /* aName */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fName */
  "#flightControlSystem:2978",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c6_b_emlrtDCI = { 50,/* lineNo */
  31,                                  /* colNo */
  "Image Processing System/Analiza jako\xc5\x9b" "ciowa/Analiza_bledu",/* fName */
  "#flightControlSystem:2978",         /* pName */
  1                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void enable_c6_flightControlSystem(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_update_jit_animation_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void c6_do_animation_call_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_st);
static void c6_bwmorph(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_bwin[19200], boolean_T c6_bw[19200]);
static boolean_T c6_function_handle_parenReference
  (SFc6_flightControlSystemInstanceStruct *chartInstance, boolean_T
   c6_varargin_1, boolean_T c6_varargin_2);
static void c6_eml_find(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_x[19200], int32_T c6_i_data[], int32_T c6_i_size[1], int32_T
  c6_j_data[], int32_T c6_j_size[1]);
static void c6_indexShapeCheck(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static real32_T c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_nullptr, const char_T *c6_identifier);
static real32_T c6_b_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_nullptr, const char_T *c6_identifier,
  boolean_T c6_y[19200]);
static void c6_d_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[19200]);
static void init_dsm_address_info(SFc6_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c6_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c6_st.tls = chartInstance->c6_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c6_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c6_doneDoubleBufferReInit = false;
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c6_decisionTxtEndIdx = 0U;
  static const uint32_T c6_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c6_JITStateAnimation[0],
                        &chartInstance->c6_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c6_covrtInstance, 1U, 0U, 1U,
    141U);
  covrtChartInitFcn(chartInstance->c6_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c6_decisionTxtStartIdx, &c6_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 0U, 1U, 0U, 5U, 0U,
                  0U, 0U, 1U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U,
                     "c6_flightControlSystem", 0, -1, 1962);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 829, 853, 1001,
                    1133, false);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 1U, 1001, 1021,
                    1225, 1715, false);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 2U, 1225, 1242,
                    1322, 1715, false);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 3U, 1574, 1595, -1,
                    1647, false);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 4U, 1845, 1869,
                    1910, 1958, false);
  covrtEmlForInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 1415, 1432,
                     1659);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 832,
    853, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 1U, 1577,
    1595, -3, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 2U, 1848,
    1869, -3, 4U);
}

static void mdl_cleanup_runtime_resources_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c6_covrtInstance);
}

static void enable_c6_flightControlSystem(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  static char_T c6_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c6_cv1[4] = { 's', 'q', 'r', 't' };

  static boolean_T c6_b_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, false,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, false, false, true, true, false, false, false, false, false,
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
    true, false, false, false, true, false, false, true, true, false, false,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true };

  static boolean_T c6_c_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, false, false,
    true, false, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, false, true, false, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, false, false, true, true, false, true, true, true };

  static boolean_T c6_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
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
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true };

  emlrtStack c6_b_st;
  emlrtStack c6_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_sizeIn[2];
  real_T c6_b_isCircleDetected;
  real_T c6_b_k;
  real_T c6_b_num_pts;
  real_T c6_d_k;
  real_T c6_num_pts;
  int32_T c6_ii_size[1];
  int32_T c6_jj_size[1];
  int32_T c6_x_pts_size[1];
  int32_T c6_y_pts_size[1];
  int32_T c6_b_loop_ub;
  int32_T c6_c_k;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_k;
  int32_T c6_loop_ub;
  real32_T c6_b_dist_error;
  real32_T c6_b_dist_error_tol;
  real32_T c6_b_is_perfect_center;
  real32_T c6_b_x;
  real32_T c6_d_sq;
  real32_T c6_dx;
  real32_T c6_dy;
  real32_T c6_min_dist_sq;
  real32_T c6_raw_error;
  real32_T c6_x;
  boolean_T c6_image_iter1[19200];
  boolean_T c6_img_clean[19200];
  boolean_T c6_last_aout[19200];
  boolean_T c6_b_p;
  boolean_T c6_c_p;
  boolean_T c6_d_p;
  boolean_T c6_e_p;
  boolean_T c6_exitg1;
  boolean_T c6_p;
  boolean_T c6_x1;
  boolean_T c6_x2;
  c6_st.tls = chartInstance->c6_fEmlrtCtx;
  c6_b_st.prev = &c6_st;
  c6_b_st.tls = c6_st.tls;
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                    *chartInstance->c6_isCircleDetected);
  if (covrtIsSigCovEnabledFcn(chartInstance->c6_covrtInstance, 0U) != 0U) {
    for (c6_i = 0; c6_i < 19200; c6_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c6_covrtInstance, 0U, (*
        chartInstance->c6_binaryImage)[c6_i]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_JITTransitionAnimation[0] = 0U;
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_b_isCircleDetected = *chartInstance->c6_isCircleDetected;
  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 0, 0);
  c6_b_st.site = &c6_emlrtRSI;
  for (c6_i1 = 0; c6_i1 < 19200; c6_i1++) {
    c6_img_clean[c6_i1] = ((*chartInstance->c6_binaryImage)[c6_i1] != 0.0);
  }

  for (c6_i2 = 0; c6_i2 < 19200; c6_i2++) {
    c6_last_aout[c6_i2] = c6_img_clean[c6_i2];
  }

  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    c6_sizeIn[c6_i3] = 120.0 + 40.0 * (real_T)c6_i3;
  }

  bwlookup_tbb_boolean(&c6_last_aout[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                       &c6_img_clean[0]);
  c6_b_st.site = &c6_b_emlrtRSI;
  do {
    for (c6_i4 = 0; c6_i4 < 19200; c6_i4++) {
      c6_last_aout[c6_i4] = c6_img_clean[c6_i4];
    }

    for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
      c6_sizeIn[c6_i5] = 120.0 + 40.0 * (real_T)c6_i5;
    }

    bwlookup_tbb_boolean(&c6_img_clean[0], &c6_sizeIn[0], 2.0, &c6_b_lut[0],
                         512.0, &c6_image_iter1[0]);
    for (c6_i6 = 0; c6_i6 < 2; c6_i6++) {
      c6_sizeIn[c6_i6] = 120.0 + 40.0 * (real_T)c6_i6;
    }

    bwlookup_tbb_boolean(&c6_image_iter1[0], &c6_sizeIn[0], 2.0, &c6_c_lut[0],
                         512.0, &c6_img_clean[0]);
    c6_p = false;
    c6_b_p = true;
    c6_k = 0;
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_k < 19200)) {
      c6_b_k = (real_T)c6_k + 1.0;
      c6_x1 = c6_last_aout[(int32_T)c6_b_k - 1];
      c6_x2 = c6_img_clean[(int32_T)c6_b_k - 1];
      c6_c_p = ((int32_T)c6_x1 == (int32_T)c6_x2);
      if (!c6_c_p) {
        c6_b_p = false;
        c6_exitg1 = true;
      } else {
        c6_k++;
      }
    }

    if (c6_b_p) {
      c6_p = true;
    }
  } while (!c6_p);

  c6_b_st.site = &c6_c_emlrtRSI;
  c6_bwmorph(chartInstance, c6_img_clean, c6_image_iter1);
  c6_b_st.site = &c6_d_emlrtRSI;
  for (c6_i7 = 0; c6_i7 < 19200; c6_i7++) {
    c6_last_aout[c6_i7] = c6_image_iter1[c6_i7];
  }

  for (c6_i8 = 0; c6_i8 < 2; c6_i8++) {
    c6_sizeIn[c6_i8] = 120.0 + 40.0 * (real_T)c6_i8;
  }

  bwlookup_tbb_boolean(&c6_last_aout[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                       &c6_image_iter1[0]);
  c6_b_dist_error = 0.0F;
  c6_b_dist_error_tol = 0.0F;
  c6_b_is_perfect_center = 0.0F;
  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 0U, 0U, c6_b_isCircleDetected, 1.0, -1, 0U, c6_b_isCircleDetected ==
        1.0))) {
  } else if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 1,
              c6_image_iter1[9539])) {
    c6_b_is_perfect_center = 1.0F;
  } else {
    c6_b_st.site = &c6_e_emlrtRSI;
    c6_eml_find(chartInstance, c6_image_iter1, chartInstance->c6_ii_data,
                c6_ii_size, chartInstance->c6_jj_data, c6_jj_size);
    c6_y_pts_size[0] = c6_ii_size[0];
    c6_loop_ub = c6_ii_size[0] - 1;
    for (c6_i10 = 0; c6_i10 <= c6_loop_ub; c6_i10++) {
      chartInstance->c6_y_pts_data[c6_i10] = (real_T)chartInstance->
        c6_ii_data[c6_i10];
    }

    c6_x_pts_size[0] = c6_jj_size[0];
    c6_b_loop_ub = c6_jj_size[0] - 1;
    for (c6_i12 = 0; c6_i12 <= c6_b_loop_ub; c6_i12++) {
      chartInstance->c6_x_pts_data[c6_i12] = (real_T)chartInstance->
        c6_jj_data[c6_i12];
    }

    if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 2, c6_x_pts_size
                       [0] == 0)) {
      c6_raw_error = 100.0F;
    } else {
      c6_min_dist_sq = 1.0E+6F;
      if (c6_x_pts_size[0] < 0) {
        emlrtDynamicBoundsCheckR2012b(c6_x_pts_size[0], 0, MAX_int32_T,
          &c6_emlrtBCI, &c6_st);
      }

      c6_num_pts = (real_T)c6_x_pts_size[0];
      c6_b_num_pts = c6_num_pts;
      c6_i13 = (int32_T)c6_b_num_pts;
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, c6_b_num_pts, mxDOUBLE_CLASS,
        c6_i13, &c6_g_emlrtRTEI, &c6_st);
      for (c6_c_k = 0; c6_c_k < c6_i13; c6_c_k++) {
        c6_d_k = 1.0 + (real_T)c6_c_k;
        covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 0, 0, 1);
        if (c6_d_k != (real_T)(int32_T)muDoubleScalarFloor(c6_d_k)) {
          emlrtIntegerCheckR2012b(c6_d_k, &c6_emlrtDCI, &c6_st);
        }

        c6_i14 = (int32_T)c6_d_k;
        if ((c6_i14 < 1) || (c6_i14 > c6_x_pts_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c6_i14, 1, c6_x_pts_size[0],
            &c6_b_emlrtBCI, &c6_st);
        }

        c6_dx = (real32_T)chartInstance->c6_x_pts_data[c6_i14 - 1] - 80.0F;
        if (c6_d_k != (real_T)(int32_T)muDoubleScalarFloor(c6_d_k)) {
          emlrtIntegerCheckR2012b(c6_d_k, &c6_b_emlrtDCI, &c6_st);
        }

        c6_i15 = (int32_T)c6_d_k;
        if ((c6_i15 < 1) || (c6_i15 > c6_y_pts_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c6_i15, 1, c6_y_pts_size[0],
            &c6_c_emlrtBCI, &c6_st);
        }

        c6_dy = (real32_T)chartInstance->c6_y_pts_data[c6_i15 - 1] - 60.0F;
        c6_d_sq = c6_dx * c6_dx + c6_dy * c6_dy;
        if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 3,
                           covrtRelationalopUpdateFcn
                           (chartInstance->c6_covrtInstance, 4U, 0U, 1U, (real_T)
                            c6_d_sq, (real_T)c6_min_dist_sq, -3, 2U, c6_d_sq <
                            c6_min_dist_sq))) {
          c6_min_dist_sq = c6_d_sq;
        }

        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c6_covrtInstance, 4U, 0, 0, 0);
      c6_b_st.site = &c6_f_emlrtRSI;
      c6_x = c6_min_dist_sq;
      c6_raw_error = c6_x;
      c6_b_x = c6_raw_error;
      if (c6_b_x < 0.0F) {
        c6_d_p = true;
      } else {
        c6_d_p = false;
      }

      c6_e_p = c6_d_p;
      if (c6_e_p) {
        c6_y = NULL;
        sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 30),
                      false);
        c6_b_y = NULL;
        sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 30),
                      false);
        c6_c_y = NULL;
        sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 4),
                      false);
        sf_mex_call(&c6_b_st, &c6_b_emlrtMCI, "error", 0U, 2U, 14, c6_y, 14,
                    sf_mex_call(&c6_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c6_b_st, NULL, "message", 1U, 2U, 14, c6_b_y, 14, c6_c_y)));
      }

      c6_raw_error = muSingleScalarSqrt(c6_raw_error);
    }

    c6_b_dist_error = c6_raw_error;
    if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 4,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c6_covrtInstance, 4U, 0U, 2U, (real_T)
                        c6_raw_error, 5.0, -3, 4U, c6_raw_error > 5.0F))) {
      c6_b_dist_error_tol = c6_raw_error;
    } else {
      c6_b_dist_error_tol = 0.0F;
    }
  }

  for (c6_i9 = 0; c6_i9 < 19200; c6_i9++) {
    (*chartInstance->c6_thin_out)[c6_i9] = c6_image_iter1[c6_i9];
  }

  *chartInstance->c6_dist_error = c6_b_dist_error;
  *chartInstance->c6_dist_error_tol = c6_b_dist_error_tol;
  *chartInstance->c6_is_perfect_center = c6_b_is_perfect_center;
  if (covrtIsSigCovEnabledFcn(chartInstance->c6_covrtInstance, 2U) != 0U) {
    for (c6_i11 = 0; c6_i11 < 19200; c6_i11++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c6_covrtInstance, 2U,
        (real_T)(*chartInstance->c6_thin_out)[c6_i11]);
    }
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 3U, (real_T)
                    *chartInstance->c6_dist_error);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 4U, (real_T)
                    *chartInstance->c6_dist_error_tol);
  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 5U, (real_T)
                    *chartInstance->c6_is_perfect_center);
}

static void ext_mode_exec_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_update_jit_animation_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_do_animation_call_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_e_y = NULL;
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(4, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", chartInstance->c6_dist_error, 1, 0U,
    0, 0U, 0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", chartInstance->c6_dist_error_tol, 1,
    0U, 0, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", chartInstance->c6_is_perfect_center,
    1, 0U, 0, 0U, 0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", *chartInstance->c6_thin_out, 11, 0U,
    1, 0U, 2, 120, 160), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_flightControlSystem
  (SFc6_flightControlSystemInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  int32_T c6_i;
  boolean_T c6_bv[19200];
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  *chartInstance->c6_dist_error = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 0)), "dist_error");
  *chartInstance->c6_dist_error_tol = c6_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 1)), "dist_error_tol");
  *chartInstance->c6_is_perfect_center = c6_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 2)), "is_perfect_center");
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 3)),
                        "thin_out", c6_bv);
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    (*chartInstance->c6_thin_out)[c6_i] = c6_bv[c6_i];
  }

  sf_mex_destroy(&c6_u);
  sf_mex_destroy(&c6_st);
}

static void c6_bwmorph(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_bwin[19200], boolean_T c6_bw[19200])
{
  static boolean_T c6_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    false, false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    false, false, false, false, false, false, false, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, false, false, false, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    false, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false
  };

  real_T c6_sizeIn[2];
  real_T c6_b_k;
  real_T c6_iter;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i2;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i3;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i4;
  int32_T c6_i40;
  int32_T c6_i41;
  int32_T c6_i42;
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  int32_T c6_i47;
  int32_T c6_i48;
  int32_T c6_i49;
  int32_T c6_i5;
  int32_T c6_i50;
  int32_T c6_i51;
  int32_T c6_i52;
  int32_T c6_i53;
  int32_T c6_i54;
  int32_T c6_i55;
  int32_T c6_i56;
  int32_T c6_i57;
  int32_T c6_i58;
  int32_T c6_i59;
  int32_T c6_i6;
  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  int32_T c6_i63;
  int32_T c6_i64;
  int32_T c6_i65;
  int32_T c6_i66;
  int32_T c6_i67;
  int32_T c6_i68;
  int32_T c6_i69;
  int32_T c6_i7;
  int32_T c6_i70;
  int32_T c6_i71;
  int32_T c6_i72;
  int32_T c6_i73;
  int32_T c6_i74;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_k;
  boolean_T c6_endPoints[19200];
  boolean_T c6_last_aout[19200];
  boolean_T c6_newEndPoints[19200];
  boolean_T c6_t[4800];
  boolean_T c6_y[4800];
  boolean_T c6_b_p;
  boolean_T c6_c_p;
  boolean_T c6_exitg1;
  boolean_T c6_exitg2;
  boolean_T c6_p;
  boolean_T c6_x1;
  boolean_T c6_x2;
  c6_iter = 0.0;
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    c6_bw[c6_i] = c6_bwin[c6_i];
  }

  c6_exitg1 = false;
  while ((!c6_exitg1) && (c6_iter < 7.0)) {
    for (c6_i1 = 0; c6_i1 < 19200; c6_i1++) {
      c6_last_aout[c6_i1] = c6_bw[c6_i1];
    }

    for (c6_i2 = 0; c6_i2 < 19200; c6_i2++) {
      c6_bw[c6_i2] = !c6_bw[c6_i2];
    }

    for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
      c6_sizeIn[c6_i3] = 120.0 + 40.0 * (real_T)c6_i3;
    }

    bwlookup_tbb_boolean(&c6_bw[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                         &c6_endPoints[0]);
    c6_i4 = 0;
    c6_i5 = 0;
    for (c6_i6 = 0; c6_i6 < 80; c6_i6++) {
      c6_i8 = 0;
      for (c6_i10 = 0; c6_i10 < 60; c6_i10++) {
        c6_y[c6_i10 + c6_i4] = c6_bw[c6_i8 + c6_i5];
        c6_i8 += 2;
      }

      c6_i4 += 60;
      c6_i5 += 240;
    }

    c6_i7 = 0;
    c6_i9 = 0;
    for (c6_i11 = 0; c6_i11 < 80; c6_i11++) {
      c6_i13 = 0;
      for (c6_i14 = 0; c6_i14 < 60; c6_i14++) {
        c6_t[c6_i14 + c6_i7] = c6_endPoints[c6_i13 + c6_i9];
        c6_i13 += 2;
      }

      c6_i7 += 60;
      c6_i9 += 240;
    }

    for (c6_i12 = 0; c6_i12 < 4800; c6_i12++) {
      c6_y[c6_i12] = c6_function_handle_parenReference(chartInstance,
        c6_y[c6_i12], c6_t[c6_i12]);
    }

    c6_i15 = 0;
    c6_i16 = 0;
    for (c6_i17 = 0; c6_i17 < 80; c6_i17++) {
      c6_i19 = 0;
      for (c6_i20 = 0; c6_i20 < 60; c6_i20++) {
        c6_bw[c6_i19 + c6_i15] = c6_y[c6_i20 + c6_i16];
        c6_i19 += 2;
      }

      c6_i15 += 240;
      c6_i16 += 60;
    }

    for (c6_i18 = 0; c6_i18 < 2; c6_i18++) {
      c6_sizeIn[c6_i18] = 120.0 + 40.0 * (real_T)c6_i18;
    }

    bwlookup_tbb_boolean(&c6_bw[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                         &c6_newEndPoints[0]);
    for (c6_i21 = 0; c6_i21 < 19200; c6_i21++) {
      c6_newEndPoints[c6_i21] = (c6_endPoints[c6_i21] && c6_newEndPoints[c6_i21]);
    }

    c6_i22 = 0;
    c6_i23 = 0;
    for (c6_i24 = 0; c6_i24 < 80; c6_i24++) {
      c6_i26 = 0;
      for (c6_i28 = 0; c6_i28 < 60; c6_i28++) {
        c6_y[c6_i28 + c6_i22] = c6_bw[(c6_i26 + c6_i23) + 120];
        c6_i26 += 2;
      }

      c6_i22 += 60;
      c6_i23 += 240;
    }

    c6_i25 = 0;
    c6_i27 = 0;
    for (c6_i29 = 0; c6_i29 < 80; c6_i29++) {
      c6_i31 = 0;
      for (c6_i32 = 0; c6_i32 < 60; c6_i32++) {
        c6_t[c6_i32 + c6_i25] = c6_newEndPoints[(c6_i31 + c6_i27) + 120];
        c6_i31 += 2;
      }

      c6_i25 += 60;
      c6_i27 += 240;
    }

    for (c6_i30 = 0; c6_i30 < 4800; c6_i30++) {
      c6_y[c6_i30] = c6_function_handle_parenReference(chartInstance,
        c6_y[c6_i30], c6_t[c6_i30]);
    }

    c6_i33 = 0;
    c6_i34 = 0;
    for (c6_i35 = 0; c6_i35 < 80; c6_i35++) {
      c6_i37 = 0;
      for (c6_i38 = 0; c6_i38 < 60; c6_i38++) {
        c6_bw[(c6_i37 + c6_i33) + 120] = c6_y[c6_i38 + c6_i34];
        c6_i37 += 2;
      }

      c6_i33 += 240;
      c6_i34 += 60;
    }

    for (c6_i36 = 0; c6_i36 < 2; c6_i36++) {
      c6_sizeIn[c6_i36] = 120.0 + 40.0 * (real_T)c6_i36;
    }

    bwlookup_tbb_boolean(&c6_bw[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                         &c6_newEndPoints[0]);
    for (c6_i39 = 0; c6_i39 < 19200; c6_i39++) {
      c6_newEndPoints[c6_i39] = (c6_endPoints[c6_i39] && c6_newEndPoints[c6_i39]);
    }

    c6_i40 = 0;
    c6_i41 = 0;
    for (c6_i42 = 0; c6_i42 < 80; c6_i42++) {
      c6_i44 = 0;
      for (c6_i46 = 0; c6_i46 < 60; c6_i46++) {
        c6_y[c6_i46 + c6_i40] = c6_bw[(c6_i44 + c6_i41) + 1];
        c6_i44 += 2;
      }

      c6_i40 += 60;
      c6_i41 += 240;
    }

    c6_i43 = 0;
    c6_i45 = 0;
    for (c6_i47 = 0; c6_i47 < 80; c6_i47++) {
      c6_i49 = 0;
      for (c6_i50 = 0; c6_i50 < 60; c6_i50++) {
        c6_t[c6_i50 + c6_i43] = c6_newEndPoints[(c6_i49 + c6_i45) + 1];
        c6_i49 += 2;
      }

      c6_i43 += 60;
      c6_i45 += 240;
    }

    for (c6_i48 = 0; c6_i48 < 4800; c6_i48++) {
      c6_y[c6_i48] = c6_function_handle_parenReference(chartInstance,
        c6_y[c6_i48], c6_t[c6_i48]);
    }

    c6_i51 = 0;
    c6_i52 = 0;
    for (c6_i53 = 0; c6_i53 < 80; c6_i53++) {
      c6_i55 = 0;
      for (c6_i56 = 0; c6_i56 < 60; c6_i56++) {
        c6_bw[(c6_i55 + c6_i51) + 1] = c6_y[c6_i56 + c6_i52];
        c6_i55 += 2;
      }

      c6_i51 += 240;
      c6_i52 += 60;
    }

    for (c6_i54 = 0; c6_i54 < 2; c6_i54++) {
      c6_sizeIn[c6_i54] = 120.0 + 40.0 * (real_T)c6_i54;
    }

    bwlookup_tbb_boolean(&c6_bw[0], &c6_sizeIn[0], 2.0, &c6_lut[0], 512.0,
                         &c6_newEndPoints[0]);
    for (c6_i57 = 0; c6_i57 < 19200; c6_i57++) {
      c6_newEndPoints[c6_i57] = (c6_endPoints[c6_i57] && c6_newEndPoints[c6_i57]);
    }

    c6_i58 = 0;
    c6_i59 = 0;
    for (c6_i60 = 0; c6_i60 < 80; c6_i60++) {
      c6_i62 = 0;
      for (c6_i64 = 0; c6_i64 < 60; c6_i64++) {
        c6_y[c6_i64 + c6_i58] = c6_bw[(c6_i62 + c6_i59) + 121];
        c6_i62 += 2;
      }

      c6_i58 += 60;
      c6_i59 += 240;
    }

    c6_i61 = 0;
    c6_i63 = 0;
    for (c6_i65 = 0; c6_i65 < 80; c6_i65++) {
      c6_i67 = 0;
      for (c6_i68 = 0; c6_i68 < 60; c6_i68++) {
        c6_t[c6_i68 + c6_i61] = c6_newEndPoints[(c6_i67 + c6_i63) + 121];
        c6_i67 += 2;
      }

      c6_i61 += 60;
      c6_i63 += 240;
    }

    for (c6_i66 = 0; c6_i66 < 4800; c6_i66++) {
      c6_y[c6_i66] = c6_function_handle_parenReference(chartInstance,
        c6_y[c6_i66], c6_t[c6_i66]);
    }

    c6_i69 = 0;
    c6_i70 = 0;
    for (c6_i71 = 0; c6_i71 < 80; c6_i71++) {
      c6_i73 = 0;
      for (c6_i74 = 0; c6_i74 < 60; c6_i74++) {
        c6_bw[(c6_i73 + c6_i69) + 121] = c6_y[c6_i74 + c6_i70];
        c6_i73 += 2;
      }

      c6_i69 += 240;
      c6_i70 += 60;
    }

    for (c6_i72 = 0; c6_i72 < 19200; c6_i72++) {
      c6_bw[c6_i72] = !c6_bw[c6_i72];
    }

    c6_iter++;
    c6_p = false;
    c6_b_p = true;
    c6_k = 0;
    c6_exitg2 = false;
    while ((!c6_exitg2) && (c6_k < 19200)) {
      c6_b_k = (real_T)c6_k + 1.0;
      c6_x1 = c6_last_aout[(int32_T)c6_b_k - 1];
      c6_x2 = c6_bw[(int32_T)c6_b_k - 1];
      c6_c_p = ((int32_T)c6_x1 == (int32_T)c6_x2);
      if (!c6_c_p) {
        c6_b_p = false;
        c6_exitg2 = true;
      } else {
        c6_k++;
      }
    }

    if (c6_b_p) {
      c6_p = true;
    }

    if (c6_p) {
      c6_exitg1 = true;
    }
  }
}

static boolean_T c6_function_handle_parenReference
  (SFc6_flightControlSystemInstanceStruct *chartInstance, boolean_T
   c6_varargin_1, boolean_T c6_varargin_2)
{
  boolean_T c6_a;
  boolean_T c6_b;
  boolean_T c6_b_a;
  boolean_T c6_b_b;
  boolean_T c6_b_varargin_1;
  boolean_T c6_b_varargin_2;
  boolean_T c6_x;
  boolean_T c6_y;
  (void)chartInstance;
  c6_x = c6_varargin_1;
  c6_y = c6_varargin_2;
  c6_b_varargin_1 = c6_x;
  c6_b_varargin_2 = c6_y;
  c6_a = c6_b_varargin_1;
  c6_b = c6_b_varargin_2;
  c6_b_a = c6_a;
  c6_b_b = c6_b;
  return (boolean_T)((int32_T)c6_b_a ^ (int32_T)c6_b_b);
}

static void c6_eml_find(SFc6_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c6_x[19200], int32_T c6_i_data[], int32_T c6_i_size[1], int32_T
  c6_j_data[], int32_T c6_j_size[1])
{
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_idx;
  int32_T c6_ii;
  int32_T c6_jj;
  boolean_T c6_b;
  boolean_T c6_b1;
  boolean_T c6_exitg1;
  boolean_T c6_guard1;
  c6_idx = 0;
  c6_ii = 1;
  c6_jj = 1;
  c6_exitg1 = false;
  while ((!c6_exitg1) && (c6_jj <= 160)) {
    c6_guard1 = false;
    if (c6_x[(c6_ii + 120 * (c6_jj - 1)) - 1]) {
      c6_idx++;
      c6_i_data[c6_idx - 1] = c6_ii;
      c6_j_data[c6_idx - 1] = c6_jj;
      if (c6_idx >= 19200) {
        c6_exitg1 = true;
      } else {
        c6_guard1 = true;
      }
    } else {
      c6_guard1 = true;
    }

    if (c6_guard1) {
      c6_ii++;
      if (c6_ii > 120) {
        c6_ii = 1;
        c6_jj++;
      }
    }
  }

  c6_b = (c6_idx < 1);
  if (c6_b) {
    c6_i = 0;
  } else {
    c6_i = c6_idx;
  }

  c6_indexShapeCheck(chartInstance);
  c6_i_size[0] = c6_i;
  c6_b1 = (c6_idx < 1);
  if (c6_b1) {
    c6_i1 = 0;
  } else {
    c6_i1 = c6_idx;
  }

  c6_indexShapeCheck(chartInstance);
  c6_j_size[0] = c6_i1;
  c6_indexShapeCheck(chartInstance);
}

static void c6_indexShapeCheck(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c6_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static real32_T c6_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_nullptr, const char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  real32_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nullptr), &c6_thisId);
  sf_mex_destroy(&c6_nullptr);
  return c6_y;
}

static real32_T c6_b_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real32_T c6_f;
  real32_T c6_y;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_f, 0, 1, 0U, 0, 0U, 0);
  c6_y = c6_f;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_nullptr, const char_T *c6_identifier,
  boolean_T c6_y[19200])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nullptr), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_nullptr);
}

static void c6_d_emlrt_marshallIn(SFc6_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[19200])
{
  int32_T c6_i;
  boolean_T c6_bv[19200];
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_bv, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c6_i = 0; c6_i < 19200; c6_i++) {
    c6_y[c6_i] = c6_bv[c6_i];
  }

  sf_mex_destroy(&c6_u);
}

static void init_dsm_address_info(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c6_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c6_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c6_thin_out = (boolean_T (*)[19200])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c6_dist_error = (real32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c6_dist_error_tol = (real32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c6_is_perfect_center = (real32_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c6_binaryImage = (real_T (*)[19200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c6_isCircleDetected = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c6_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3177396650U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3659071041U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4173893506U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(906680868U);
}

mxArray *sf_c6_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  return(mxcell3p);
}

mxArray *sf_c6_flightControlSystem_jit_fallback_info(void)
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

mxArray *sf_c6_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCewczAwAakOYCYiQECWKF8RiBmgdIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikPAB3vK9Is4gPQ7IOlnwaKfC0m/AJSfkllcEp9aVJRfBB"
    "HnY0DQA+cfHaL8w4fmHz4U/8SX5OcMFv9IgP3jQcA/gmj+AfEzi+MLUovSUpNL4pNT80pSixgGU"
    "zxpOKDrx+YvDjR/gfglGZl58fmlJTB/AABX0CsI"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sfHitHLY1GV1KhJcZaLAzaE";
}

static void sf_opaque_initialize_c6_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c6_flightControlSystem
    ((SFc6_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_flightControlSystem(void *chartInstanceVar)
{
  enable_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_flightControlSystem(void *chartInstanceVar)
{
  disable_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c6_flightControlSystem
    ((SFc6_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c6_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c6_flightControlSystem
      ((SFc6_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c6_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc6_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c6_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c6_flightControlSystem((SFc6_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_flightControlSystem
      ((SFc6_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c6_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrdWE9v40QUd0K22q2WaCuh3UVCwIHDHkBqWVhxQGy7+bMNpDTCaRF7iSb2SzzqeMY7f5JmT3w",
    "MPgESXwZx5MhH4MCBI28cJw1OSGwH1C6WXHfs/Oa99/Nv3ntjp9Q6cfCo4vnL246zg9fbeJad6X",
    "ErGZcWzun9ivN5Mu7sOo4XEKlbfCCc/IcnfBgCd81gQC9zYrkJO0SSUBWwy0kI34ASzGgqeD7nK",
    "R+ABO7hBJGQOpddRUPDKL9oGu5Zy+rbgHqBGwjD/Gc4IfFPOZv8k93I6A5arFMJnm4C+DqQwgyD",
    "JiPD9SxIPa4F4F0oE+bmSoF2TWRDVSeGaRoxaFyC1+JKE2RBbYjX1URDTV/mVghV7gwtwohRwrN",
    "zHRDlQoTq0HAW+fj31GhkL6NdtNennGghKWGNkNWswjNiOwz9PEFZs9w861DXoW+GQ8qHll1pQu",
    "AYP+okA1eDmhiBJEM45TnXoI2ucRm/4Lkus6/BlpVloTVowulbUYWwsd3GCBlSBe02PV4jjKl82",
    "K6I2jACFtuvE00KYKf2c4CVon5XnBNpV0HOlWQ4fWkgwdYE92n2NzxKoeKE+zUmzwxwGlpJgY80",
    "z12fT7RJk0ZpEdZwGdXb7Yz2lrEtrkEOiAeZc58kVAE6HOsqp12fKtJnFo0s6TjKzDMALwx11MD",
    "w+ljIC+Q4b5K94squhHxo8IdQBw1xwmigus8JMxl9DhVmOCuPM4UZK59dxNr1UwjsES8A39YTyu",
    "AElJ1AZc7PWEeOMNoR1ZM6KE/SKOtKMgp8LCSWpe4kgjN+wcWYN6UI3aQjWKMrAMwaRHIsC8+wL",
    "MlJE53P5rWEl12rrCLtWUg0I32rjefAsbLYWG0lJB6uqgbH1g0d2gbr0ldY2rmiSmM7NWnEa8CP",
    "+9GHpXz96F4yfjxfSy3VlfimCJZhjp3SUT9u9qBLQ4hvuAR7iukwOazdfefK7p3yertl/K9UEOd",
    "siTtewFVW8HN/AXcvGXtPegNGh4FNwloK5k6Q93DZj7sZ+F7lfxrnLOGueJ5dHy3gSyvsOgvXTX",
    "yVl/hCxkpT3OEC7s2UnUoKt5Nw9v1vn3zwdP/dn3/a6d7qiD9+3EYfx5V8eq4m43dm/dm8go2Wk",
    "nwWPTxI6eFBXDeOqT5uf3fw/Pzgq+BL7wVpH70ijXi+H95Y728l5e/s/vt4akxwcb6UXstP9lp2",
    "TMx0D2Dn/2zB350NfNxZ0JPj/P50O/xbh2k9rOJrN8XX7rS+6x5IKeSyjq8vng8zxVNNxVP9Wzw",
    "9LdhNiefhYRY976Xi2Yv3QL0I2z3sR3oe2M7PuUnv6dFhGr8qrtupuOxYB5T3hNHV16hOXVddvE",
    "4/s9TNckFcxfnv6vS/ids2vrz9wOv++/01+cBJ/f7eDY4jfS3aF960uH518vVt7yXjL+bfbGoBZ",
    "f6KXWPyGDd2g1VP/yf6/jMnf7M+tWH5Sz46v3h8xAmb4DZxug1Pbnek/d45fySBqNV78euoQ7Pr",
    "pr7sbmp92/GYcl+M1UcHH3+6v01d+wsIWR1i",
    ""
  };

  static char newstr [1537] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c6_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c6_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(607445120U));
  ssSetChecksum1(S,(3458084927U));
  ssSetChecksum2(S,(89392809U));
  ssSetChecksum3(S,(2801037136U));
}

static void mdlRTW_c6_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c6_flightControlSystem(SimStruct *S)
{
  SFc6_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc6_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc6_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c6_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c6_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c6_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_flightControlSystem;
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

  mdl_setup_runtime_resources_c6_flightControlSystem(chartInstance);
}

void c6_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c6_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
