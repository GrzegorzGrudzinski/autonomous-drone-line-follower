/* Include files */

#include "flightControlSystem_sfun.h"
#include "c4_flightControlSystem.h"
#include <math.h>
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
static emlrtMCInfo c4_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI = { 161,/* lineNo */
  1,                                   /* colNo */
  "imadjust",                          /* fName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI = { 159,/* lineNo */
  1,                                   /* colNo */
  "imadjust",                          /* fName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 3,  /* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2840"          /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 4,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2840"          /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 5,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2840"          /* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 6,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2840"          /* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 7,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2840"          /* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 8,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2840"          /* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 9,/* lineNo */
  "Image Processing System/MATLAB Function1",/* fcnName */
  "#flightControlSystem:2840"          /* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 133,/* lineNo */
  "rescale",                           /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\datafun\\rescale.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 27,/* lineNo */
  "rescaleKernel",                     /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\rescaleKernel.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 30,/* lineNo */
  "rescaleKernel",                     /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\rescaleKernel.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 12,/* lineNo */
  "pow2",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\elfun\\pow2.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 48,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 12,/* lineNo */
  "pow2",                              /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+scalar\\pow2.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 25,/* lineNo */
  "imadjust",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 276,/* lineNo */
  "imadjust",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 24,/* lineNo */
  "imadjust",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 26,/* lineNo */
  "imadjust",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 54,/* lineNo */
  "stretchlim",                        /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\stretchlim.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 131,/* lineNo */
  "imhist",                            /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 166,/* lineNo */
  "imhist",                            /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 452,/* lineNo */
  "imhist",                            /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 295,/* lineNo */
  "imadjust",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 331,/* lineNo */
  "imadjust",                          /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\images\\images\\eml\\imadjust.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "D:\\Matlab_2024b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static char_T c4_cv[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'h',
  'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N', 'a', 'N',
  's' };

/* Function Declarations */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_update_jit_animation_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st);
static void c4_rescale(SFc4_flightControlSystemInstanceStruct *chartInstance,
  real_T c4_A[71820], real_T c4_b_R[71820]);
static real_T c4_pow2(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      real_T c4_a);
static void c4_stretchlim(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_varargin_1[71820], real_T c4_lowhigh[2]);
static void c4_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real_T c4_c_varargin_1[71820],
                      real_T c4_yout[65536]);
static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp);
static real_T c4_sumColumnB4(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_x[65536], int32_T c4_vstart);
static const mxArray *c4_imshow(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1, const mxArray *c4_input2, const mxArray *c4_input3, const
  mxArray *c4_input4, const mxArray *c4_input5, const mxArray *c4_input6);
static const mxArray *c4_title(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0);
static const mxArray *c4_xlabel(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0);
static const mxArray *c4_ylabel(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0);
static const mxArray *c4_axis(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0);
static const mxArray *c4_b_axis(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0);
static const mxArray *c4_hot(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp);
static const mxArray *c4_colormap(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0);
static const mxArray *c4_b_warning(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static const mxArray *c4_c_warning(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0);
static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c4_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_doneDoubleBufferReInit = false;
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c4_JITStateAnimation[0],
                        &chartInstance->c4_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    22U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "c4_flightControlSystem", 0, -1, 199);
}

