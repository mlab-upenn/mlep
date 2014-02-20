/* Include files */

#include "blascompat32.h"
#include "campus_windows_sfun.h"
#include "c4_campus_windows.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "campus_windows_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[16] = { "nargin", "nargout", "u",
  "TotEnergy", "TotPower", "ChWMassFlow", "ChWLoad", "ChWInTemp", "ChWOutTemp",
  "PPD", "SummerComfort", "PipeSupplyInTemp", "PipeSupplyOutTemp",
  "PipeReturnInTemp", "PipeReturnOutTemp", "TempAverage" };

/* Function Declarations */
static void initialize_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance);
static void initialize_params_c4_campus_windows
  (SFc4_campus_windowsInstanceStruct *chartInstance);
static void enable_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance);
static void disable_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_campus_windows
  (SFc4_campus_windowsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_campus_windows
  (SFc4_campus_windowsInstanceStruct *chartInstance);
static void set_sim_state_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance);
static void sf_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance);
static void initSimStructsc4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_TempAverage, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_campus_windows, const char_T *
  c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_campus_windowsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_campus_windows = 0U;
}

static void initialize_params_c4_campus_windows
  (SFc4_campus_windowsInstanceStruct *chartInstance)
{
}

static void enable_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_campus_windows
  (SFc4_campus_windowsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_campus_windows
  (SFc4_campus_windowsInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_e_hoistedGlobal;
  real_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T c4_f_hoistedGlobal;
  real_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  real_T c4_h_hoistedGlobal;
  real_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  real_T c4_i_hoistedGlobal;
  real_T c4_i_u;
  const mxArray *c4_j_y = NULL;
  real_T c4_j_hoistedGlobal;
  real_T c4_j_u;
  const mxArray *c4_k_y = NULL;
  real_T c4_k_hoistedGlobal;
  real_T c4_k_u;
  const mxArray *c4_l_y = NULL;
  real_T c4_l_hoistedGlobal;
  real_T c4_l_u;
  const mxArray *c4_m_y = NULL;
  real_T c4_m_hoistedGlobal;
  real_T c4_m_u;
  const mxArray *c4_n_y = NULL;
  uint8_T c4_n_hoistedGlobal;
  uint8_T c4_n_u;
  const mxArray *c4_o_y = NULL;
  real_T *c4_ChWInTemp;
  real_T *c4_ChWLoad;
  real_T *c4_ChWMassFlow;
  real_T *c4_ChWOutTemp;
  real_T *c4_PPD;
  real_T *c4_PipeReturnInTemp;
  real_T *c4_PipeReturnOutTemp;
  real_T *c4_PipeSupplyInTemp;
  real_T *c4_PipeSupplyOutTemp;
  real_T *c4_SummerComfort;
  real_T *c4_TempAverage;
  real_T *c4_TotEnergy;
  real_T *c4_TotPower;
  c4_TempAverage = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c4_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c4_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c4_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c4_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c4_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c4_PPD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(14), FALSE);
  c4_hoistedGlobal = *c4_ChWInTemp;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_ChWLoad;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_ChWMassFlow;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_ChWOutTemp;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = *c4_PPD;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = *c4_PipeReturnInTemp;
  c4_f_u = c4_f_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_g_hoistedGlobal = *c4_PipeReturnOutTemp;
  c4_g_u = c4_g_hoistedGlobal;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_h_hoistedGlobal = *c4_PipeSupplyInTemp;
  c4_h_u = c4_h_hoistedGlobal;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_i_hoistedGlobal = *c4_PipeSupplyOutTemp;
  c4_i_u = c4_i_hoistedGlobal;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  c4_j_hoistedGlobal = *c4_SummerComfort;
  c4_j_u = c4_j_hoistedGlobal;
  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 9, c4_k_y);
  c4_k_hoistedGlobal = *c4_TempAverage;
  c4_k_u = c4_k_hoistedGlobal;
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 10, c4_l_y);
  c4_l_hoistedGlobal = *c4_TotEnergy;
  c4_l_u = c4_l_hoistedGlobal;
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_create("y", &c4_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 11, c4_m_y);
  c4_m_hoistedGlobal = *c4_TotPower;
  c4_m_u = c4_m_hoistedGlobal;
  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", &c4_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 12, c4_n_y);
  c4_n_hoistedGlobal = chartInstance->c4_is_active_c4_campus_windows;
  c4_n_u = c4_n_hoistedGlobal;
  c4_o_y = NULL;
  sf_mex_assign(&c4_o_y, sf_mex_create("y", &c4_n_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 13, c4_o_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_ChWInTemp;
  real_T *c4_ChWLoad;
  real_T *c4_ChWMassFlow;
  real_T *c4_ChWOutTemp;
  real_T *c4_PPD;
  real_T *c4_PipeReturnInTemp;
  real_T *c4_PipeReturnOutTemp;
  real_T *c4_PipeSupplyInTemp;
  real_T *c4_PipeSupplyOutTemp;
  real_T *c4_SummerComfort;
  real_T *c4_TempAverage;
  real_T *c4_TotEnergy;
  real_T *c4_TotPower;
  c4_TempAverage = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c4_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c4_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c4_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c4_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c4_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c4_PPD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_ChWInTemp = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 0)), "ChWInTemp");
  *c4_ChWLoad = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 1)), "ChWLoad");
  *c4_ChWMassFlow = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 2)), "ChWMassFlow");
  *c4_ChWOutTemp = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 3)), "ChWOutTemp");
  *c4_PPD = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
    "PPD");
  *c4_PipeReturnInTemp = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 5)), "PipeReturnInTemp");
  *c4_PipeReturnOutTemp = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 6)), "PipeReturnOutTemp");
  *c4_PipeSupplyInTemp = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 7)), "PipeSupplyInTemp");
  *c4_PipeSupplyOutTemp = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 8)), "PipeSupplyOutTemp");
  *c4_SummerComfort = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 9)), "SummerComfort");
  *c4_TempAverage = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 10)), "TempAverage");
  *c4_TotEnergy = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 11)), "TotEnergy");
  *c4_TotPower = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 12)), "TotPower");
  chartInstance->c4_is_active_c4_campus_windows = c4_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 13)),
     "is_active_c4_campus_windows");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_campus_windows(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void sf_c4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance)
{
  int32_T c4_i0;
  int32_T c4_i1;
  real_T c4_u[13];
  uint32_T c4_debug_family_var_map[16];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 13.0;
  real_T c4_TotEnergy;
  real_T c4_TotPower;
  real_T c4_ChWMassFlow;
  real_T c4_ChWLoad;
  real_T c4_ChWInTemp;
  real_T c4_ChWOutTemp;
  real_T c4_PPD;
  real_T c4_SummerComfort;
  real_T c4_PipeSupplyInTemp;
  real_T c4_PipeSupplyOutTemp;
  real_T c4_PipeReturnInTemp;
  real_T c4_PipeReturnOutTemp;
  real_T c4_TempAverage;
  real_T *c4_b_TotEnergy;
  real_T *c4_b_TotPower;
  real_T *c4_b_ChWMassFlow;
  real_T *c4_b_ChWLoad;
  real_T *c4_b_ChWInTemp;
  real_T *c4_b_ChWOutTemp;
  real_T *c4_b_PPD;
  real_T *c4_b_SummerComfort;
  real_T *c4_b_PipeSupplyInTemp;
  real_T *c4_b_PipeSupplyOutTemp;
  real_T *c4_b_PipeReturnInTemp;
  real_T *c4_b_PipeReturnOutTemp;
  real_T *c4_b_TempAverage;
  real_T (*c4_b_u)[13];
  c4_b_TempAverage = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c4_b_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c4_b_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c4_b_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c4_b_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c4_b_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c4_b_PPD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_b_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_b_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_b_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u = (real_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i0 = 0; c4_i0 < 13; c4_i0++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_u)[c4_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_b_TotEnergy, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_TotPower, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ChWMassFlow, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ChWLoad, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ChWInTemp, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ChWOutTemp, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_b_PPD, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_b_SummerComfort, 8U);
  _SFD_DATA_RANGE_CHECK(*c4_b_PipeSupplyInTemp, 9U);
  _SFD_DATA_RANGE_CHECK(*c4_b_PipeSupplyOutTemp, 10U);
  _SFD_DATA_RANGE_CHECK(*c4_b_PipeReturnInTemp, 11U);
  _SFD_DATA_RANGE_CHECK(*c4_b_PipeReturnOutTemp, 12U);
  _SFD_DATA_RANGE_CHECK(*c4_b_TempAverage, 13U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i1 = 0; c4_i1 < 13; c4_i1++) {
    c4_u[c4_i1] = (*c4_b_u)[c4_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c4_u, 2U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_TotEnergy, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_TotPower, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_ChWMassFlow, 5U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_ChWLoad, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_ChWInTemp, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_ChWOutTemp, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_PPD, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_SummerComfort, 10U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_PipeSupplyInTemp, 11U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_PipeSupplyOutTemp, 12U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_PipeReturnInTemp, 13U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_PipeReturnOutTemp, 14U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_TempAverage, 15U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_TotEnergy = c4_u[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_TotPower = c4_u[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_ChWMassFlow = c4_u[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_ChWLoad = c4_u[3];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_ChWInTemp = c4_u[4];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_ChWOutTemp = c4_u[5];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  c4_PPD = c4_u[6];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
  c4_SummerComfort = c4_u[7];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
  c4_PipeSupplyInTemp = c4_u[8];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
  c4_PipeSupplyOutTemp = c4_u[9];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
  c4_PipeReturnInTemp = c4_u[10];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
  c4_PipeReturnOutTemp = c4_u[11];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
  c4_TempAverage = c4_u[12];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -35);
  sf_debug_symbol_scope_pop();
  *c4_b_TotEnergy = c4_TotEnergy;
  *c4_b_TotPower = c4_TotPower;
  *c4_b_ChWMassFlow = c4_ChWMassFlow;
  *c4_b_ChWLoad = c4_ChWLoad;
  *c4_b_ChWInTemp = c4_ChWInTemp;
  *c4_b_ChWOutTemp = c4_ChWOutTemp;
  *c4_b_PPD = c4_PPD;
  *c4_b_SummerComfort = c4_SummerComfort;
  *c4_b_PipeSupplyInTemp = c4_PipeSupplyInTemp;
  *c4_b_PipeSupplyOutTemp = c4_PipeSupplyOutTemp;
  *c4_b_PipeReturnInTemp = c4_PipeReturnInTemp;
  *c4_b_PipeReturnOutTemp = c4_PipeReturnOutTemp;
  *c4_b_TempAverage = c4_TempAverage;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_campus_windowsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_campus_windows(SFc4_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc4_campus_windowsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_TempAverage, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_TempAverage),
    &c4_thisId);
  sf_mex_destroy(&c4_TempAverage);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_TempAverage;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc4_campus_windowsInstanceStruct *)chartInstanceVoid;
  c4_TempAverage = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_TempAverage),
    &c4_thisId);
  sf_mex_destroy(&c4_TempAverage);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i2;
  real_T c4_b_inData[13];
  int32_T c4_i3;
  real_T c4_u[13];
  const mxArray *c4_y = NULL;
  SFc4_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc4_campus_windowsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i2 = 0; c4_i2 < 13; c4_i2++) {
    c4_b_inData[c4_i2] = (*(real_T (*)[13])c4_inData)[c4_i2];
  }

  for (c4_i3 = 0; c4_i3 < 13; c4_i3++) {
    c4_u[c4_i3] = c4_b_inData[c4_i3];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 13), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_campus_windows_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc4_campus_windowsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i4;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i4, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i4;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc4_campus_windowsInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_campus_windows, const char_T *
  c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_campus_windows), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_campus_windows);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_campus_windowsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_campus_windows_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3867408979U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3745008621U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(308211266U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1455130651U);
}

