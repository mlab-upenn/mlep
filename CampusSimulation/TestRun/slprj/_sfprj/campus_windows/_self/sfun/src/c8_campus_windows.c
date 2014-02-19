/* Include files */

#include "blascompat32.h"
#include "campus_windows_sfun.h"
#include "c8_campus_windows.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "campus_windows_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[17] = { "chillerFlow1", "chillerFlow2",
  "massFlowOff1", "massFlowHosp", "massFlowOff2", "totFlow", "MaxFlowOff1",
  "MaxFlowHosp", "MaxFlowOff2", "maxFlowHosp", "remFlow", "maxFlowOff1",
  "maxFlowOff2", "nargin", "nargout", "Inputs", "y" };

/* Function Declarations */
static void initialize_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance);
static void initialize_params_c8_campus_windows
  (SFc8_campus_windowsInstanceStruct *chartInstance);
static void enable_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance);
static void disable_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_campus_windows
  (SFc8_campus_windowsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_campus_windows
  (SFc8_campus_windowsInstanceStruct *chartInstance);
static void set_sim_state_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void finalize_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance);
static void sf_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance);
static void initSimStructsc8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct *chartInstance,
  const mxArray *c8_y, const char_T *c8_identifier, real_T c8_b_y[3]);
static void c8_b_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_d_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_e_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_campus_windows, const char_T *
  c8_identifier);
static uint8_T c8_f_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_campus_windowsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_campus_windows = 0U;
}

static void initialize_params_c8_campus_windows
  (SFc8_campus_windowsInstanceStruct *chartInstance)
{
}

static void enable_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_campus_windows
  (SFc8_campus_windowsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_campus_windows
  (SFc8_campus_windowsInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[3];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T (*c8_d_y)[3];
  c8_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2), FALSE);
  for (c8_i0 = 0; c8_i0 < 3; c8_i0++) {
    c8_u[c8_i0] = (*c8_d_y)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_campus_windows;
  c8_b_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv0[3];
  int32_T c8_i1;
  real_T (*c8_y)[3];
  c8_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)), "y",
                      c8_dv0);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    (*c8_y)[c8_i1] = c8_dv0[c8_i1];
  }

  chartInstance->c8_is_active_c8_campus_windows = c8_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_campus_windows");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_campus_windows(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void sf_c8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance)
{
  int32_T c8_i2;
  int32_T c8_i3;
  int32_T c8_i4;
  real_T c8_Inputs[5];
  uint32_T c8_debug_family_var_map[17];
  real_T c8_chillerFlow1;
  real_T c8_chillerFlow2;
  real_T c8_massFlowOff1;
  real_T c8_massFlowHosp;
  real_T c8_massFlowOff2;
  real_T c8_totFlow;
  real_T c8_MaxFlowOff1;
  real_T c8_MaxFlowHosp;
  real_T c8_MaxFlowOff2;
  real_T c8_maxFlowHosp;
  real_T c8_remFlow;
  real_T c8_maxFlowOff1;
  real_T c8_maxFlowOff2;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_y[3];
  real_T c8_A;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_b_A;
  real_T c8_c_x;
  real_T c8_d_x;
  int32_T c8_i5;
  real_T (*c8_b_y)[3];
  real_T (*c8_b_Inputs)[5];
  c8_b_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_Inputs = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i2 = 0; c8_i2 < 5; c8_i2++) {
    _SFD_DATA_RANGE_CHECK((*c8_b_Inputs)[c8_i2], 0U);
  }

  for (c8_i3 = 0; c8_i3 < 3; c8_i3++) {
    _SFD_DATA_RANGE_CHECK((*c8_b_y)[c8_i3], 1U);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i4 = 0; c8_i4 < 5; c8_i4++) {
    c8_Inputs[c8_i4] = (*c8_b_Inputs)[c8_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_chillerFlow1, 0U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_chillerFlow2, 1U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_massFlowOff1, 2U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_massFlowHosp, 3U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_massFlowOff2, 4U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_totFlow, 5U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_MaxFlowOff1, 6U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_MaxFlowHosp, 7U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_MaxFlowOff2, 8U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_maxFlowHosp, 9U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_remFlow, 10U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_maxFlowOff1, 11U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_maxFlowOff2, 12U,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 13U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 14U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c8_Inputs, 15U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c8_y, 16U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  c8_chillerFlow1 = c8_Inputs[0];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  c8_chillerFlow2 = c8_Inputs[1];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 9);
  c8_massFlowOff1 = c8_Inputs[2];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
  c8_massFlowHosp = c8_Inputs[3];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
  c8_massFlowOff2 = c8_Inputs[4];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
  c8_totFlow = c8_chillerFlow1 + c8_chillerFlow2;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 17);
  c8_MaxFlowOff1 = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 18);
  c8_MaxFlowHosp = 60.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 19);
  c8_MaxFlowOff2 = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 22);
  if (CV_EML_IF(0, 1, 0, c8_massFlowHosp > c8_totFlow)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 23);
    c8_maxFlowHosp = c8_totFlow;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 24);
    c8_remFlow = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 26);
    c8_maxFlowHosp = c8_massFlowHosp;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 27);
    c8_remFlow = c8_totFlow - c8_massFlowHosp;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 32);
  if (CV_EML_IF(0, 1, 1, c8_remFlow == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 33);
    c8_maxFlowOff1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 34);
    c8_maxFlowOff2 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 38);
    if (CV_EML_IF(0, 1, 2, c8_massFlowOff1 + c8_massFlowOff2 > c8_remFlow)) {
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 39);
      c8_A = c8_remFlow;
      c8_x = c8_A;
      c8_b_x = c8_x;
      c8_maxFlowOff1 = c8_b_x / 2.0;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 40);
      c8_b_A = c8_remFlow;
      c8_c_x = c8_b_A;
      c8_d_x = c8_c_x;
      c8_maxFlowOff2 = c8_d_x / 2.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 43);
      c8_maxFlowOff1 = c8_massFlowOff1;
      _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 44);
      c8_maxFlowOff2 = c8_massFlowOff2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 48);
  c8_maxFlowOff1 = c8_MaxFlowOff1;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 49);
  c8_maxFlowHosp = c8_MaxFlowHosp;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 50);
  c8_maxFlowOff2 = c8_MaxFlowOff2;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 53);
  c8_y[0] = c8_maxFlowOff1;
  c8_y[1] = c8_maxFlowHosp;
  c8_y[2] = c8_maxFlowOff2;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -53);
  sf_debug_symbol_scope_pop();
  for (c8_i5 = 0; c8_i5 < 3; c8_i5++) {
    (*c8_b_y)[c8_i5] = c8_y[c8_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  sf_debug_check_for_state_inconsistency(_campus_windowsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc8_campus_windows(SFc8_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i6;
  real_T c8_b_inData[3];
  int32_T c8_i7;
  real_T c8_u[3];
  const mxArray *c8_y = NULL;
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i6 = 0; c8_i6 < 3; c8_i6++) {
    c8_b_inData[c8_i6] = (*(real_T (*)[3])c8_inData)[c8_i6];
  }

  for (c8_i7 = 0; c8_i7 < 3; c8_i7++) {
    c8_u[c8_i7] = c8_b_inData[c8_i7];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct *chartInstance,
  const mxArray *c8_y, const char_T *c8_identifier, real_T c8_b_y[3])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_y), &c8_thisId, c8_b_y);
  sf_mex_destroy(&c8_y);
}