static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static char_T c4_cv5[40] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'a',
    'd', 'j', 'u', 's', 't', ':', 'l', 'o', 'w', 'M', 'u', 's', 't', 'B', 'e',
    'S', 'm', 'a', 'l', 'l', 'e', 'r', 'T', 'h', 'a', 'n', 'H', 'i', 'g', 'h' };

  static char_T c4_cv6[39] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'a',
    'd', 'j', 'u', 's', 't', ':', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r',
    's', 'A', 'r', 'e', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  static char_T c4_cv2[20] = { 'I', 'n', 'i', 't', 'i', 'a', 'l', 'M', 'a', 'g',
    'n', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n' };

  static char_T c4_cv7[15] = { 'H', 'o', 'u', 'g', 'h', ' ', 'T', 'r', 'a', 'n',
    's', 'f', 'o', 'r', 'm' };

  static char_T c4_cv11[6] = { 'n', 'o', 'r', 'm', 'a', 'l' };

  static char_T c4_cv8[6] = { '\\', 't', 'h', 'e', 't', 'a' };

  static char_T c4_b_cv[5] = { 'X', 'D', 'a', 't', 'a' };

  static char_T c4_cv1[5] = { 'Y', 'D', 'a', 't', 'a' };

  static char_T c4_cv9[4] = { '\\', 'r', 'h', 'o' };

  static char_T c4_cv3[3] = { 'f', 'i', 't' };

  static char_T c4_cv4[3] = { 'o', 'f', 'f' };

  static char_T c4_cv10[2] = { 'o', 'n' };

  c4_rtString c4_r;
  c4_rtString c4_r1;
  c4_rtString_1 c4_r2;
  c4_rtString_2 c4_r3;
  c4_rtString_3 c4_r4;
  c4_rtString_4 c4_r5;
  c4_rtString_5 c4_r6;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c4_b_propValues[1];
  const mxArray *c4_c_propValues[1];
  const mxArray *c4_d_propValues[1];
  const mxArray *c4_e_propValues[1];
  const mxArray *c4_f_propValues[1];
  const mxArray *c4_g_propValues[1];
  const mxArray *c4_propValues[1];
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_bb_y = NULL;
  const mxArray *c4_cb_y = NULL;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_db_y = NULL;
  const mxArray *c4_e_y = NULL;
  const mxArray *c4_eb_y = NULL;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_fb_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_gb_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_hb_y = NULL;
  const mxArray *c4_i_y = NULL;
  const mxArray *c4_ib_y = NULL;
  const mxArray *c4_jb_y = NULL;
  const mxArray *c4_kb_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_n_y = NULL;
  const mxArray *c4_p_y = NULL;
  const mxArray *c4_r_y = NULL;
  const mxArray *c4_s = NULL;
  const mxArray *c4_u_y = NULL;
  const mxArray *c4_w_y = NULL;
  const mxArray *c4_y = NULL;
  const mxArray *c4_y_y = NULL;
  real_T c4_lowhigh_in[2];
  real_T c4_a;
  real_T c4_ab_y;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_b_fullRange;
  real_T c4_b_hIn;
  real_T c4_b_lIn;
  real_T c4_b_minval;
  real_T c4_b_varargin_2;
  real_T c4_c;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_c_i;
  real_T c4_c_minval;
  real_T c4_c_varargin_1;
  real_T c4_c_x;
  real_T c4_d_a;
  real_T c4_d_varargin_1;
  real_T c4_d_x;
  real_T c4_e_a;
  real_T c4_e_varargin_1;
  real_T c4_e_x;
  real_T c4_f_a;
  real_T c4_f_varargin_1;
  real_T c4_f_x;
  real_T c4_fullRange;
  real_T c4_g_a;
  real_T c4_g_x;
  real_T c4_hIn;
  real_T c4_h_x;
  real_T c4_highIn;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_j_y;
  real_T c4_k_x;
  real_T c4_k_y;
  real_T c4_lIn;
  real_T c4_l_x;
  real_T c4_lowIn;
  real_T c4_m_x;
  real_T c4_m_y;
  real_T c4_maxval;
  real_T c4_minval;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_o_y;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_q_y;
  real_T c4_r_x;
  real_T c4_s_x;
  real_T c4_s_y;
  real_T c4_t_x;
  real_T c4_t_y;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_v_y;
  real_T c4_varargin_2;
  real_T c4_x_y;
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  const char_T *c4_b_propClasses[1] = { "coder.internal.string" };

  const char_T *c4_b_propNames[1] = { "Value" };

  const char_T *c4_c_propClasses[1] = { "coder.internal.string" };

  const char_T *c4_c_propNames[1] = { "Value" };

  const char_T *c4_d_propClasses[1] = { "coder.internal.string" };

  const char_T *c4_d_propNames[1] = { "Value" };

  const char_T *c4_e_propClasses[1] = { "coder.internal.string" };

  const char_T *c4_e_propNames[1] = { "Value" };

  const char_T *c4_f_propClasses[1] = { "coder.internal.string" };

  const char_T *c4_f_propNames[1] = { "Value" };

  const char_T *c4_g_propClasses[1] = { "coder.internal.string" };

  const char_T *c4_g_propNames[1] = { "Value" };

  const char_T *c4_propClasses[1] = { "coder.internal.string" };

  const char_T *c4_propNames[1] = { "Value" };

  char_T c4_b_u[20];
  char_T c4_d_u[15];
  char_T c4_e_u[6];
  char_T c4_u[5];
  char_T c4_f_u[4];
  char_T c4_c_u[3];
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b_isInvalid;
  boolean_T c4_b_x;
  boolean_T c4_c_isInvalid;
  boolean_T c4_c_y;
  boolean_T c4_d_isInvalid;
  boolean_T c4_isInvalid;
  boolean_T c4_x;
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  if (covrtIsSigCovEnabledFcn(chartInstance->c4_covrtInstance, 2U) != 0U) {
    for (c4_i = 0; c4_i < 399; c4_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c4_covrtInstance, 2U, (*
        chartInstance->c4_R)[c4_i]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c4_covrtInstance, 1U) != 0U) {
    for (c4_i1 = 0; c4_i1 < 180; c4_i1++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c4_covrtInstance, 1U, (*
        chartInstance->c4_T)[c4_i1]);
    }
  }

  if (covrtIsSigCovEnabledFcn(chartInstance->c4_covrtInstance, 0U) != 0U) {
    for (c4_i2 = 0; c4_i2 < 71820; c4_i2++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c4_covrtInstance, 0U, (*
        chartInstance->c4_H)[c4_i2]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  chartInstance->c4_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  for (c4_i3 = 0; c4_i3 < 5; c4_i3++) {
    c4_r.Value[c4_i3] = c4_b_cv[c4_i3];
  }

  for (c4_i4 = 0; c4_i4 < 5; c4_i4++) {
    c4_r1.Value[c4_i4] = c4_cv1[c4_i4];
  }

  for (c4_i5 = 0; c4_i5 < 20; c4_i5++) {
    c4_r2.Value[c4_i5] = c4_cv2[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_r3.Value[c4_i6] = c4_cv3[c4_i6];
  }

  c4_b_st.site = &c4_emlrtRSI;
  c4_c_st.site = &c4_emlrtRSI;
  for (c4_i7 = 0; c4_i7 < 71820; c4_i7++) {
    chartInstance->c4_dv[c4_i7] = (*chartInstance->c4_H)[c4_i7];
  }

  c4_rescale(chartInstance, chartInstance->c4_dv, chartInstance->c4_varargin_1);
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv4, 10, 0U, 1, 0U, 2, 1, 3), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 27),
                false);
  c4_c_st.site = &c4_q_emlrtRSI;
  sf_mex_assign(&c4_s, c4_b_warning(chartInstance, &c4_c_st, c4_y, c4_b_y),
                false);
  c4_c_st.site = &c4_o_emlrtRSI;
  c4_stretchlim(chartInstance, &c4_c_st, chartInstance->c4_varargin_1,
                c4_lowhigh_in);
  c4_c_st.site = &c4_r_emlrtRSI;
  c4_c_warning(chartInstance, &c4_c_st, sf_mex_dup(c4_s));
  c4_lowIn = c4_lowhigh_in[0];
  c4_highIn = c4_lowhigh_in[1];
  c4_x = (c4_lowIn >= c4_highIn);
  c4_b_x = c4_x;
  if (!c4_b_x) {
    c4_b = true;
  } else {
    c4_b = false;
  }

  c4_c_y = !c4_b;
  if (c4_c_y) {
    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1, 40),
                  false);
    c4_e_y = NULL;
    sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1, 40),
                  false);
    sf_mex_call(&c4_b_st, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_d_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 1U, 14, c4_e_y)));
  }

  c4_fullRange = c4_lowIn;
  c4_c_varargin_1 = c4_fullRange;
  c4_c_x = c4_c_varargin_1;
  c4_d_x = c4_c_x;
  c4_e_x = c4_d_x;
  c4_f_x = c4_e_x;
  c4_g_x = c4_f_x;
  c4_minval = c4_g_x;
  if (c4_minval < 0.0) {
    c4_isInvalid = true;
  } else {
    c4_isInvalid = false;
  }

  c4_b_isInvalid = c4_isInvalid;
  if (c4_b_isInvalid) {
    c4_b1 = true;
  } else {
    c4_b_fullRange = c4_highIn;
    c4_d_varargin_1 = c4_b_fullRange;
    c4_h_x = c4_d_varargin_1;
    c4_i_x = c4_h_x;
    c4_j_x = c4_i_x;
    c4_k_x = c4_j_x;
    c4_l_x = c4_k_x;
    c4_b_minval = c4_l_x;
    if (c4_b_minval < 0.0) {
      c4_c_isInvalid = true;
    } else {
      c4_c_isInvalid = false;
    }

    c4_d_isInvalid = c4_c_isInvalid;
    if (c4_d_isInvalid) {
      c4_b1 = true;
    } else {
      c4_b1 = false;
    }
  }

  if (c4_b1) {
    c4_f_y = NULL;
    sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_cv6, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c4_g_y = NULL;
    sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv6, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c4_b_st, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_f_y, 14,
                sf_mex_call(&c4_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c4_b_st, NULL, "message", 1U, 1U, 14, c4_g_y)));
  }

  c4_c_st.site = &c4_p_emlrtRSI;
  c4_lIn = c4_lowIn;
  c4_hIn = c4_highIn;
  c4_b_lIn = c4_lIn;
  c4_b_hIn = c4_hIn;
  for (c4_b_i = 0; c4_b_i < 71820; c4_b_i++) {
    c4_c_i = (real_T)c4_b_i + 1.0;
    c4_e_varargin_1 = c4_b_hIn;
    c4_varargin_2 = chartInstance->c4_varargin_1[(int32_T)c4_c_i - 1];
    c4_m_x = c4_e_varargin_1;
    c4_j_y = c4_varargin_2;
    c4_n_x = c4_m_x;
    c4_k_y = c4_j_y;
    c4_o_x = c4_n_x;
    c4_m_y = c4_k_y;
    c4_a = c4_o_x;
    c4_b_b = c4_m_y;
    c4_p_x = c4_a;
    c4_o_y = c4_b_b;
    c4_q_x = c4_p_x;
    c4_q_y = c4_o_y;
    c4_c_minval = muDoubleScalarMin(c4_q_x, c4_q_y);
    c4_f_varargin_1 = c4_b_lIn;
    c4_b_varargin_2 = c4_c_minval;
    c4_r_x = c4_f_varargin_1;
    c4_s_y = c4_b_varargin_2;
    c4_s_x = c4_r_x;
    c4_t_y = c4_s_y;
    c4_t_x = c4_s_x;
    c4_v_y = c4_t_y;
    c4_b_a = c4_t_x;
    c4_c_b = c4_v_y;
    c4_u_x = c4_b_a;
    c4_x_y = c4_c_b;
    c4_v_x = c4_u_x;
    c4_ab_y = c4_x_y;
    c4_maxval = muDoubleScalarMax(c4_v_x, c4_ab_y);
    c4_c_a = (c4_maxval - c4_b_lIn) / (c4_b_hIn - c4_b_lIn);
    c4_d_a = c4_c_a;
    c4_e_a = c4_d_a;
    c4_f_a = c4_e_a;
    c4_g_a = c4_f_a;
    c4_c = c4_g_a;
    chartInstance->c4_outImg[(int32_T)c4_c_i - 1] = c4_c;
  }

  sf_mex_destroy(&c4_s);
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", chartInstance->c4_outImg, 0, 0U, 1,
    0U, 2, 399, 180), false);
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create_class_instance("coder.internal.string"),
                false);
  for (c4_i8 = 0; c4_i8 < 5; c4_i8++) {
    c4_u[c4_i8] = c4_r.Value[c4_i8];
  }

  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_u, 10, 0U, 1, 0U, 2, 1, 5), false);
  c4_propValues[0] = c4_l_y;
  sf_mex_set_all_properties(&c4_i_y, 0, 1, &c4_propNames[0], &c4_propClasses[0],
    &c4_propValues[0]);
  sf_mex_assign(&c4_i_y, sf_mex_convert_to_redirect_source(c4_i_y, 0,
    "coder.internal.string"), false);
  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", *chartInstance->c4_T, 0, 0U, 1, 0U,
    2, 1, 180), false);
  c4_p_y = NULL;
  sf_mex_assign(&c4_p_y, sf_mex_create_class_instance("coder.internal.string"),
                false);
  for (c4_i9 = 0; c4_i9 < 5; c4_i9++) {
    c4_u[c4_i9] = c4_r1.Value[c4_i9];
  }

  c4_r_y = NULL;
  sf_mex_assign(&c4_r_y, sf_mex_create("y", c4_u, 10, 0U, 1, 0U, 2, 1, 5), false);
  c4_b_propValues[0] = c4_r_y;
  sf_mex_set_all_properties(&c4_p_y, 0, 1, &c4_b_propNames[0],
    &c4_b_propClasses[0], &c4_b_propValues[0]);
  sf_mex_assign(&c4_p_y, sf_mex_convert_to_redirect_source(c4_p_y, 0,
    "coder.internal.string"), false);
  c4_u_y = NULL;
  sf_mex_assign(&c4_u_y, sf_mex_create("y", *chartInstance->c4_R, 0, 0U, 1, 0U,
    2, 1, 399), false);
  c4_w_y = NULL;
  sf_mex_assign(&c4_w_y, sf_mex_create_class_instance("coder.internal.string"),
                false);
  for (c4_i10 = 0; c4_i10 < 20; c4_i10++) {
    c4_b_u[c4_i10] = c4_r2.Value[c4_i10];
  }

  c4_y_y = NULL;
  sf_mex_assign(&c4_y_y, sf_mex_create("y", c4_b_u, 10, 0U, 1, 0U, 2, 1, 20),
                false);
  c4_c_propValues[0] = c4_y_y;
  sf_mex_set_all_properties(&c4_w_y, 0, 1, &c4_c_propNames[0],
    &c4_c_propClasses[0], &c4_c_propValues[0]);
  sf_mex_assign(&c4_w_y, sf_mex_convert_to_redirect_source(c4_w_y, 0,
    "coder.internal.string"), false);
  c4_bb_y = NULL;
  sf_mex_assign(&c4_bb_y, sf_mex_create_class_instance("coder.internal.string"),
                false);
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    c4_c_u[c4_i11] = c4_r3.Value[c4_i11];
  }

  c4_cb_y = NULL;
  sf_mex_assign(&c4_cb_y, sf_mex_create("y", c4_c_u, 10, 0U, 1, 0U, 2, 1, 3),
                false);
  c4_d_propValues[0] = c4_cb_y;
  sf_mex_set_all_properties(&c4_bb_y, 0, 1, &c4_d_propNames[0],
    &c4_d_propClasses[0], &c4_d_propValues[0]);
  sf_mex_assign(&c4_bb_y, sf_mex_convert_to_redirect_source(c4_bb_y, 0,
    "coder.internal.string"), false);
  c4_b_st.site = &c4_emlrtRSI;
  c4_imshow(chartInstance, &c4_b_st, c4_h_y, c4_i_y, c4_n_y, c4_p_y, c4_u_y,
            c4_w_y, c4_bb_y);
  for (c4_i12 = 0; c4_i12 < 15; c4_i12++) {
    c4_r4.Value[c4_i12] = c4_cv7[c4_i12];
  }

  c4_db_y = NULL;
  sf_mex_assign(&c4_db_y, sf_mex_create_class_instance("coder.internal.string"),
                false);
  for (c4_i13 = 0; c4_i13 < 15; c4_i13++) {
    c4_d_u[c4_i13] = c4_r4.Value[c4_i13];
  }

  c4_eb_y = NULL;
  sf_mex_assign(&c4_eb_y, sf_mex_create("y", c4_d_u, 10, 0U, 1, 0U, 2, 1, 15),
                false);
  c4_e_propValues[0] = c4_eb_y;
  sf_mex_set_all_properties(&c4_db_y, 0, 1, &c4_e_propNames[0],
    &c4_e_propClasses[0], &c4_e_propValues[0]);
  sf_mex_assign(&c4_db_y, sf_mex_convert_to_redirect_source(c4_db_y, 0,
    "coder.internal.string"), false);
  c4_b_st.site = &c4_b_emlrtRSI;
  c4_title(chartInstance, &c4_b_st, c4_db_y);
  for (c4_i14 = 0; c4_i14 < 6; c4_i14++) {
    c4_r5.Value[c4_i14] = c4_cv8[c4_i14];
  }

  c4_fb_y = NULL;
  sf_mex_assign(&c4_fb_y, sf_mex_create_class_instance("coder.internal.string"),
                false);
  for (c4_i15 = 0; c4_i15 < 6; c4_i15++) {
    c4_e_u[c4_i15] = c4_r5.Value[c4_i15];
  }

  c4_gb_y = NULL;
  sf_mex_assign(&c4_gb_y, sf_mex_create("y", c4_e_u, 10, 0U, 1, 0U, 2, 1, 6),
                false);
  c4_f_propValues[0] = c4_gb_y;
  sf_mex_set_all_properties(&c4_fb_y, 0, 1, &c4_f_propNames[0],
    &c4_f_propClasses[0], &c4_f_propValues[0]);
  sf_mex_assign(&c4_fb_y, sf_mex_convert_to_redirect_source(c4_fb_y, 0,
    "coder.internal.string"), false);
  c4_b_st.site = &c4_c_emlrtRSI;
  c4_xlabel(chartInstance, &c4_b_st, c4_fb_y);
  for (c4_i16 = 0; c4_i16 < 4; c4_i16++) {
    c4_r6.Value[c4_i16] = c4_cv9[c4_i16];
  }

  c4_hb_y = NULL;
  sf_mex_assign(&c4_hb_y, sf_mex_create_class_instance("coder.internal.string"),
                false);
  for (c4_i17 = 0; c4_i17 < 4; c4_i17++) {
    c4_f_u[c4_i17] = c4_r6.Value[c4_i17];
  }

  c4_ib_y = NULL;
  sf_mex_assign(&c4_ib_y, sf_mex_create("y", c4_f_u, 10, 0U, 1, 0U, 2, 1, 4),
                false);
  c4_g_propValues[0] = c4_ib_y;
  sf_mex_set_all_properties(&c4_hb_y, 0, 1, &c4_g_propNames[0],
    &c4_g_propClasses[0], &c4_g_propValues[0]);
  sf_mex_assign(&c4_hb_y, sf_mex_convert_to_redirect_source(c4_hb_y, 0,
    "coder.internal.string"), false);
  c4_b_st.site = &c4_d_emlrtRSI;
  c4_ylabel(chartInstance, &c4_b_st, c4_hb_y);
  c4_jb_y = NULL;
  sf_mex_assign(&c4_jb_y, sf_mex_create("y", c4_cv10, 10, 0U, 1, 0U, 2, 1, 2),
                false);
  c4_b_st.site = &c4_e_emlrtRSI;
  c4_axis(chartInstance, &c4_b_st, c4_jb_y);
  c4_kb_y = NULL;
  sf_mex_assign(&c4_kb_y, sf_mex_create("y", c4_cv11, 10, 0U, 1, 0U, 2, 1, 6),
                false);
  c4_b_st.site = &c4_f_emlrtRSI;
  c4_b_axis(chartInstance, &c4_b_st, c4_kb_y);
  c4_b_st.site = &c4_g_emlrtRSI;
  c4_colormap(chartInstance, &c4_b_st, c4_hot(chartInstance, &c4_b_st));
}

