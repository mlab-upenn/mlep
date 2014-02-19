/* Include files */

#include "blascompat32.h"
#include "campus_windows_sfun.h"
#include "c3_campus_windows.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "campus_windows_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[23] = { "nargin", "nargout", "u",
  "Tout", "Ch1Power", "Ch2Power", "Ch1InTemp", "Ch1FlowTemp", "Ch1OutTemp",
  "Ch2InTemp", "Ch2FlowTemp", "Ch2OutTemp", "ChWaterOutTemp", "ChillPumpPower",
  "CondPumpPower", "TowerPower", "ChillerPLR", "Load1InTemp", "Load1OutTemp",
  "Load2InTemp", "Load2OutTemp", "Load3InTemp", "Load3OutTemp" };

/* Function Declarations */
static void initialize_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance);
static void initialize_params_c3_campus_windows
  (SFc3_campus_windowsInstanceStruct *chartInstance);
static void enable_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance);
static void disable_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_campus_windows
  (SFc3_campus_windowsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_campus_windows
  (SFc3_campus_windowsInstanceStruct *chartInstance);
static void set_sim_state_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance);
static void sf_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance);
static void initSimStructsc3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_Load3OutTemp, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_campus_windows, const char_T *
  c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_campus_windowsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_campus_windows = 0U;
}

static void initialize_params_c3_campus_windows
  (SFc3_campus_windowsInstanceStruct *chartInstance)
{
}

