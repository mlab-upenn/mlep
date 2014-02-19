/* Include files */

#include "blascompat32.h"
#include "campus_windows_sfun.h"
#include "c7_campus_windows.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "campus_windows_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[14] = { "nargin", "nargout", "u",
  "TotEnergy", "TotPower", "ChWMassFlow", "ChWLoad", "ChWInTemp", "ChWOutTemp",
  "SummerComfort", "PipeSupplyInTemp", "PipeSupplyOutTemp", "PipeReturnInTemp",
  "PipeReturnOutTemp" };

/* Function Declarations */
static void initialize_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance);
static void initialize_params_c7_campus_windows
  (SFc7_campus_windowsInstanceStruct *chartInstance);
static void enable_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance);
static void disable_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance);
static void c7_update_debugger_state_c7_campus_windows
  (SFc7_campus_windowsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_campus_windows
  (SFc7_campus_windowsInstanceStruct *chartInstance);
static void set_sim_state_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance);
static void sf_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance);
static void initSimStructsc7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_PipeReturnOutTemp, const char_T
  *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_c_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_d_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_campus_windows, const char_T *
  c7_identifier);
static uint8_T c7_e_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_campus_windowsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_campus_windows = 0U;
}

static void initialize_params_c7_campus_windows
  (SFc7_campus_windowsInstanceStruct *chartInstance)
{
}