static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_jit_animation_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void c4_rescale(SFc4_flightControlSystemInstanceStruct *chartInstance,
  real_T c4_A[71820], real_T c4_b_R[71820])
{
  real_T c4_a;
  real_T c4_ab_x;
  real_T c4_b_a;
  real_T c4_b_e;
  real_T c4_b_ex;
  real_T c4_b_inputMax;
  real_T c4_b_inputMin;
  real_T c4_b_varargin_2;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_bb_x;
  real_T c4_c1;
  real_T c4_c2;
  real_T c4_c_a;
  real_T c4_c_varargin_1;
  real_T c4_c_varargin_2;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_cb_x;
  real_T c4_d;
  real_T c4_d_varargin_1;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_db_x;
  real_T c4_e;
  real_T c4_e1;
  real_T c4_e_b;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_eb_x;
  real_T c4_ex;
  real_T c4_f_b;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_fb_x;
  real_T c4_g_b;
  real_T c4_g_x;
  real_T c4_g_y;
  real_T c4_gb_x;
  real_T c4_h_x;
  real_T c4_h_y;
  real_T c4_hb_x;
  real_T c4_iMax;
  real_T c4_iMin;
  real_T c4_i_x;
  real_T c4_i_y;
  real_T c4_inputMax;
  real_T c4_inputMin;
  real_T c4_j_x;
  real_T c4_j_y;
  real_T c4_k_x;
  real_T c4_k_y;
  real_T c4_l_x;
  real_T c4_l_y;
  real_T c4_m_x;
  real_T c4_m_y;
  real_T c4_maxval;
  real_T c4_minval;
  real_T c4_n_x;
  real_T c4_n_y;
  real_T c4_o_x;
  real_T c4_o_y;
  real_T c4_p_x;
  real_T c4_p_y;
  real_T c4_q_x;
  real_T c4_r1;
  real_T c4_r3;
  real_T c4_r_x;
  real_T c4_s;
  real_T c4_s_x;
  real_T c4_sigma;
  real_T c4_t;
  real_T c4_t_x;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_varargin_2;
  real_T c4_w_x;
  real_T c4_x;
  real_T c4_x_x;
  real_T c4_y;
  real_T c4_y_x;
  real_T c4_z;
  int32_T c4_b_end;
  int32_T c4_b_first;
  int32_T c4_b_i;
  int32_T c4_b_idx;
  int32_T c4_b_k;
  int32_T c4_c_end;
  int32_T c4_c_i;
  int32_T c4_c_k;
  int32_T c4_d_i;
  int32_T c4_d_k;
  int32_T c4_eint;
  int32_T c4_end;
  int32_T c4_first;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_idx;
  int32_T c4_k;
  boolean_T c4_b;
  boolean_T c4_b1;
  boolean_T c4_b_b;
  boolean_T c4_b_p;
  boolean_T c4_c_b;
  boolean_T c4_c_p;
  boolean_T c4_d_b;
  boolean_T c4_d_p;
  boolean_T c4_exitg1;
  boolean_T c4_h_b;
  boolean_T c4_i_b;
  boolean_T c4_j_b;
  boolean_T c4_k_b;
  boolean_T c4_p;
  for (c4_i = 0; c4_i < 71820; c4_i++) {
    chartInstance->c4_b_varargin_1[c4_i] = c4_A[c4_i];
  }

  c4_x = chartInstance->c4_b_varargin_1[0];
  c4_b_x = c4_x;
  c4_b = muDoubleScalarIsNaN(c4_b_x);
  c4_p = !c4_b;
  if (c4_p) {
    c4_idx = 1;
  } else {
    c4_idx = 0;
    c4_k = 2;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_k < 71821)) {
      c4_c_x = chartInstance->c4_b_varargin_1[c4_k - 1];
      c4_d_x = c4_c_x;
      c4_b_b = muDoubleScalarIsNaN(c4_d_x);
      c4_b_p = !c4_b_b;
      if (c4_b_p) {
        c4_idx = c4_k;
        c4_exitg1 = true;
      } else {
        c4_k++;
      }
    }
  }

  if (c4_idx == 0) {
    c4_inputMin = chartInstance->c4_b_varargin_1[0];
  } else {
    c4_first = c4_idx - 1;
    c4_ex = chartInstance->c4_b_varargin_1[c4_first];
    c4_i1 = c4_first;
    for (c4_b_k = c4_i1 + 2; c4_b_k < 71821; c4_b_k++) {
      if (c4_ex > chartInstance->c4_b_varargin_1[c4_b_k - 1]) {
        c4_ex = chartInstance->c4_b_varargin_1[c4_b_k - 1];
      }
    }

    c4_inputMin = c4_ex;
  }

  for (c4_i2 = 0; c4_i2 < 71820; c4_i2++) {
    chartInstance->c4_b_varargin_1[c4_i2] = c4_A[c4_i2];
  }

  c4_e_x = chartInstance->c4_b_varargin_1[0];
  c4_f_x = c4_e_x;
  c4_c_b = muDoubleScalarIsNaN(c4_f_x);
  c4_c_p = !c4_c_b;
  if (c4_c_p) {
    c4_b_idx = 1;
  } else {
    c4_b_idx = 0;
    c4_c_k = 2;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_c_k < 71821)) {
      c4_g_x = chartInstance->c4_b_varargin_1[c4_c_k - 1];
      c4_h_x = c4_g_x;
      c4_d_b = muDoubleScalarIsNaN(c4_h_x);
      c4_d_p = !c4_d_b;
      if (c4_d_p) {
        c4_b_idx = c4_c_k;
        c4_exitg1 = true;
      } else {
        c4_c_k++;
      }
    }
  }

  if (c4_b_idx == 0) {
    c4_inputMax = chartInstance->c4_b_varargin_1[0];
  } else {
    c4_b_first = c4_b_idx - 1;
    c4_b_ex = chartInstance->c4_b_varargin_1[c4_b_first];
    c4_i3 = c4_b_first;
    for (c4_d_k = c4_i3 + 2; c4_d_k < 71821; c4_d_k++) {
      if (c4_b_ex < chartInstance->c4_b_varargin_1[c4_d_k - 1]) {
        c4_b_ex = chartInstance->c4_b_varargin_1[c4_d_k - 1];
      }
    }

    c4_inputMax = c4_b_ex;
  }

  c4_b_inputMin = c4_inputMin;
  c4_b_inputMax = c4_inputMax;
  for (c4_i4 = 0; c4_i4 < 71820; c4_i4++) {
    c4_b_R[c4_i4] = c4_A[c4_i4];
  }

  c4_varargin_2 = c4_b_inputMax;
  c4_y = c4_varargin_2;
  c4_b_y = c4_y;
  c4_c_y = c4_b_y;
  c4_e_b = c4_c_y;
  c4_d_y = c4_e_b;
  c4_e_y = c4_d_y;
  c4_minval = muDoubleScalarMin(0.0, c4_e_y);
  c4_c_varargin_1 = c4_minval;
  c4_b_varargin_2 = c4_b_inputMin;
  c4_i_x = c4_c_varargin_1;
  c4_f_y = c4_b_varargin_2;
  c4_j_x = c4_i_x;
  c4_g_y = c4_f_y;
  c4_k_x = c4_j_x;
  c4_h_y = c4_g_y;
  c4_a = c4_k_x;
  c4_f_b = c4_h_y;
  c4_l_x = c4_a;
  c4_i_y = c4_f_b;
  c4_m_x = c4_l_x;
  c4_j_y = c4_i_y;
  c4_sigma = muDoubleScalarMax(c4_m_x, c4_j_y);
  for (c4_i5 = 0; c4_i5 < 71820; c4_i5++) {
    c4_b_R[c4_i5] -= c4_sigma;
  }

  c4_iMin = c4_b_inputMin - c4_sigma;
  c4_iMax = c4_b_inputMax - c4_sigma;
  c4_n_x = c4_iMax;
  c4_o_x = c4_n_x;
  c4_p_x = c4_o_x;
  c4_d_varargin_1 = muDoubleScalarAbs(c4_p_x);
  c4_q_x = c4_iMin;
  c4_r_x = c4_q_x;
  c4_s_x = c4_r_x;
  c4_c_varargin_2 = muDoubleScalarAbs(c4_s_x);
  c4_t_x = c4_d_varargin_1;
  c4_k_y = c4_c_varargin_2;
  c4_u_x = c4_t_x;
  c4_l_y = c4_k_y;
  c4_v_x = c4_u_x;
  c4_m_y = c4_l_y;
  c4_b_a = c4_v_x;
  c4_g_b = c4_m_y;
  c4_w_x = c4_b_a;
  c4_n_y = c4_g_b;
  c4_x_x = c4_w_x;
  c4_o_y = c4_n_y;
  c4_maxval = muDoubleScalarMax(c4_x_x, c4_o_y);
  c4_y_x = c4_maxval;
  c4_ab_x = c4_y_x;
  c4_bb_x = c4_ab_x;
  c4_cb_x = c4_bb_x;
  c4_db_x = c4_cb_x;
  c4_eb_x = c4_db_x;
  c4_h_b = muDoubleScalarIsInf(c4_eb_x);
  c4_i_b = !c4_h_b;
  c4_fb_x = c4_db_x;
  c4_j_b = muDoubleScalarIsNaN(c4_fb_x);
  c4_b1 = !c4_j_b;
  c4_k_b = (c4_i_b && c4_b1);
  if (c4_k_b) {
    frexp(c4_cb_x, &c4_eint);
    c4_e = (real_T)c4_eint;
  } else {
    c4_e = 0.0;
  }

  c4_d = c4_e;
  c4_b_e = c4_d;
  c4_e1 = c4_b_e;
  c4_r1 = c4_pow2(chartInstance, c4_e1 - 1.0);
  c4_gb_x = (c4_e1 + 1.0) / 2.0;
  c4_hb_x = c4_gb_x;
  c4_p_y = c4_hb_x;
  c4_p_y = trunc(c4_p_y);
  c4_r3 = c4_pow2(chartInstance, c4_p_y - 1.0);
  if (c4_iMin == c4_iMax) {
    c4_end = 71820;
    for (c4_b_i = 0; c4_b_i < c4_end; c4_b_i++) {
      if (!muDoubleScalarIsNaN(c4_b_R[c4_b_i])) {
        c4_b_R[c4_b_i] = 0.0;
      }
    }
  } else {
    c4_c1 = c4_iMax / c4_r1;
    c4_c2 = c4_iMin / c4_r1;
    c4_z = (c4_c1 * 0.0 - c4_c2 * (1.0 / c4_r3)) / (c4_c1 - c4_c2);
    c4_c2 = c4_iMax / c4_r3 - c4_iMin / c4_r3;
    c4_s = 1.0 / c4_c2 / c4_r3;
    c4_t = c4_r3 * c4_z;
    c4_c_a = c4_s;
    for (c4_i6 = 0; c4_i6 < 71820; c4_i6++) {
      c4_b_R[c4_i6] *= c4_c_a;
    }

    for (c4_i7 = 0; c4_i7 < 71820; c4_i7++) {
      c4_b_R[c4_i7] += c4_t;
    }

    c4_b_end = 71820;
    for (c4_c_i = 0; c4_c_i < c4_b_end; c4_c_i++) {
      if (c4_b_R[c4_c_i] < 0.0) {
        c4_b_R[c4_c_i] = 0.0;
      }
    }

    c4_c_end = 71820;
    for (c4_d_i = 0; c4_d_i < c4_c_end; c4_d_i++) {
      if (c4_b_R[c4_d_i] > 1.0) {
        c4_b_R[c4_d_i] = 1.0;
      }
    }
  }
}