mxArray *sf_c4_campus_windows_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TRo3AkQ08G0wTbkApWFG2C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c4_campus_windows(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[10],T\"ChWInTemp\",},{M[1],M[11],T\"ChWLoad\",},{M[1],M[8],T\"ChWMassFlow\",},{M[1],M[9],T\"ChWOutTemp\",},{M[1],M[16],T\"PPD\",},{M[1],M[22],T\"PipeReturnInTemp\",},{M[1],M[23],T\"PipeReturnOutTemp\",},{M[1],M[20],T\"PipeSupplyInTemp\",},{M[1],M[21],T\"PipeSupplyOutTemp\",},{M[1],M[17],T\"SummerComfort\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[24],T\"TempAverage\",},{M[1],M[5],T\"TotEnergy\",},{M[1],M[7],T\"TotPower\",},{M[8],M[0],T\"is_active_c4_campus_windows\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_campus_windows_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_campus_windowsInstanceStruct *chartInstance;
    chartInstance = (SFc4_campus_windowsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_campus_windowsMachineNumber_,
           4,
           1,
           1,
           14,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_campus_windowsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_campus_windowsMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_campus_windowsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"TotEnergy");
          _SFD_SET_DATA_PROPS(2,2,0,1,"TotPower");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ChWMassFlow");
          _SFD_SET_DATA_PROPS(4,2,0,1,"ChWLoad");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ChWInTemp");
          _SFD_SET_DATA_PROPS(6,2,0,1,"ChWOutTemp");
          _SFD_SET_DATA_PROPS(7,2,0,1,"PPD");
          _SFD_SET_DATA_PROPS(8,2,0,1,"SummerComfort");
          _SFD_SET_DATA_PROPS(9,2,0,1,"PipeSupplyInTemp");
          _SFD_SET_DATA_PROPS(10,2,0,1,"PipeSupplyOutTemp");
          _SFD_SET_DATA_PROPS(11,2,0,1,"PipeReturnInTemp");
          _SFD_SET_DATA_PROPS(12,2,0,1,"PipeReturnOutTemp");
          _SFD_SET_DATA_PROPS(13,2,0,1,"TempAverage");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,730);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_TotEnergy;
          real_T *c4_TotPower;
          real_T *c4_ChWMassFlow;
          real_T *c4_ChWLoad;
          real_T *c4_ChWInTemp;
          real_T *c4_ChWOutTemp;
          real_T *c4_PPD;
          real_T *c4_SummerComfort;
          real_T *c4_PipeSupplyInTemp;
          real_T *c4_PipeSupplyOutTemp;
          real_T *c4_PipeReturnInTemp;
          real_T *c4_PipeReturnOutTemp;
          real_T *c4_TempAverage;
          real_T (*c4_u)[13];
          c4_TempAverage = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c4_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 12);
          c4_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            11);
          c4_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 10);
          c4_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            9);
          c4_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c4_PPD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c4_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c4_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c4_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u = (real_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_TotEnergy);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_TotPower);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_ChWMassFlow);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_ChWLoad);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_ChWInTemp);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_ChWOutTemp);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_PPD);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_SummerComfort);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_PipeSupplyInTemp);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_PipeSupplyOutTemp);
          _SFD_SET_DATA_VALUE_PTR(11U, c4_PipeReturnInTemp);
          _SFD_SET_DATA_VALUE_PTR(12U, c4_PipeReturnOutTemp);
          _SFD_SET_DATA_VALUE_PTR(13U, c4_TempAverage);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_campus_windowsMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "em4d53728YdMGKdzRUalfH";
}