static void enable_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_campus_windows
  (SFc7_campus_windowsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c7_campus_windows
  (SFc7_campus_windowsInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_d_hoistedGlobal;
  real_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  real_T c7_e_hoistedGlobal;
  real_T c7_e_u;
  const mxArray *c7_f_y = NULL;
  real_T c7_f_hoistedGlobal;
  real_T c7_f_u;
  const mxArray *c7_g_y = NULL;
  real_T c7_g_hoistedGlobal;
  real_T c7_g_u;
  const mxArray *c7_h_y = NULL;
  real_T c7_h_hoistedGlobal;
  real_T c7_h_u;
  const mxArray *c7_i_y = NULL;
  real_T c7_i_hoistedGlobal;
  real_T c7_i_u;
  const mxArray *c7_j_y = NULL;
  real_T c7_j_hoistedGlobal;
  real_T c7_j_u;
  const mxArray *c7_k_y = NULL;
  real_T c7_k_hoistedGlobal;
  real_T c7_k_u;
  const mxArray *c7_l_y = NULL;
  uint8_T c7_l_hoistedGlobal;
  uint8_T c7_l_u;
  const mxArray *c7_m_y = NULL;
  real_T *c7_ChWInTemp;
  real_T *c7_ChWLoad;
  real_T *c7_ChWMassFlow;
  real_T *c7_ChWOutTemp;
  real_T *c7_PipeReturnInTemp;
  real_T *c7_PipeReturnOutTemp;
  real_T *c7_PipeSupplyInTemp;
  real_T *c7_PipeSupplyOutTemp;
  real_T *c7_SummerComfort;
  real_T *c7_TotEnergy;
  real_T *c7_TotPower;
  c7_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c7_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c7_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c7_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c7_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(12), FALSE);
  c7_hoistedGlobal = *c7_ChWInTemp;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *c7_ChWLoad;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *c7_ChWMassFlow;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = *c7_ChWOutTemp;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_e_hoistedGlobal = *c7_PipeReturnInTemp;
  c7_e_u = c7_e_hoistedGlobal;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_f_hoistedGlobal = *c7_PipeReturnOutTemp;
  c7_f_u = c7_f_hoistedGlobal;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_g_hoistedGlobal = *c7_PipeSupplyInTemp;
  c7_g_u = c7_g_hoistedGlobal;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 6, c7_h_y);
  c7_h_hoistedGlobal = *c7_PipeSupplyOutTemp;
  c7_h_u = c7_h_hoistedGlobal;
  c7_i_y = NULL;
  sf_mex_assign(&c7_i_y, sf_mex_create("y", &c7_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 7, c7_i_y);
  c7_i_hoistedGlobal = *c7_SummerComfort;
  c7_i_u = c7_i_hoistedGlobal;
  c7_j_y = NULL;
  sf_mex_assign(&c7_j_y, sf_mex_create("y", &c7_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 8, c7_j_y);
  c7_j_hoistedGlobal = *c7_TotEnergy;
  c7_j_u = c7_j_hoistedGlobal;
  c7_k_y = NULL;
  sf_mex_assign(&c7_k_y, sf_mex_create("y", &c7_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 9, c7_k_y);
  c7_k_hoistedGlobal = *c7_TotPower;
  c7_k_u = c7_k_hoistedGlobal;
  c7_l_y = NULL;
  sf_mex_assign(&c7_l_y, sf_mex_create("y", &c7_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 10, c7_l_y);
  c7_l_hoistedGlobal = chartInstance->c7_is_active_c7_campus_windows;
  c7_l_u = c7_l_hoistedGlobal;
  c7_m_y = NULL;
  sf_mex_assign(&c7_m_y, sf_mex_create("y", &c7_l_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 11, c7_m_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_ChWInTemp;
  real_T *c7_ChWLoad;
  real_T *c7_ChWMassFlow;
  real_T *c7_ChWOutTemp;
  real_T *c7_PipeReturnInTemp;
  real_T *c7_PipeReturnOutTemp;
  real_T *c7_PipeSupplyInTemp;
  real_T *c7_PipeSupplyOutTemp;
  real_T *c7_SummerComfort;
  real_T *c7_TotEnergy;
  real_T *c7_TotPower;
  c7_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c7_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c7_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c7_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c7_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_ChWInTemp = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 0)), "ChWInTemp");
  *c7_ChWLoad = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 1)), "ChWLoad");
  *c7_ChWMassFlow = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 2)), "ChWMassFlow");
  *c7_ChWOutTemp = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 3)), "ChWOutTemp");
  *c7_PipeReturnInTemp = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 4)), "PipeReturnInTemp");
  *c7_PipeReturnOutTemp = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 5)), "PipeReturnOutTemp");
  *c7_PipeSupplyInTemp = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 6)), "PipeSupplyInTemp");
  *c7_PipeSupplyOutTemp = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 7)), "PipeSupplyOutTemp");
  *c7_SummerComfort = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 8)), "SummerComfort");
  *c7_TotEnergy = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 9)), "TotEnergy");
  *c7_TotPower = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 10)), "TotPower");
  chartInstance->c7_is_active_c7_campus_windows = c7_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 11)),
     "is_active_c7_campus_windows");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_campus_windows(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void sf_c7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance)
{
  int32_T c7_i0;
  int32_T c7_i1;
  real_T c7_u[11];
  uint32_T c7_debug_family_var_map[14];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 11.0;
  real_T c7_TotEnergy;
  real_T c7_TotPower;
  real_T c7_ChWMassFlow;
  real_T c7_ChWLoad;
  real_T c7_ChWInTemp;
  real_T c7_ChWOutTemp;
  real_T c7_SummerComfort;
  real_T c7_PipeSupplyInTemp;
  real_T c7_PipeSupplyOutTemp;
  real_T c7_PipeReturnInTemp;
  real_T c7_PipeReturnOutTemp;
  real_T *c7_b_TotEnergy;
  real_T *c7_b_TotPower;
  real_T *c7_b_ChWMassFlow;
  real_T *c7_b_ChWLoad;
  real_T *c7_b_ChWInTemp;
  real_T *c7_b_ChWOutTemp;
  real_T *c7_b_SummerComfort;
  real_T *c7_b_PipeSupplyInTemp;
  real_T *c7_b_PipeSupplyOutTemp;
  real_T *c7_b_PipeReturnInTemp;
  real_T *c7_b_PipeReturnOutTemp;
  real_T (*c7_b_u)[11];
  c7_b_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c7_b_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c7_b_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c7_b_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c7_b_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_b_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_b_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_b_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_b_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_b_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_b_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_u = (real_T (*)[11])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i0 = 0; c7_i0 < 11; c7_i0++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_u)[c7_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c7_b_TotEnergy, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_b_TotPower, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_b_ChWMassFlow, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_b_ChWLoad, 4U);
  _SFD_DATA_RANGE_CHECK(*c7_b_ChWInTemp, 5U);
  _SFD_DATA_RANGE_CHECK(*c7_b_ChWOutTemp, 6U);
  _SFD_DATA_RANGE_CHECK(*c7_b_SummerComfort, 7U);
  _SFD_DATA_RANGE_CHECK(*c7_b_PipeSupplyInTemp, 8U);
  _SFD_DATA_RANGE_CHECK(*c7_b_PipeSupplyOutTemp, 9U);
  _SFD_DATA_RANGE_CHECK(*c7_b_PipeReturnInTemp, 10U);
  _SFD_DATA_RANGE_CHECK(*c7_b_PipeReturnOutTemp, 11U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i1 = 0; c7_i1 < 11; c7_i1++) {
    c7_u[c7_i1] = (*c7_b_u)[c7_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c7_u, 2U, c7_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_TotEnergy, 3U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_TotPower, 4U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_ChWMassFlow, 5U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_ChWLoad, 6U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_ChWInTemp, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_ChWOutTemp, 8U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_SummerComfort, 9U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_PipeSupplyInTemp, 10U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_PipeSupplyOutTemp, 11U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_PipeReturnInTemp, 12U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_PipeReturnOutTemp, 13U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  c7_TotEnergy = c7_u[0];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_TotPower = c7_u[1];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  c7_ChWMassFlow = c7_u[2];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_ChWLoad = c7_u[3];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  c7_ChWInTemp = c7_u[4];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
  c7_ChWOutTemp = c7_u[5];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
  c7_SummerComfort = c7_u[6];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 23);
  c7_PipeSupplyInTemp = c7_u[7];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 25);
  c7_PipeSupplyOutTemp = c7_u[8];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
  c7_PipeReturnInTemp = c7_u[9];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 29);
  c7_PipeReturnOutTemp = c7_u[10];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -29);
  sf_debug_symbol_scope_pop();
  *c7_b_TotEnergy = c7_TotEnergy;
  *c7_b_TotPower = c7_TotPower;
  *c7_b_ChWMassFlow = c7_ChWMassFlow;
  *c7_b_ChWLoad = c7_ChWLoad;
  *c7_b_ChWInTemp = c7_ChWInTemp;
  *c7_b_ChWOutTemp = c7_ChWOutTemp;
  *c7_b_SummerComfort = c7_SummerComfort;
  *c7_b_PipeSupplyInTemp = c7_PipeSupplyInTemp;
  *c7_b_PipeSupplyOutTemp = c7_PipeSupplyOutTemp;
  *c7_b_PipeReturnInTemp = c7_PipeReturnInTemp;
  *c7_b_PipeReturnOutTemp = c7_PipeReturnOutTemp;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  sf_debug_check_for_state_inconsistency(_campus_windowsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_campus_windows(SFc7_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc7_campus_windowsInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_PipeReturnOutTemp, const char_T
  *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_PipeReturnOutTemp),
    &c7_thisId);
  sf_mex_destroy(&c7_PipeReturnOutTemp);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_PipeReturnOutTemp;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc7_campus_windowsInstanceStruct *)chartInstanceVoid;
  c7_PipeReturnOutTemp = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_PipeReturnOutTemp),
    &c7_thisId);
  sf_mex_destroy(&c7_PipeReturnOutTemp);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i2;
  real_T c7_b_inData[11];
  int32_T c7_i3;
  real_T c7_u[11];
  const mxArray *c7_y = NULL;
  SFc7_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc7_campus_windowsInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i2 = 0; c7_i2 < 11; c7_i2++) {
    c7_b_inData[c7_i2] = (*(real_T (*)[11])c7_inData)[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 11; c7_i3++) {
    c7_u[c7_i3] = c7_b_inData[c7_i3];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 11), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

const mxArray *sf_c7_campus_windows_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc7_campus_windowsInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_c_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i4;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i4, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i4;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc7_campus_windowsInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_campus_windows, const char_T *
  c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_campus_windows), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_campus_windows);
  return c7_y;
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_campus_windowsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_campus_windows_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1038183393U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3962939716U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2624527742U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1526244193U);
}