static real_T c4_pow2(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      real_T c4_a)
{
  real_T c4_b;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_c_b;
  real_T c4_d_b;
  real_T c4_x;
  (void)chartInstance;
  c4_x = c4_a;
  c4_b_a = c4_x;
  c4_b = c4_b_a;
  c4_b_b = c4_b;
  c4_c_b = c4_b_b;
  c4_d_b = c4_c_b;
  return muDoubleScalarPower(2.0, c4_d_b);
}

static void c4_stretchlim(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, real_T c4_c_varargin_1[71820], real_T c4_lowhigh[2])
{
  emlrtStack c4_st;
  real_T c4_b_idx;
  real_T c4_ihigh;
  real_T c4_ilow;
  real_T c4_s;
  real_T c4_y;
  int32_T c4_b_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_ib;
  int32_T c4_idx;
  int32_T c4_k;
  boolean_T c4_findHighFlag;
  boolean_T c4_findLowFlag;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_s_emlrtRSI;
  c4_imhist(chartInstance, &c4_st, c4_c_varargin_1, chartInstance->c4_N);
  for (c4_i = 0; c4_i < 65536; c4_i++) {
    chartInstance->c4_cdf[c4_i] = chartInstance->c4_N[c4_i];
  }

  for (c4_k = 0; c4_k < 65535; c4_k++) {
    c4_b_k = c4_k;
    chartInstance->c4_cdf[c4_b_k + 1] += chartInstance->c4_cdf[c4_b_k];
  }

  c4_s = c4_sumColumnB4(chartInstance, chartInstance->c4_N, 1);
  for (c4_ib = 0; c4_ib < 15; c4_ib++) {
    c4_s += c4_sumColumnB4(chartInstance, chartInstance->c4_N, 1 + ((c4_ib + 1) <<
      12));
  }

  c4_y = c4_s;
  for (c4_i1 = 0; c4_i1 < 65536; c4_i1++) {
    chartInstance->c4_cdf[c4_i1] /= c4_y;
  }

  c4_findLowFlag = true;
  c4_findHighFlag = true;
  c4_ilow = 0.0;
  c4_ihigh = 0.0;
  for (c4_idx = 0; c4_idx < 65536; c4_idx++) {
    c4_b_idx = (real_T)c4_idx + 1.0;
    if (c4_findLowFlag && (chartInstance->c4_cdf[(int32_T)c4_b_idx - 1] > 0.01))
    {
      c4_ilow = c4_b_idx;
      c4_findLowFlag = false;
    }

    if (c4_findHighFlag && (chartInstance->c4_cdf[(int32_T)c4_b_idx - 1] >= 0.99))
    {
      c4_ihigh = c4_b_idx;
      c4_findHighFlag = false;
    }
  }

  if (c4_ilow == c4_ihigh) {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_lowhigh[c4_i2] = 1.0 + 65535.0 * (real_T)c4_i2;
    }
  } else {
    c4_lowhigh[0] = c4_ilow;
    c4_lowhigh[1] = c4_ihigh;
  }

  for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
    c4_lowhigh[c4_i3] = (c4_lowhigh[c4_i3] - 1.0) / 65535.0;
  }
}