static void c8_b_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3])
{
  real_T c8_dv1[3];
  int32_T c8_i8;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv1, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c8_i8 = 0; c8_i8 < 3; c8_i8++) {
    c8_y[c8_i8] = c8_dv1[c8_i8];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_y;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_b_y[3];
  int32_T c8_i9;
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)chartInstanceVoid;
  c8_y = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_y), &c8_thisId, c8_b_y);
  sf_mex_destroy(&c8_y);
  for (c8_i9 = 0; c8_i9 < 3; c8_i9++) {
    (*(real_T (*)[3])c8_outData)[c8_i9] = c8_b_y[c8_i9];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i10;
  real_T c8_b_inData[5];
  int32_T c8_i11;
  real_T c8_u[5];
  const mxArray *c8_y = NULL;
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i10 = 0; c8_i10 < 5; c8_i10++) {
    c8_b_inData[c8_i10] = (*(real_T (*)[5])c8_inData)[c8_i10];
  }

  for (c8_i11 = 0; c8_i11 < 5; c8_i11++) {
    c8_u[c8_i11] = c8_b_inData[c8_i11];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_campus_windows_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[4];
  c8_ResolvedFunctionInfo (*c8_b_info)[4];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i12;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_b_info = (c8_ResolvedFunctionInfo (*)[4])c8_info;
  (*c8_b_info)[0].context = "";
  (*c8_b_info)[0].name = "mtimes";
  (*c8_b_info)[0].dominantType = "double";
  (*c8_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c8_b_info)[0].fileTimeLo = 1289552092U;
  (*c8_b_info)[0].fileTimeHi = 0U;
  (*c8_b_info)[0].mFileTimeLo = 0U;
  (*c8_b_info)[0].mFileTimeHi = 0U;
  (*c8_b_info)[1].context = "";
  (*c8_b_info)[1].name = "mrdivide";
  (*c8_b_info)[1].dominantType = "double";
  (*c8_b_info)[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c8_b_info)[1].fileTimeLo = 1325156538U;
  (*c8_b_info)[1].fileTimeHi = 0U;
  (*c8_b_info)[1].mFileTimeLo = 1319762366U;
  (*c8_b_info)[1].mFileTimeHi = 0U;
  (*c8_b_info)[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c8_b_info)[2].name = "rdivide";
  (*c8_b_info)[2].dominantType = "double";
  (*c8_b_info)[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c8_b_info)[2].fileTimeLo = 1286851244U;
  (*c8_b_info)[2].fileTimeHi = 0U;
  (*c8_b_info)[2].mFileTimeLo = 0U;
  (*c8_b_info)[2].mFileTimeHi = 0U;
  (*c8_b_info)[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c8_b_info)[3].name = "eml_div";
  (*c8_b_info)[3].dominantType = "double";
  (*c8_b_info)[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c8_b_info)[3].fileTimeLo = 1313380210U;
  (*c8_b_info)[3].fileTimeHi = 0U;
  (*c8_b_info)[3].mFileTimeLo = 0U;
  (*c8_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c8_i12 = 0; c8_i12 < 4; c8_i12++) {
    c8_r0 = &c8_info[c8_i12];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i12);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i12);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i12);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i12);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i12);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i12);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i12);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i12);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_d_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i13;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i13, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i13;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_e_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_campus_windows, const char_T *
  c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_campus_windows), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_campus_windows);
  return c8_y;
}