static void enable_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_campus_windows
  (SFc3_campus_windowsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_campus_windows
  (SFc3_campus_windowsInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_h_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_j_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_k_hoistedGlobal;
  real_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_l_hoistedGlobal;
  real_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  real_T c3_m_hoistedGlobal;
  real_T c3_m_u;
  const mxArray *c3_n_y = NULL;
  real_T c3_n_hoistedGlobal;
  real_T c3_n_u;
  const mxArray *c3_o_y = NULL;
  real_T c3_o_hoistedGlobal;
  real_T c3_o_u;
  const mxArray *c3_p_y = NULL;
  real_T c3_p_hoistedGlobal;
  real_T c3_p_u;
  const mxArray *c3_q_y = NULL;
  real_T c3_q_hoistedGlobal;
  real_T c3_q_u;
  const mxArray *c3_r_y = NULL;
  real_T c3_r_hoistedGlobal;
  real_T c3_r_u;
  const mxArray *c3_s_y = NULL;
  real_T c3_s_hoistedGlobal;
  real_T c3_s_u;
  const mxArray *c3_t_y = NULL;
  real_T c3_t_hoistedGlobal;
  real_T c3_t_u;
  const mxArray *c3_u_y = NULL;
  uint8_T c3_u_hoistedGlobal;
  uint8_T c3_u_u;
  const mxArray *c3_v_y = NULL;
  real_T *c3_Ch1FlowTemp;
  real_T *c3_Ch1InTemp;
  real_T *c3_Ch1OutTemp;
  real_T *c3_Ch1Power;
  real_T *c3_Ch2FlowTemp;
  real_T *c3_Ch2InTemp;
  real_T *c3_Ch2OutTemp;
  real_T *c3_Ch2Power;
  real_T *c3_ChWaterOutTemp;
  real_T *c3_ChillPumpPower;
  real_T *c3_ChillerPLR;
  real_T *c3_CondPumpPower;
  real_T *c3_Load1InTemp;
  real_T *c3_Load1OutTemp;
  real_T *c3_Load2InTemp;
  real_T *c3_Load2OutTemp;
  real_T *c3_Load3InTemp;
  real_T *c3_Load3OutTemp;
  real_T *c3_Tout;
  real_T *c3_TowerPower;
  c3_Load3OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c3_Load3InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c3_Load2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c3_Load2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c3_Load1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c3_Load1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c3_ChillerPLR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c3_TowerPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c3_CondPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c3_ChillPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c3_ChWaterOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_Ch2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_Ch2FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_Ch2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_Ch1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_Ch1FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Ch1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_Ch2Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Ch1Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(21), FALSE);
  c3_hoistedGlobal = *c3_Ch1FlowTemp;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_Ch1InTemp;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_Ch1OutTemp;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_Ch1Power;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_Ch2FlowTemp;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_Ch2InTemp;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *c3_Ch2OutTemp;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *c3_Ch2Power;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *c3_ChWaterOutTemp;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = *c3_ChillPumpPower;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = *c3_ChillerPLR;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_l_hoistedGlobal = *c3_CondPumpPower;
  c3_l_u = c3_l_hoistedGlobal;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_m_hoistedGlobal = *c3_Load1InTemp;
  c3_m_u = c3_m_hoistedGlobal;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_n_hoistedGlobal = *c3_Load1OutTemp;
  c3_n_u = c3_n_hoistedGlobal;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_o_hoistedGlobal = *c3_Load2InTemp;
  c3_o_u = c3_o_hoistedGlobal;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_p_hoistedGlobal = *c3_Load2OutTemp;
  c3_p_u = c3_p_hoistedGlobal;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_q_hoistedGlobal = *c3_Load3InTemp;
  c3_q_u = c3_q_hoistedGlobal;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_q_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_r_hoistedGlobal = *c3_Load3OutTemp;
  c3_r_u = c3_r_hoistedGlobal;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_s_hoistedGlobal = *c3_Tout;
  c3_s_u = c3_s_hoistedGlobal;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_s_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_t_hoistedGlobal = *c3_TowerPower;
  c3_t_u = c3_t_hoistedGlobal;
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_t_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 19, c3_u_y);
  c3_u_hoistedGlobal = chartInstance->c3_is_active_c3_campus_windows;
  c3_u_u = c3_u_hoistedGlobal;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_u_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 20, c3_v_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_Ch1FlowTemp;
  real_T *c3_Ch1InTemp;
  real_T *c3_Ch1OutTemp;
  real_T *c3_Ch1Power;
  real_T *c3_Ch2FlowTemp;
  real_T *c3_Ch2InTemp;
  real_T *c3_Ch2OutTemp;
  real_T *c3_Ch2Power;
  real_T *c3_ChWaterOutTemp;
  real_T *c3_ChillPumpPower;
  real_T *c3_ChillerPLR;
  real_T *c3_CondPumpPower;
  real_T *c3_Load1InTemp;
  real_T *c3_Load1OutTemp;
  real_T *c3_Load2InTemp;
  real_T *c3_Load2OutTemp;
  real_T *c3_Load3InTemp;
  real_T *c3_Load3OutTemp;
  real_T *c3_Tout;
  real_T *c3_TowerPower;
  c3_Load3OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c3_Load3InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c3_Load2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c3_Load2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c3_Load1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c3_Load1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c3_ChillerPLR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c3_TowerPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c3_CondPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c3_ChillPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c3_ChWaterOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_Ch2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_Ch2FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_Ch2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_Ch1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_Ch1FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Ch1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_Ch2Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Ch1Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_Ch1FlowTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 0)), "Ch1FlowTemp");
  *c3_Ch1InTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 1)), "Ch1InTemp");
  *c3_Ch1OutTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 2)), "Ch1OutTemp");
  *c3_Ch1Power = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 3)), "Ch1Power");
  *c3_Ch2FlowTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 4)), "Ch2FlowTemp");
  *c3_Ch2InTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 5)), "Ch2InTemp");
  *c3_Ch2OutTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 6)), "Ch2OutTemp");
  *c3_Ch2Power = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 7)), "Ch2Power");
  *c3_ChWaterOutTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "ChWaterOutTemp");
  *c3_ChillPumpPower = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 9)), "ChillPumpPower");
  *c3_ChillerPLR = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 10)), "ChillerPLR");
  *c3_CondPumpPower = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "CondPumpPower");
  *c3_Load1InTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 12)), "Load1InTemp");
  *c3_Load1OutTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 13)), "Load1OutTemp");
  *c3_Load2InTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 14)), "Load2InTemp");
  *c3_Load2OutTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 15)), "Load2OutTemp");
  *c3_Load3InTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 16)), "Load3InTemp");
  *c3_Load3OutTemp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 17)), "Load3OutTemp");
  *c3_Tout = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    18)), "Tout");
  *c3_TowerPower = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 19)), "TowerPower");
  chartInstance->c3_is_active_c3_campus_windows = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 20)),
     "is_active_c3_campus_windows");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_campus_windows(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void sf_c3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  real_T c3_u[20];
  uint32_T c3_debug_family_var_map[23];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 20.0;
  real_T c3_Tout;
  real_T c3_Ch1Power;
  real_T c3_Ch2Power;
  real_T c3_Ch1InTemp;
  real_T c3_Ch1FlowTemp;
  real_T c3_Ch1OutTemp;
  real_T c3_Ch2InTemp;
  real_T c3_Ch2FlowTemp;
  real_T c3_Ch2OutTemp;
  real_T c3_ChWaterOutTemp;
  real_T c3_ChillPumpPower;
  real_T c3_CondPumpPower;
  real_T c3_TowerPower;
  real_T c3_ChillerPLR;
  real_T c3_Load1InTemp;
  real_T c3_Load1OutTemp;
  real_T c3_Load2InTemp;
  real_T c3_Load2OutTemp;
  real_T c3_Load3InTemp;
  real_T c3_Load3OutTemp;
  real_T *c3_b_Tout;
  real_T *c3_b_Ch1Power;
  real_T *c3_b_Ch2Power;
  real_T *c3_b_Ch1InTemp;
  real_T *c3_b_Ch1FlowTemp;
  real_T *c3_b_Ch1OutTemp;
  real_T *c3_b_Ch2InTemp;
  real_T *c3_b_Ch2FlowTemp;
  real_T *c3_b_Ch2OutTemp;
  real_T *c3_b_ChWaterOutTemp;
  real_T *c3_b_ChillPumpPower;
  real_T *c3_b_CondPumpPower;
  real_T *c3_b_TowerPower;
  real_T *c3_b_ChillerPLR;
  real_T *c3_b_Load1InTemp;
  real_T *c3_b_Load1OutTemp;
  real_T *c3_b_Load2InTemp;
  real_T *c3_b_Load2OutTemp;
  real_T *c3_b_Load3InTemp;
  real_T *c3_b_Load3OutTemp;
  real_T (*c3_b_u)[20];
  c3_b_Load3OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
  c3_b_Load3InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
  c3_b_Load2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
  c3_b_Load2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
  c3_b_Load1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
  c3_b_Load1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c3_b_ChillerPLR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c3_b_TowerPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c3_b_CondPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c3_b_ChillPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c3_b_ChWaterOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c3_b_Ch2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c3_b_Ch2FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c3_b_Ch2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c3_b_Ch1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_b_Ch1FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_b_Ch1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_Ch2Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_Ch1Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_Tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_u = (real_T (*)[20])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i0 = 0; c3_i0 < 20; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_u)[c3_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_Tout, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch1Power, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch2Power, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch1InTemp, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch1FlowTemp, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch1OutTemp, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch2InTemp, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch2FlowTemp, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ch2OutTemp, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_b_ChWaterOutTemp, 10U);
  _SFD_DATA_RANGE_CHECK(*c3_b_ChillPumpPower, 11U);
  _SFD_DATA_RANGE_CHECK(*c3_b_CondPumpPower, 12U);
  _SFD_DATA_RANGE_CHECK(*c3_b_TowerPower, 13U);
  _SFD_DATA_RANGE_CHECK(*c3_b_ChillerPLR, 14U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Load1InTemp, 15U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Load1OutTemp, 16U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Load2InTemp, 17U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Load2OutTemp, 18U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Load3InTemp, 19U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Load3OutTemp, 20U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i1 = 0; c3_i1 < 20; c3_i1++) {
    c3_u[c3_i1] = (*c3_b_u)[c3_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_u, 2U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_Tout, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch1Power, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch2Power, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch1InTemp, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch1FlowTemp, 7U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch1OutTemp, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch2InTemp, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch2FlowTemp, 10U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ch2OutTemp, 11U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ChWaterOutTemp, 12U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ChillPumpPower, 13U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_CondPumpPower, 14U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_TowerPower, 15U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ChillerPLR, 16U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Load1InTemp, 17U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Load1OutTemp, 18U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Load2InTemp, 19U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Load2OutTemp, 20U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Load3InTemp, 21U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Load3OutTemp, 22U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_Tout = c3_u[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_Ch1Power = c3_u[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_Ch2Power = c3_u[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_Ch1InTemp = c3_u[3];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_Ch1FlowTemp = c3_u[4];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_Ch1OutTemp = c3_u[5];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_Ch2InTemp = c3_u[6];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_Ch2FlowTemp = c3_u[7];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  c3_Ch2OutTemp = c3_u[8];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_ChWaterOutTemp = c3_u[9];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_ChillPumpPower = c3_u[10];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_CondPumpPower = c3_u[11];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
  c3_TowerPower = c3_u[12];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  c3_ChillerPLR = c3_u[13];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  c3_Load1InTemp = c3_u[14];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
  c3_Load1OutTemp = c3_u[15];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
  c3_Load2InTemp = c3_u[16];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
  c3_Load2OutTemp = c3_u[17];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
  c3_Load3InTemp = c3_u[18];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
  c3_Load3OutTemp = c3_u[19];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -50);
  sf_debug_symbol_scope_pop();
  *c3_b_Tout = c3_Tout;
  *c3_b_Ch1Power = c3_Ch1Power;
  *c3_b_Ch2Power = c3_Ch2Power;
  *c3_b_Ch1InTemp = c3_Ch1InTemp;
  *c3_b_Ch1FlowTemp = c3_Ch1FlowTemp;
  *c3_b_Ch1OutTemp = c3_Ch1OutTemp;
  *c3_b_Ch2InTemp = c3_Ch2InTemp;
  *c3_b_Ch2FlowTemp = c3_Ch2FlowTemp;
  *c3_b_Ch2OutTemp = c3_Ch2OutTemp;
  *c3_b_ChWaterOutTemp = c3_ChWaterOutTemp;
  *c3_b_ChillPumpPower = c3_ChillPumpPower;
  *c3_b_CondPumpPower = c3_CondPumpPower;
  *c3_b_TowerPower = c3_TowerPower;
  *c3_b_ChillerPLR = c3_ChillerPLR;
  *c3_b_Load1InTemp = c3_Load1InTemp;
  *c3_b_Load1OutTemp = c3_Load1OutTemp;
  *c3_b_Load2InTemp = c3_Load2InTemp;
  *c3_b_Load2OutTemp = c3_Load2OutTemp;
  *c3_b_Load3InTemp = c3_Load3InTemp;
  *c3_b_Load3OutTemp = c3_Load3OutTemp;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_campus_windowsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_campus_windows(SFc3_campus_windowsInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc3_campus_windowsInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_Load3OutTemp, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Load3OutTemp),
    &c3_thisId);
  sf_mex_destroy(&c3_Load3OutTemp);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Load3OutTemp;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc3_campus_windowsInstanceStruct *)chartInstanceVoid;
  c3_Load3OutTemp = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Load3OutTemp),
    &c3_thisId);
  sf_mex_destroy(&c3_Load3OutTemp);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i2;
  real_T c3_b_inData[20];
  int32_T c3_i3;
  real_T c3_u[20];
  const mxArray *c3_y = NULL;
  SFc3_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc3_campus_windowsInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i2 = 0; c3_i2 < 20; c3_i2++) {
    c3_b_inData[c3_i2] = (*(real_T (*)[20])c3_inData)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 20; c3_i3++) {
    c3_u[c3_i3] = c3_b_inData[c3_i3];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 20), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_campus_windows_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc3_campus_windowsInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i4;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i4, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i4;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc3_campus_windowsInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_campus_windows, const char_T *
  c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_campus_windows), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_campus_windows);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_campus_windowsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_campus_windowsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_campus_windows_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3680403437U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(468107857U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4139604916U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3043318018U);
}