static void c4_imhist(SFc4_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c4_sp, real_T c4_c_varargin_1[71820],
                      real_T c4_yout[65536])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_a;
  real_T c4_b_a;
  real_T c4_b_i;
  real_T c4_b_x;
  real_T c4_idx;
  real_T c4_out;
  real_T c4_x;
  int32_T c4_b_c;
  int32_T c4_c;
  int32_T c4_i;
  boolean_T c4_b;
  boolean_T c4_b_b;
  boolean_T c4_nanFlag;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_st.site = &c4_t_emlrtRSI;
  c4_b_st.site = &c4_u_emlrtRSI;
  c4_out = 1.0;
  getnumcores(&c4_out);
  memset(&c4_yout[0], 0, sizeof(real_T) << 16);
  c4_nanFlag = false;
  for (c4_i = 0; c4_i < 71820; c4_i++) {
    c4_b_i = (real_T)c4_i + 1.0;
    c4_x = c4_c_varargin_1[(int32_T)c4_b_i - 1];
    c4_b = muDoubleScalarIsNaN(c4_x);
    if (c4_b) {
      c4_nanFlag = true;
      c4_idx = 0.0;
    } else {
      c4_idx = c4_c_varargin_1[(int32_T)c4_b_i - 1] * 65535.0 + 0.5;
    }

    if (c4_idx < 0.0) {
      c4_yout[0]++;
    } else if (c4_idx > 65535.0) {
      c4_yout[65535]++;
    } else {
      c4_b_x = c4_c_varargin_1[(int32_T)c4_b_i - 1];
      c4_b_b = muDoubleScalarIsInf(c4_b_x);
      if (c4_b_b) {
        c4_yout[65535]++;
      } else {
        c4_a = c4_idx;
        c4_c = (int32_T)c4_a;
        c4_b_a = c4_idx;
        c4_b_c = (int32_T)c4_b_a;
        c4_yout[c4_c] = c4_yout[c4_b_c] + 1.0;
      }
    }
  }

  if (c4_nanFlag) {
    c4_b_st.site = &c4_v_emlrtRSI;
    c4_warning(chartInstance, &c4_b_st);
  }
}