static uint8_T c8_f_emlrt_marshallIn(SFc8_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_campus_windowsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_campus_windows_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3947630047U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4260908738U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3162335108U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3699491836U);
}

mxArray *sf_c8_campus_windows_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PP4OraJcoRW3DASyRTSaCG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c8_campus_windows(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c8_campus_windows\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_campus_windows_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_campus_windowsInstanceStruct *chartInstance;
    chartInstance = (SFc8_campus_windowsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_campus_windowsMachineNumber_,
           8,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Inputs");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1051);
        _SFD_CV_INIT_EML_IF(0,1,0,352,377,422,515);
        _SFD_CV_INIT_EML_IF(0,1,1,543,558,613,914);
        _SFD_CV_INIT_EML_IF(0,1,2,653,693,787,910);
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
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          real_T (*c8_Inputs)[5];
          real_T (*c8_y)[3];
          c8_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c8_Inputs = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c8_Inputs);
          _SFD_SET_DATA_VALUE_PTR(1U, *c8_y);
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
  return "DIt7KPIUsr7lLh1Fi8jPCG";
}

static void sf_opaque_initialize_c8_campus_windows(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_campus_windowsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_campus_windows((SFc8_campus_windowsInstanceStruct*)
    chartInstanceVar);
  initialize_c8_campus_windows((SFc8_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_campus_windows(void *chartInstanceVar)
{
  enable_c8_campus_windows((SFc8_campus_windowsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_campus_windows(void *chartInstanceVar)
{
  disable_c8_campus_windows((SFc8_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_campus_windows(void *chartInstanceVar)
{
  sf_c8_campus_windows((SFc8_campus_windowsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_campus_windows(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_campus_windows
    ((SFc8_campus_windowsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_campus_windows();/* state var info */
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

extern void sf_internal_set_sim_state_c8_campus_windows(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_campus_windows();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_campus_windows((SFc8_campus_windowsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_campus_windows(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_campus_windows(S);
}

static void sf_opaque_set_sim_state_c8_campus_windows(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c8_campus_windows(S, st);
}

static void sf_opaque_terminate_c8_campus_windows(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_campus_windowsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_campus_windows((SFc8_campus_windowsInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_campus_windows_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_campus_windows((SFc8_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_campus_windows(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_campus_windows((SFc8_campus_windowsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_campus_windows_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2806708186U));
  ssSetChecksum1(S,(1971748324U));
  ssSetChecksum2(S,(2260691964U));
  ssSetChecksum3(S,(4118484209U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_campus_windows(SimStruct *S)
{
  SFc8_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc8_campus_windowsInstanceStruct *)malloc(sizeof
    (SFc8_campus_windowsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_campus_windowsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_campus_windows;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_campus_windows;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_campus_windows;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_campus_windows;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_campus_windows;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_campus_windows;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_campus_windows;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_campus_windows;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_campus_windows;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_campus_windows;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_campus_windows;
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

void c8_campus_windows_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_campus_windows(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_campus_windows(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_campus_windows(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_campus_windows_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