mxArray *sf_c3_campus_windows_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("i5G7316CteMPhSZn8KdFdB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(20);
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

    mxArray *mxData = mxCreateStructMatrix(1,20,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_campus_windows(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[10],T\"Ch1FlowTemp\",},{M[1],M[11],T\"Ch1InTemp\",},{M[1],M[9],T\"Ch1OutTemp\",},{M[1],M[7],T\"Ch1Power\",},{M[1],M[13],T\"Ch2FlowTemp\",},{M[1],M[12],T\"Ch2InTemp\",},{M[1],M[14],T\"Ch2OutTemp\",},{M[1],M[8],T\"Ch2Power\",},{M[1],M[15],T\"ChWaterOutTemp\",},{M[1],M[16],T\"ChillPumpPower\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[21],T\"ChillerPLR\",},{M[1],M[19],T\"CondPumpPower\",},{M[1],M[22],T\"Load1InTemp\",},{M[1],M[23],T\"Load1OutTemp\",},{M[1],M[24],T\"Load2InTemp\",},{M[1],M[25],T\"Load2OutTemp\",},{M[1],M[26],T\"Load3InTemp\",},{M[1],M[27],T\"Load3OutTemp\",},{M[1],M[5],T\"Tout\",},{M[1],M[20],T\"TowerPower\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_campus_windows\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 21, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_campus_windows_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_campus_windowsInstanceStruct *chartInstance;
    chartInstance = (SFc3_campus_windowsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_campus_windowsMachineNumber_,
           3,
           1,
           1,
           21,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"Tout");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Ch1Power");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Ch2Power");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Ch1InTemp");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Ch1FlowTemp");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Ch1OutTemp");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Ch2InTemp");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Ch2FlowTemp");
          _SFD_SET_DATA_PROPS(9,2,0,1,"Ch2OutTemp");
          _SFD_SET_DATA_PROPS(10,2,0,1,"ChWaterOutTemp");
          _SFD_SET_DATA_PROPS(11,2,0,1,"ChillPumpPower");
          _SFD_SET_DATA_PROPS(12,2,0,1,"CondPumpPower");
          _SFD_SET_DATA_PROPS(13,2,0,1,"TowerPower");
          _SFD_SET_DATA_PROPS(14,2,0,1,"ChillerPLR");
          _SFD_SET_DATA_PROPS(15,2,0,1,"Load1InTemp");
          _SFD_SET_DATA_PROPS(16,2,0,1,"Load1OutTemp");
          _SFD_SET_DATA_PROPS(17,2,0,1,"Load2InTemp");
          _SFD_SET_DATA_PROPS(18,2,0,1,"Load2OutTemp");
          _SFD_SET_DATA_PROPS(19,2,0,1,"Load3InTemp");
          _SFD_SET_DATA_PROPS(20,2,0,1,"Load3OutTemp");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1051);
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
          dimVector[0]= 20;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_Tout;
          real_T *c3_Ch1Power;
          real_T *c3_Ch2Power;
          real_T *c3_Ch1InTemp;
          real_T *c3_Ch1FlowTemp;
          real_T *c3_Ch1OutTemp;
          real_T *c3_Ch2InTemp;
          real_T *c3_Ch2FlowTemp;
          real_T *c3_Ch2OutTemp;
          real_T *c3_ChWaterOutTemp;
          real_T *c3_ChillPumpPower;
          real_T *c3_CondPumpPower;
          real_T *c3_TowerPower;
          real_T *c3_ChillerPLR;
          real_T *c3_Load1InTemp;
          real_T *c3_Load1OutTemp;
          real_T *c3_Load2InTemp;
          real_T *c3_Load2OutTemp;
          real_T *c3_Load3InTemp;
          real_T *c3_Load3OutTemp;
          real_T (*c3_u)[20];
          c3_Load3OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 20);
          c3_Load3InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 19);
          c3_Load2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 18);
          c3_Load2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 17);
          c3_Load1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 16);
          c3_Load1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
          c3_ChillerPLR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
          c3_TowerPower = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c3_CondPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            12);
          c3_ChillPumpPower = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            11);
          c3_ChWaterOutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            10);
          c3_Ch2OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c3_Ch2FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c3_Ch2InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c3_Ch1OutTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c3_Ch1FlowTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c3_Ch1InTemp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_Ch2Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_Ch1Power = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_Tout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_u = (real_T (*)[20])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_Tout);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_Ch1Power);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_Ch2Power);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_Ch1InTemp);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_Ch1FlowTemp);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_Ch1OutTemp);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_Ch2InTemp);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_Ch2FlowTemp);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_Ch2OutTemp);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_ChWaterOutTemp);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_ChillPumpPower);
          _SFD_SET_DATA_VALUE_PTR(12U, c3_CondPumpPower);
          _SFD_SET_DATA_VALUE_PTR(13U, c3_TowerPower);
          _SFD_SET_DATA_VALUE_PTR(14U, c3_ChillerPLR);
          _SFD_SET_DATA_VALUE_PTR(15U, c3_Load1InTemp);
          _SFD_SET_DATA_VALUE_PTR(16U, c3_Load1OutTemp);
          _SFD_SET_DATA_VALUE_PTR(17U, c3_Load2InTemp);
          _SFD_SET_DATA_VALUE_PTR(18U, c3_Load2OutTemp);
          _SFD_SET_DATA_VALUE_PTR(19U, c3_Load3InTemp);
          _SFD_SET_DATA_VALUE_PTR(20U, c3_Load3OutTemp);
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
  return "DwpCqGSNelSRp6YiJx8wSF";
}