static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp)
{
  static char_T c4_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 27),
                false);
  c4_st.site = &c4_w_emlrtRSI;
  c4_b_feval(chartInstance, &c4_st, c4_y, c4_feval(chartInstance, &c4_st, c4_b_y,
              c4_c_y));
}

static real_T c4_sumColumnB4(SFc4_flightControlSystemInstanceStruct
  *chartInstance, real_T c4_x[65536], int32_T c4_vstart)
{
  real_T c4_psum1;
  real_T c4_psum2;
  real_T c4_psum3;
  real_T c4_psum4;
  int32_T c4_b_k;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_k;
  (void)chartInstance;
  c4_i2 = c4_vstart + 1023;
  c4_i3 = c4_vstart + 2047;
  c4_i4 = c4_vstart + 3071;
  c4_psum1 = c4_x[c4_vstart - 1];
  c4_psum2 = c4_x[c4_i2];
  c4_psum3 = c4_x[c4_i3];
  c4_psum4 = c4_x[c4_i4];
  for (c4_k = 0; c4_k < 1023; c4_k++) {
    c4_b_k = c4_k + 1;
    c4_psum1 += c4_x[(c4_vstart + c4_b_k) - 1];
    c4_psum2 += c4_x[c4_i2 + c4_b_k];
    c4_psum3 += c4_x[c4_i3 + c4_b_k];
    c4_psum4 += c4_x[c4_i4 + c4_b_k];
  }

  return (c4_psum1 + c4_psum2) + (c4_psum3 + c4_psum4);
}