mxArray *sf_c7_campus_windows_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nr4eiF2EQu5DMrKsLrsW2G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(11);
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

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c7_campus_windows(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[19],T\"ChWInTemp\",},{M[1],M[18],T\"ChWLoad\",},{M[1],M[17],T\"ChWMassFlow\",},{M[1],M[20],T\"ChWOutTemp\",},{M[1],M[24],T\"PipeReturnInTemp\",},{M[1],M[25],T\"PipeReturnOutTemp\",},{M[1],M[22],T\"PipeSupplyInTemp\",},{M[1],M[23],T\"PipeSupplyOutTemp\",},{M[1],M[21],T\"SummerComfort\",},{M[1],M[5],T\"TotEnergy\",}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"TotPower\",},{M[8],M[0],T\"is_active_c7_campus_windows\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 12, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_campus_windows_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_campus_windowsInstanceStruct *chartInstance;
    chartInstance = (SFc7_campus_windowsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_campus_windowsMachineNumber_,
           7,
           1,
           1,
           12,
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
          _SFD_SET_DATA_PROPS(7,2,0,1,"SummerComfort");
          _SFD_SET_DATA_PROPS(8,2,0,1,"PipeSupplyInTemp");
          _SFD_SET_DATA_PROPS(9,2,0,1,"PipeSupplyOutTemp");
          _SFD_SET_DATA_PROPS(10,2,0,1,"PipeReturnInTemp");
          _SFD_SET_DATA_PROPS(11,2,0,1,"PipeReturnOutTemp");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,638);
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
          dimVector[0]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);

        {
          real_T *c7_TotEnergy;
          real_T *c7_TotPower;
          real_T *c7_ChWMassFlow;
          real_T *c7_ChWLoad;
          real_T *c7_ChWInTemp;
          real_T *c7_ChWOutTemp;
          real_T *c7_SummerComfort;
          real_T *c7_PipeSupplyInTemp;
          real_T *c7_PipeSupplyOutTemp;
          real_T *c7_PipeReturnInTemp;
          real_T *c7_PipeReturnOutTemp;
          real_T (*c7_u)[11];
          c7_PipeReturnOutTemp = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 11);
          c7_PipeReturnInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            10);
          c7_PipeSupplyOutTemp = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 9);
          c7_PipeSupplyInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            8);
          c7_SummerComfort = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c7_ChWOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c7_ChWInTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c7_ChWLoad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c7_ChWMassFlow = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c7_TotPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c7_TotEnergy = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_u = (real_T (*)[11])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_TotEnergy);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_TotPower);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_ChWMassFlow);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_ChWLoad);
          _SFD_SET_DATA_VALUE_PTR(5U, c7_ChWInTemp);
          _SFD_SET_DATA_VALUE_PTR(6U, c7_ChWOutTemp);
          _SFD_SET_DATA_VALUE_PTR(7U, c7_SummerComfort);
          _SFD_SET_DATA_VALUE_PTR(8U, c7_PipeSupplyInTemp);
          _SFD_SET_DATA_VALUE_PTR(9U, c7_PipeSupplyOutTemp);
          _SFD_SET_DATA_VALUE_PTR(10U, c7_PipeReturnInTemp);
          _SFD_SET_DATA_VALUE_PTR(11U, c7_PipeReturnOutTemp);
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
  return "nY1iwc9KwLoKGEua8XE3GD";
}

