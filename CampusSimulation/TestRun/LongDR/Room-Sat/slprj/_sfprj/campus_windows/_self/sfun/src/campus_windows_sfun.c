/* Include files */

#include "campus_windows_sfun.h"
#include "c1_campus_windows.h"
#include "c2_campus_windows.h"
#include "c3_campus_windows.h"
#include "c4_campus_windows.h"
#include "c5_campus_windows.h"
#include "c6_campus_windows.h"
#include "c7_campus_windows.h"
#include "c8_campus_windows.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _campus_windowsMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void campus_windows_initializer(void)
{
}

void campus_windows_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_campus_windows_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_campus_windows_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_campus_windows_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2033355700U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1195967571U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1341546601U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(556451475U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1117623042U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2833045505U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(70484053U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2552260844U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c1_campus_windows_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c2_campus_windows_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c3_campus_windows_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c4_campus_windows_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c5_campus_windows_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c6_campus_windows_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c7_campus_windows_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_campus_windows_get_check_sum(mxArray *plhs[]);
          sf_c8_campus_windows_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1267493297U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(841019383U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(513919492U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(281013406U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_campus_windows_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "uXEU9OqmW6UQ6ktTn3V23G") == 0) {
          extern mxArray *sf_c1_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c1_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "scjLOBRaXu2AJse9QdcHMC") == 0) {
          extern mxArray *sf_c2_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c2_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "i5G7316CteMPhSZn8KdFdB") == 0) {
          extern mxArray *sf_c3_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c3_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "TRo3AkQ08G0wTbkApWFG2C") == 0) {
          extern mxArray *sf_c4_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c4_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "TRo3AkQ08G0wTbkApWFG2C") == 0) {
          extern mxArray *sf_c5_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c5_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "vwAuo6L4lZxNVO8ej2iepB") == 0) {
          extern mxArray *sf_c6_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c6_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "nr4eiF2EQu5DMrKsLrsW2G") == 0) {
          extern mxArray *sf_c7_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c7_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "PP4OraJcoRW3DASyRTSaCG") == 0) {
          extern mxArray *sf_c8_campus_windows_get_autoinheritance_info(void);
          plhs[0] = sf_c8_campus_windows_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_campus_windows_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_campus_windows_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_campus_windows_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void campus_windows_debug_initialize(void)
{
  _campus_windowsMachineNumber_ = sf_debug_initialize_machine("campus_windows",
    "sfun",0,8,0,0,0);
  sf_debug_set_machine_event_thresholds(_campus_windowsMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_campus_windowsMachineNumber_,0);
}

void campus_windows_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_campus_windows_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("campus_windows",
      "campus_windows");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_campus_windows_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