const mxArray *sf_c4_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_imshow(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1, const mxArray *c4_input2, const mxArray *c4_input3, const
  mxArray *c4_input4, const mxArray *c4_input5, const mxArray *c4_input6)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "imshow", 0U, 7U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1), 14, sf_mex_dup(c4_input2), 14,
    sf_mex_dup(c4_input3), 14, sf_mex_dup(c4_input4), 14, sf_mex_dup(c4_input5),
    14, sf_mex_dup(c4_input6)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  sf_mex_destroy(&c4_input2);
  sf_mex_destroy(&c4_input3);
  sf_mex_destroy(&c4_input4);
  sf_mex_destroy(&c4_input5);
  sf_mex_destroy(&c4_input6);
  return c4_m;
}

static const mxArray *c4_title(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "title", 0U, 1U, 14, sf_mex_dup
    (c4_input0)), false);
  sf_mex_destroy(&c4_input0);
  return c4_m;
}

static const mxArray *c4_xlabel(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "xlabel", 0U, 1U, 14, sf_mex_dup
    (c4_input0)), false);
  sf_mex_destroy(&c4_input0);
  return c4_m;
}

static const mxArray *c4_ylabel(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "ylabel", 0U, 1U, 14, sf_mex_dup
    (c4_input0)), false);
  sf_mex_destroy(&c4_input0);
  return c4_m;
}