static void sf_opaque_initialize_c7_campus_windows(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_campus_windowsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_campus_windows((SFc7_campus_windowsInstanceStruct*)
    chartInstanceVar);
  initialize_c7_campus_windows((SFc7_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_campus_windows(void *chartInstanceVar)
{
  enable_c7_campus_windows((SFc7_campus_windowsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_campus_windows(void *chartInstanceVar)
{
  disable_c7_campus_windows((SFc7_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_campus_windows(void *chartInstanceVar)
{
  sf_c7_campus_windows((SFc7_campus_windowsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_campus_windows(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_campus_windows
    ((SFc7_campus_windowsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_campus_windows();/* state var info */
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

extern void sf_internal_set_sim_state_c7_campus_windows(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_campus_windows();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_campus_windows((SFc7_campus_windowsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_campus_windows(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_campus_windows(S);
}

static void sf_opaque_set_sim_state_c7_campus_windows(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c7_campus_windows(S, st);
}

static void sf_opaque_terminate_c7_campus_windows(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_campus_windowsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_campus_windows((SFc7_campus_windowsInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_campus_windows_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_campus_windows((SFc7_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_campus_windows(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_campus_windows((SFc7_campus_windowsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_campus_windows_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,11);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(435321152U));
  ssSetChecksum1(S,(2233530204U));
  ssSetChecksum2(S,(936276126U));
  ssSetChecksum3(S,(2874423692U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_campus_windows(SimStruct *S)
{
  SFc7_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc7_campus_windowsInstanceStruct *)malloc(sizeof
    (SFc7_campus_windowsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_campus_windowsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_campus_windows;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_campus_windows;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_campus_windows;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_campus_windows;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_campus_windows;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_campus_windows;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_campus_windows;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_campus_windows;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_campus_windows;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_campus_windows;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_campus_windows;
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

void c7_campus_windows_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_campus_windows(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_campus_windows(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_campus_windows(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_campus_windows_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