static void sf_opaque_initialize_c3_campus_windows(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_campus_windowsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_campus_windows((SFc3_campus_windowsInstanceStruct*)
    chartInstanceVar);
  initialize_c3_campus_windows((SFc3_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_campus_windows(void *chartInstanceVar)
{
  enable_c3_campus_windows((SFc3_campus_windowsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_campus_windows(void *chartInstanceVar)
{
  disable_c3_campus_windows((SFc3_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_campus_windows(void *chartInstanceVar)
{
  sf_c3_campus_windows((SFc3_campus_windowsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_campus_windows(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_campus_windows
    ((SFc3_campus_windowsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_campus_windows();/* state var info */
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

extern void sf_internal_set_sim_state_c3_campus_windows(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_campus_windows();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_campus_windows((SFc3_campus_windowsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_campus_windows(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_campus_windows(S);
}

static void sf_opaque_set_sim_state_c3_campus_windows(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_campus_windows(S, st);
}

static void sf_opaque_terminate_c3_campus_windows(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_campus_windowsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_campus_windows((SFc3_campus_windowsInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_campus_windows_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_campus_windows((SFc3_campus_windowsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_campus_windows(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_campus_windows((SFc3_campus_windowsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_campus_windows_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,20);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3901303623U));
  ssSetChecksum1(S,(2882298292U));
  ssSetChecksum2(S,(2657301312U));
  ssSetChecksum3(S,(1232647270U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_campus_windows(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_campus_windows(SimStruct *S)
{
  SFc3_campus_windowsInstanceStruct *chartInstance;
  chartInstance = (SFc3_campus_windowsInstanceStruct *)malloc(sizeof
    (SFc3_campus_windowsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_campus_windowsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_campus_windows;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_campus_windows;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_campus_windows;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_campus_windows;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_campus_windows;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_campus_windows;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_campus_windows;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_campus_windows;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_campus_windows;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_campus_windows;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_campus_windows;
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

void c3_campus_windows_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_campus_windows(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_campus_windows(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_campus_windows(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_campus_windows_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