static const mxArray *c4_axis(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "axis", 0U, 1U, 14, sf_mex_dup
    (c4_input0)), false);
  sf_mex_destroy(&c4_input0);
  return c4_m;
}

static const mxArray *c4_b_axis(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "axis", 0U, 1U, 14, sf_mex_dup
    (c4_input0)), false);
  sf_mex_destroy(&c4_input0);
  return c4_m;
}

static const mxArray *c4_hot(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "hot", 1U, 0U), false);
  return c4_m;
}

static const mxArray *c4_colormap(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "colormap", 0U, 1U, 14,
    sf_mex_dup(c4_input0)), false);
  sf_mex_destroy(&c4_input0);
  return c4_m;
}

static const mxArray *c4_b_warning(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "warning", 1U, 2U, 14,
    sf_mex_dup(c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static const mxArray *c4_c_warning(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "warning", 0U, 1U, 14,
    sf_mex_dup(c4_input0)), false);
  sf_mex_destroy(&c4_input0);
  return c4_m;
}

static const mxArray *c4_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_b_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_H = (real_T (*)[71820])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_T = (real_T (*)[180])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_R = (real_T (*)[399])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(542019782U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1493521075U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(647085546U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1262128509U);
}

mxArray *sf_c4_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  return(mxcell3p);
}

mxArray *sf_c4_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("getnumcores");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCOAGI2IOYAYiYGCGCF8hmhfEa4OAtcXAGISyoLUkHixUXJnilAOi8xF8xPLK3"
    "wzEvLZwAA+RkJgQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "snomH0nBpPlaWbTLhCJkbIC";
}

static void sf_opaque_initialize_c4_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_flightControlSystem(void *chartInstanceVar)
{
  enable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_flightControlSystem(void *chartInstanceVar)
{
  disable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc4_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c4_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWE9v40QUn7RltaBltVwWDkhwhANSYeGG0LZOwga1NMLpLuKyTOxne5TxjHf+JA1XLhz5Lnw",
    "ZuPAxEEfeOE4aOSH1OELtYsmZPDu/ee/9/P45pDM4J3g8xPPXx4Tcw/U+ngdkcbxRyZ21c3H9iH",
    "xZycO3CIkyqsxAJJL4H5GMIQUR2iRhV55YYfMhVTTXLfQKmsN3oCW3hknhZzwTCSgQEW5QSGW89",
    "GqWW87EpG9F5DTrFxmLsjCTlsenuCGNLwSf/5vewpohauwyBZHpA8QmU9KmWZ/TdDcLysyCDKKJ",
    "trk3VxpMaAvnqj633LCCQ+8KooHQhiIL+gZ/Q0MNBObKO0KYDpdomRecUdGc64zqEAqMDgOXRYy",
    "fF9Ygew31or4xE9RIxSjv5TxwEd4QO+Ro5zmGNffm2eSmC2Obpkykjl1lcxDoP8ZJA66SQE5B0R",
    "QuhGcOOu96V+UDXsVl8xwcuLBslYM2XzwV3Qpb6u1NkSHdUm8/EgHlXPthR7I4gynwUn+XGtoCu",
    "9DvAdaaxSP5nCqXBZ6ZZAV7ZaHCBlLErPkTntZQZcH9FotnAzjLXUhBjDSvTF9tdFNMWm1kHmAa",
    "dc/OGurbxA6EAZXQCBrXPkWZBjS4jCtPvTHTdMwdGlkypZeNdwDRGkp0YkV3JtUEOfYtstdcuUz",
    "wQ0OcQhcMlAWjh9H9nHLb0OZcY4Vz4XGpsWL56UWsy59W4IhGGcSunzAO56DdBrpxfcY+coLeTp",
    "mZd0FHihVNM8lqiLGROJZG8wIuxUTImegrmYfVRLAjrgCwalAlsC2cYltS8z4a38xqBa9GLrLaj",
    "Gc5NZyOXWx8DQI7i/PVdUIaYVb1BI5uaNA+2JD9hK1daKYNjlPzXpkDcTmPvtfxm0ffqeQnq1wa",
    "6JHCJ0WxDQuclE7G5bAHI5ZDeSGkOFMsxOpweo/Jtd43D3brPcBvnZY4sifu2RruaAs/j9dwjyo",
    "5+vxlwlmauSJslOThHHnPN+140IDvbfbXcWQDd83zcv1oDd/ZopesrTfxdbjB1yHpdDol7uka7u",
    "2anqMa7l7F2ezjPy5++1H9kv58+udf8cv5PvFx3zOeH1by+8v5bNXBphtFvkk8vFuLBydrIfNnx",
    "+K0wJH1xXh0lgXfTMaDoNzve7LbXlKzd3n9QzwNFriyXqpoEFfvWk6mdvEO8Drk2W3l9W3a2STv",
    "D8l/Vy/uAm5f/3zr2ev+++MddYfUfv/oDvtRX9v2tbvm1+/Er+98UMlfrd45g4zxeMvUW93GwTT",
    "Zdvd/Et9/e/K37LM9x1/1p9kPT04E5XMccxevEdXloXL/16xuKaB6+7vEbfSh5fr0hrniQS2/nT",
    "xjIpYz/cmnn31xvE9f+we1CP1F",
    ""
  };

  static char newstr [1377] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c4_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1339631991U));
  ssSetChecksum1(S,(2289197235U));
  ssSetChecksum2(S,(3728900967U));
  ssSetChecksum3(S,(2036294902U));
}

static void mdlRTW_c4_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_flightControlSystem(SimStruct *S)
{
  SFc4_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc4_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc4_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c4_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_flightControlSystem;
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

  mdl_setup_runtime_resources_c4_flightControlSystem(chartInstance);
}

void c4_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