static void sf_opaque_initialize_c4_campus_windows(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_campus_windowsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_campus_windows((SFc4_campus_windowsInstanceStruct*)
    chartInstanceVar);
  initialize_c4_campus_windows((SFc4_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_campus_windows(void *chartInstanceVar)
{
  enable_c4_campus_windows((SFc4_campus_windowsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_campus_windows(void *chartInstanceVar)
{
  disable_c4_campus_windows((SFc4_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_campus_windows(void *chartInstanceVar)
{
  sf_c4_campus_windows((SFc4_campus_windowsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_campus_windows(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_campus_windows
    ((SFc4_campus_windowsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_campus_windows();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c4_campus_windows(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_campus_windows();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_campus_windows((SFc4_campus_windowsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_campus_windows(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_campus_windows(S);
}

static void sf_opaque_set_sim_state_c4_campus_windows(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_campus_windows(S, st);
}

static void sf_opaque_terminate_c4_campus_windows(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_campus_windowsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_campus_windows((SFc4_campus_windowsInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_campus_windows_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_campus_windows((SFc4_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_campus_windows(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_campus_windows((SFc4_campus_windowsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_campus_windows_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,13);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(759489042U));
  ssSetChecksum1(S,(1463421791U));
  ssSetChecksum2(S,(3927781681U));
  ssSetChecksum3(S,(73022700U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_campus_windows(SimStruct *S)
{
  SFc4_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc4_campus_windowsInstanceStruct *)malloc(sizeof
    (SFc4_campus_windowsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_campus_windowsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_campus_windows;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_campus_windows;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_campus_windows;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_campus_windows;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_campus_windows;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_campus_windows;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_campus_windows;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_campus_windows;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_campus_windows;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_campus_windows;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_campus_windows;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c4_campus_windows_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_campus_windows(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_campus_windows(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_campus_windows(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_campus_windows_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
