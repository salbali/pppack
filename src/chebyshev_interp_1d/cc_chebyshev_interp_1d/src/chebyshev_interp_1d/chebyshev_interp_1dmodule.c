/* File: chebyshev_interp_1dmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Tue May 23 16:34:09 2017
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *chebyshev_interp_1d_error;
static PyObject *chebyshev_interp_1d_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
  if (!(check)) {\
    char errstring[256];\
    sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
    PyErr_SetString(chebyshev_interp_1d_error,errstring);\
    /*goto capi_fail;*/\
  } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = chebyshev_interp_1d_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyFloat_Check(obj)) {
#ifdef __sgi
    *v = PyFloat_AsDouble(obj);
#else
    *v = PyFloat_AS_DOUBLE(obj);
#endif
    return 1;
  }
  tmp = PyNumber_Float(obj);
  if (tmp) {
#ifdef __sgi
    *v = PyFloat_AsDouble(tmp);
#else
    *v = PyFloat_AS_DOUBLE(tmp);
#endif
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = chebyshev_interp_1d_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC_US(chebyshev_coef_1d,CHEBYSHEV_COEF_1D)(int*,double*,double*,double*,double*,double*);
extern void F_FUNC_US(chebyshev_interp_1d,CHEBYSHEV_INTERP_1D)(int*,double*,double*,int*,double*,double*);
extern void F_FUNC_US(chebyshev_value_1d,CHEBYSHEV_VALUE_1D)(int*,double*,double*,double*,int*,double*,double*);
extern void F_FUNC_US(qr_solve,QR_SOLVE)(int*,int*,double*,double*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/***************************** chebyshev_coef_1d *****************************/
static char doc_f2py_rout_chebyshev_interp_1d_chebyshev_coef_1d[] = "\
c,xmin,xmax = chebyshev_coef_1d(xd,yd,[nd])\n\nWrapper for ``chebyshev_coef_1d``.\
\n\nParameters\n----------\n"
"xd : input rank-1 array('d') with bounds (nd)\n"
"yd : input rank-1 array('d') with bounds (nd)\n"
"\nOther Parameters\n----------------\n"
"nd : input int, optional\n    Default: len(xd)\n"
"\nReturns\n-------\n"
"c : rank-1 array('d') with bounds (nd)\n"
"xmin : float\n"
"xmax : float";
/* extern void F_FUNC_US(chebyshev_coef_1d,CHEBYSHEV_COEF_1D)(int*,double*,double*,double*,double*,double*); */
static PyObject *f2py_rout_chebyshev_interp_1d_chebyshev_coef_1d(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int nd = 0;
  PyObject *nd_capi = Py_None;
  double *xd = NULL;
  npy_intp xd_Dims[1] = {-1};
  const int xd_Rank = 1;
  PyArrayObject *capi_xd_tmp = NULL;
  int capi_xd_intent = 0;
  PyObject *xd_capi = Py_None;
  double *yd = NULL;
  npy_intp yd_Dims[1] = {-1};
  const int yd_Rank = 1;
  PyArrayObject *capi_yd_tmp = NULL;
  int capi_yd_intent = 0;
  PyObject *yd_capi = Py_None;
  double *c = NULL;
  npy_intp c_Dims[1] = {-1};
  const int c_Rank = 1;
  PyArrayObject *capi_c_tmp = NULL;
  int capi_c_intent = 0;
  double xmin = 0;
  double xmax = 0;
  static char *capi_kwlist[] = {"xd","yd","nd",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|O:chebyshev_interp_1d.chebyshev_coef_1d",\
    capi_kwlist,&xd_capi,&yd_capi,&nd_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable xmax */
  /* Processing variable xmin */
  /* Processing variable xd */
  ;
  capi_xd_intent |= F2PY_INTENT_IN;
  capi_xd_tmp = array_from_pyobj(NPY_DOUBLE,xd_Dims,xd_Rank,capi_xd_intent,xd_capi);
  if (capi_xd_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 1st argument `xd' of chebyshev_interp_1d.chebyshev_coef_1d to C/Fortran array" );
  } else {
    xd = (double *)(PyArray_DATA(capi_xd_tmp));

  /* Processing variable nd */
  if (nd_capi == Py_None) nd = len(xd); else
    f2py_success = int_from_pyobj(&nd,nd_capi,"chebyshev_interp_1d.chebyshev_coef_1d() 1st keyword (nd) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(xd)>=nd,"len(xd)>=nd","1st keyword nd","chebyshev_coef_1d:nd=%d",nd) {
  /* Processing variable yd */
  yd_Dims[0]=nd;
  capi_yd_intent |= F2PY_INTENT_IN;
  capi_yd_tmp = array_from_pyobj(NPY_DOUBLE,yd_Dims,yd_Rank,capi_yd_intent,yd_capi);
  if (capi_yd_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 2nd argument `yd' of chebyshev_interp_1d.chebyshev_coef_1d to C/Fortran array" );
  } else {
    yd = (double *)(PyArray_DATA(capi_yd_tmp));

  /* Processing variable c */
  c_Dims[0]=nd;
  capi_c_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_c_tmp = array_from_pyobj(NPY_DOUBLE,c_Dims,c_Rank,capi_c_intent,Py_None);
  if (capi_c_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting hidden `c' of chebyshev_interp_1d.chebyshev_coef_1d to C/Fortran array" );
  } else {
    c = (double *)(PyArray_DATA(capi_c_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&nd,xd,yd,c,&xmin,&xmax);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("Ndd",capi_c_tmp,xmin,xmax);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_c_tmp == NULL) ... else of c*/
  /* End of cleaning variable c */
  if((PyObject *)capi_yd_tmp!=yd_capi) {
    Py_XDECREF(capi_yd_tmp); }
  }  /*if (capi_yd_tmp == NULL) ... else of yd*/
  /* End of cleaning variable yd */
  } /*CHECKSCALAR(len(xd)>=nd)*/
  } /*if (f2py_success) of nd*/
  /* End of cleaning variable nd */
  if((PyObject *)capi_xd_tmp!=xd_capi) {
    Py_XDECREF(capi_xd_tmp); }
  }  /*if (capi_xd_tmp == NULL) ... else of xd*/
  /* End of cleaning variable xd */
  /* End of cleaning variable xmin */
  /* End of cleaning variable xmax */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/************************** end of chebyshev_coef_1d **************************/

/**************************** chebyshev_interp_1d ****************************/
static char doc_f2py_rout_chebyshev_interp_1d_chebyshev_interp_1d[] = "\
yi = chebyshev_interp_1d(xd,yd,xi,[nd,ni])\n\nWrapper for ``chebyshev_interp_1d``.\
\n\nParameters\n----------\n"
"xd : input rank-1 array('d') with bounds (nd)\n"
"yd : input rank-1 array('d') with bounds (nd)\n"
"xi : input rank-1 array('d') with bounds (ni)\n"
"\nOther Parameters\n----------------\n"
"nd : input int, optional\n    Default: len(xd)\n"
"ni : input int, optional\n    Default: len(xi)\n"
"\nReturns\n-------\n"
"yi : rank-1 array('d') with bounds (ni)";
/* extern void F_FUNC_US(chebyshev_interp_1d,CHEBYSHEV_INTERP_1D)(int*,double*,double*,int*,double*,double*); */
static PyObject *f2py_rout_chebyshev_interp_1d_chebyshev_interp_1d(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,int*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int nd = 0;
  PyObject *nd_capi = Py_None;
  double *xd = NULL;
  npy_intp xd_Dims[1] = {-1};
  const int xd_Rank = 1;
  PyArrayObject *capi_xd_tmp = NULL;
  int capi_xd_intent = 0;
  PyObject *xd_capi = Py_None;
  double *yd = NULL;
  npy_intp yd_Dims[1] = {-1};
  const int yd_Rank = 1;
  PyArrayObject *capi_yd_tmp = NULL;
  int capi_yd_intent = 0;
  PyObject *yd_capi = Py_None;
  int ni = 0;
  PyObject *ni_capi = Py_None;
  double *xi = NULL;
  npy_intp xi_Dims[1] = {-1};
  const int xi_Rank = 1;
  PyArrayObject *capi_xi_tmp = NULL;
  int capi_xi_intent = 0;
  PyObject *xi_capi = Py_None;
  double *yi = NULL;
  npy_intp yi_Dims[1] = {-1};
  const int yi_Rank = 1;
  PyArrayObject *capi_yi_tmp = NULL;
  int capi_yi_intent = 0;
  static char *capi_kwlist[] = {"xd","yd","xi","nd","ni",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOO|OO:chebyshev_interp_1d.chebyshev_interp_1d",\
    capi_kwlist,&xd_capi,&yd_capi,&xi_capi,&nd_capi,&ni_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable xi */
  ;
  capi_xi_intent |= F2PY_INTENT_IN;
  capi_xi_tmp = array_from_pyobj(NPY_DOUBLE,xi_Dims,xi_Rank,capi_xi_intent,xi_capi);
  if (capi_xi_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 3rd argument `xi' of chebyshev_interp_1d.chebyshev_interp_1d to C/Fortran array" );
  } else {
    xi = (double *)(PyArray_DATA(capi_xi_tmp));

  /* Processing variable xd */
  ;
  capi_xd_intent |= F2PY_INTENT_IN;
  capi_xd_tmp = array_from_pyobj(NPY_DOUBLE,xd_Dims,xd_Rank,capi_xd_intent,xd_capi);
  if (capi_xd_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 1st argument `xd' of chebyshev_interp_1d.chebyshev_interp_1d to C/Fortran array" );
  } else {
    xd = (double *)(PyArray_DATA(capi_xd_tmp));

  /* Processing variable ni */
  if (ni_capi == Py_None) ni = len(xi); else
    f2py_success = int_from_pyobj(&ni,ni_capi,"chebyshev_interp_1d.chebyshev_interp_1d() 2nd keyword (ni) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(xi)>=ni,"len(xi)>=ni","2nd keyword ni","chebyshev_interp_1d:ni=%d",ni) {
  /* Processing variable nd */
  if (nd_capi == Py_None) nd = len(xd); else
    f2py_success = int_from_pyobj(&nd,nd_capi,"chebyshev_interp_1d.chebyshev_interp_1d() 1st keyword (nd) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(xd)>=nd,"len(xd)>=nd","1st keyword nd","chebyshev_interp_1d:nd=%d",nd) {
  /* Processing variable yd */
  yd_Dims[0]=nd;
  capi_yd_intent |= F2PY_INTENT_IN;
  capi_yd_tmp = array_from_pyobj(NPY_DOUBLE,yd_Dims,yd_Rank,capi_yd_intent,yd_capi);
  if (capi_yd_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 2nd argument `yd' of chebyshev_interp_1d.chebyshev_interp_1d to C/Fortran array" );
  } else {
    yd = (double *)(PyArray_DATA(capi_yd_tmp));

  /* Processing variable yi */
  yi_Dims[0]=ni;
  capi_yi_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_yi_tmp = array_from_pyobj(NPY_DOUBLE,yi_Dims,yi_Rank,capi_yi_intent,Py_None);
  if (capi_yi_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting hidden `yi' of chebyshev_interp_1d.chebyshev_interp_1d to C/Fortran array" );
  } else {
    yi = (double *)(PyArray_DATA(capi_yi_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&nd,xd,yd,&ni,xi,yi);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_yi_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_yi_tmp == NULL) ... else of yi*/
  /* End of cleaning variable yi */
  if((PyObject *)capi_yd_tmp!=yd_capi) {
    Py_XDECREF(capi_yd_tmp); }
  }  /*if (capi_yd_tmp == NULL) ... else of yd*/
  /* End of cleaning variable yd */
  } /*CHECKSCALAR(len(xd)>=nd)*/
  } /*if (f2py_success) of nd*/
  /* End of cleaning variable nd */
  } /*CHECKSCALAR(len(xi)>=ni)*/
  } /*if (f2py_success) of ni*/
  /* End of cleaning variable ni */
  if((PyObject *)capi_xd_tmp!=xd_capi) {
    Py_XDECREF(capi_xd_tmp); }
  }  /*if (capi_xd_tmp == NULL) ... else of xd*/
  /* End of cleaning variable xd */
  if((PyObject *)capi_xi_tmp!=xi_capi) {
    Py_XDECREF(capi_xi_tmp); }
  }  /*if (capi_xi_tmp == NULL) ... else of xi*/
  /* End of cleaning variable xi */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/************************* end of chebyshev_interp_1d *************************/

/***************************** chebyshev_value_1d *****************************/
static char doc_f2py_rout_chebyshev_interp_1d_chebyshev_value_1d[] = "\
yi = chebyshev_value_1d(c,xmin,xmax,xi,[nd,ni])\n\nWrapper for ``chebyshev_value_1d``.\
\n\nParameters\n----------\n"
"c : input rank-1 array('d') with bounds (nd)\n"
"xmin : input float\n"
"xmax : input float\n"
"xi : input rank-1 array('d') with bounds (ni)\n"
"\nOther Parameters\n----------------\n"
"nd : input int, optional\n    Default: len(c)\n"
"ni : input int, optional\n    Default: len(xi)\n"
"\nReturns\n-------\n"
"yi : rank-1 array('d') with bounds (ni)";
/* extern void F_FUNC_US(chebyshev_value_1d,CHEBYSHEV_VALUE_1D)(int*,double*,double*,double*,int*,double*,double*); */
static PyObject *f2py_rout_chebyshev_interp_1d_chebyshev_value_1d(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,double*,int*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int nd = 0;
  PyObject *nd_capi = Py_None;
  double *c = NULL;
  npy_intp c_Dims[1] = {-1};
  const int c_Rank = 1;
  PyArrayObject *capi_c_tmp = NULL;
  int capi_c_intent = 0;
  PyObject *c_capi = Py_None;
  double xmin = 0;
  PyObject *xmin_capi = Py_None;
  double xmax = 0;
  PyObject *xmax_capi = Py_None;
  int ni = 0;
  PyObject *ni_capi = Py_None;
  double *xi = NULL;
  npy_intp xi_Dims[1] = {-1};
  const int xi_Rank = 1;
  PyArrayObject *capi_xi_tmp = NULL;
  int capi_xi_intent = 0;
  PyObject *xi_capi = Py_None;
  double *yi = NULL;
  npy_intp yi_Dims[1] = {-1};
  const int yi_Rank = 1;
  PyArrayObject *capi_yi_tmp = NULL;
  int capi_yi_intent = 0;
  static char *capi_kwlist[] = {"c","xmin","xmax","xi","nd","ni",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO|OO:chebyshev_interp_1d.chebyshev_value_1d",\
    capi_kwlist,&c_capi,&xmin_capi,&xmax_capi,&xi_capi,&nd_capi,&ni_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable c */
  ;
  capi_c_intent |= F2PY_INTENT_IN;
  capi_c_tmp = array_from_pyobj(NPY_DOUBLE,c_Dims,c_Rank,capi_c_intent,c_capi);
  if (capi_c_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 1st argument `c' of chebyshev_interp_1d.chebyshev_value_1d to C/Fortran array" );
  } else {
    c = (double *)(PyArray_DATA(capi_c_tmp));

  /* Processing variable xi */
  ;
  capi_xi_intent |= F2PY_INTENT_IN;
  capi_xi_tmp = array_from_pyobj(NPY_DOUBLE,xi_Dims,xi_Rank,capi_xi_intent,xi_capi);
  if (capi_xi_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 4th argument `xi' of chebyshev_interp_1d.chebyshev_value_1d to C/Fortran array" );
  } else {
    xi = (double *)(PyArray_DATA(capi_xi_tmp));

  /* Processing variable xmax */
    f2py_success = double_from_pyobj(&xmax,xmax_capi,"chebyshev_interp_1d.chebyshev_value_1d() 3rd argument (xmax) can't be converted to double");
  if (f2py_success) {
  /* Processing variable xmin */
    f2py_success = double_from_pyobj(&xmin,xmin_capi,"chebyshev_interp_1d.chebyshev_value_1d() 2nd argument (xmin) can't be converted to double");
  if (f2py_success) {
  /* Processing variable ni */
  if (ni_capi == Py_None) ni = len(xi); else
    f2py_success = int_from_pyobj(&ni,ni_capi,"chebyshev_interp_1d.chebyshev_value_1d() 2nd keyword (ni) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(xi)>=ni,"len(xi)>=ni","2nd keyword ni","chebyshev_value_1d:ni=%d",ni) {
  /* Processing variable nd */
  if (nd_capi == Py_None) nd = len(c); else
    f2py_success = int_from_pyobj(&nd,nd_capi,"chebyshev_interp_1d.chebyshev_value_1d() 1st keyword (nd) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(c)>=nd,"len(c)>=nd","1st keyword nd","chebyshev_value_1d:nd=%d",nd) {
  /* Processing variable yi */
  yi_Dims[0]=ni;
  capi_yi_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_yi_tmp = array_from_pyobj(NPY_DOUBLE,yi_Dims,yi_Rank,capi_yi_intent,Py_None);
  if (capi_yi_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting hidden `yi' of chebyshev_interp_1d.chebyshev_value_1d to C/Fortran array" );
  } else {
    yi = (double *)(PyArray_DATA(capi_yi_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&nd,c,&xmin,&xmax,&ni,xi,yi);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_yi_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_yi_tmp == NULL) ... else of yi*/
  /* End of cleaning variable yi */
  } /*CHECKSCALAR(len(c)>=nd)*/
  } /*if (f2py_success) of nd*/
  /* End of cleaning variable nd */
  } /*CHECKSCALAR(len(xi)>=ni)*/
  } /*if (f2py_success) of ni*/
  /* End of cleaning variable ni */
  } /*if (f2py_success) of xmin*/
  /* End of cleaning variable xmin */
  } /*if (f2py_success) of xmax*/
  /* End of cleaning variable xmax */
  if((PyObject *)capi_xi_tmp!=xi_capi) {
    Py_XDECREF(capi_xi_tmp); }
  }  /*if (capi_xi_tmp == NULL) ... else of xi*/
  /* End of cleaning variable xi */
  if((PyObject *)capi_c_tmp!=c_capi) {
    Py_XDECREF(capi_c_tmp); }
  }  /*if (capi_c_tmp == NULL) ... else of c*/
  /* End of cleaning variable c */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/************************* end of chebyshev_value_1d *************************/

/********************************** qr_solve **********************************/
static char doc_f2py_rout_chebyshev_interp_1d_qr_solve[] = "\
x = qr_solve(a,b,[m,n])\n\nWrapper for ``qr_solve``.\
\n\nParameters\n----------\n"
"a : input rank-2 array('d') with bounds (m,n)\n"
"b : input rank-1 array('d') with bounds (m)\n"
"\nOther Parameters\n----------------\n"
"m : input int, optional\n    Default: shape(a,0)\n"
"n : input int, optional\n    Default: shape(a,1)\n"
"\nReturns\n-------\n"
"x : rank-1 array('d') with bounds (n)";
/* extern void F_FUNC_US(qr_solve,QR_SOLVE)(int*,int*,double*,double*,double*); */
static PyObject *f2py_rout_chebyshev_interp_1d_qr_solve(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int m = 0;
  PyObject *m_capi = Py_None;
  int n = 0;
  PyObject *n_capi = Py_None;
  double *a = NULL;
  npy_intp a_Dims[2] = {-1, -1};
  const int a_Rank = 2;
  PyArrayObject *capi_a_tmp = NULL;
  int capi_a_intent = 0;
  PyObject *a_capi = Py_None;
  double *b = NULL;
  npy_intp b_Dims[1] = {-1};
  const int b_Rank = 1;
  PyArrayObject *capi_b_tmp = NULL;
  int capi_b_intent = 0;
  PyObject *b_capi = Py_None;
  double *x = NULL;
  npy_intp x_Dims[1] = {-1};
  const int x_Rank = 1;
  PyArrayObject *capi_x_tmp = NULL;
  int capi_x_intent = 0;
  static char *capi_kwlist[] = {"a","b","m","n",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|OO:chebyshev_interp_1d.qr_solve",\
    capi_kwlist,&a_capi,&b_capi,&m_capi,&n_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable a */
  ;
  capi_a_intent |= F2PY_INTENT_IN;
  capi_a_tmp = array_from_pyobj(NPY_DOUBLE,a_Dims,a_Rank,capi_a_intent,a_capi);
  if (capi_a_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 1st argument `a' of chebyshev_interp_1d.qr_solve to C/Fortran array" );
  } else {
    a = (double *)(PyArray_DATA(capi_a_tmp));

  /* Processing variable m */
  if (m_capi == Py_None) m = shape(a,0); else
    f2py_success = int_from_pyobj(&m,m_capi,"chebyshev_interp_1d.qr_solve() 1st keyword (m) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,0)==m,"shape(a,0)==m","1st keyword m","qr_solve:m=%d",m) {
  /* Processing variable n */
  if (n_capi == Py_None) n = shape(a,1); else
    f2py_success = int_from_pyobj(&n,n_capi,"chebyshev_interp_1d.qr_solve() 2nd keyword (n) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(a,1)==n,"shape(a,1)==n","2nd keyword n","qr_solve:n=%d",n) {
  /* Processing variable x */
  x_Dims[0]=n;
  capi_x_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_x_tmp = array_from_pyobj(NPY_DOUBLE,x_Dims,x_Rank,capi_x_intent,Py_None);
  if (capi_x_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting hidden `x' of chebyshev_interp_1d.qr_solve to C/Fortran array" );
  } else {
    x = (double *)(PyArray_DATA(capi_x_tmp));

  /* Processing variable b */
  b_Dims[0]=m;
  capi_b_intent |= F2PY_INTENT_IN;
  capi_b_tmp = array_from_pyobj(NPY_DOUBLE,b_Dims,b_Rank,capi_b_intent,b_capi);
  if (capi_b_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(chebyshev_interp_1d_error,"failed in converting 2nd argument `b' of chebyshev_interp_1d.qr_solve to C/Fortran array" );
  } else {
    b = (double *)(PyArray_DATA(capi_b_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&m,&n,a,b,x);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_x_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_b_tmp!=b_capi) {
    Py_XDECREF(capi_b_tmp); }
  }  /*if (capi_b_tmp == NULL) ... else of b*/
  /* End of cleaning variable b */
  }  /*if (capi_x_tmp == NULL) ... else of x*/
  /* End of cleaning variable x */
  } /*CHECKSCALAR(shape(a,1)==n)*/
  } /*if (f2py_success) of n*/
  /* End of cleaning variable n */
  } /*CHECKSCALAR(shape(a,0)==m)*/
  } /*if (f2py_success) of m*/
  /* End of cleaning variable m */
  if((PyObject *)capi_a_tmp!=a_capi) {
    Py_XDECREF(capi_a_tmp); }
  }  /*if (capi_a_tmp == NULL) ... else of a*/
  /* End of cleaning variable a */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/****************************** end of qr_solve ******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"chebyshev_coef_1d",-1,{{-1}},0,(char *)F_FUNC_US(chebyshev_coef_1d,CHEBYSHEV_COEF_1D),(f2py_init_func)f2py_rout_chebyshev_interp_1d_chebyshev_coef_1d,doc_f2py_rout_chebyshev_interp_1d_chebyshev_coef_1d},
  {"chebyshev_interp_1d",-1,{{-1}},0,(char *)F_FUNC_US(chebyshev_interp_1d,CHEBYSHEV_INTERP_1D),(f2py_init_func)f2py_rout_chebyshev_interp_1d_chebyshev_interp_1d,doc_f2py_rout_chebyshev_interp_1d_chebyshev_interp_1d},
  {"chebyshev_value_1d",-1,{{-1}},0,(char *)F_FUNC_US(chebyshev_value_1d,CHEBYSHEV_VALUE_1D),(f2py_init_func)f2py_rout_chebyshev_interp_1d_chebyshev_value_1d,doc_f2py_rout_chebyshev_interp_1d_chebyshev_value_1d},
  {"qr_solve",-1,{{-1}},0,(char *)F_FUNC_US(qr_solve,QR_SOLVE),(f2py_init_func)f2py_rout_chebyshev_interp_1d_qr_solve,doc_f2py_rout_chebyshev_interp_1d_qr_solve},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "chebyshev_interp_1d",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_chebyshev_interp_1d(void) {
#else
#define RETVAL
PyMODINIT_FUNC initchebyshev_interp_1d(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = chebyshev_interp_1d_module = PyModule_Create(&moduledef);
#else
  m = chebyshev_interp_1d_module = Py_InitModule("chebyshev_interp_1d", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module chebyshev_interp_1d (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'chebyshev_interp_1d' is auto-generated with f2py (version:2).\nFunctions:\n"
"  c,xmin,xmax = chebyshev_coef_1d(xd,yd,nd=len(xd))\n"
"  yi = chebyshev_interp_1d(xd,yd,xi,nd=len(xd),ni=len(xi))\n"
"  yi = chebyshev_value_1d(c,xmin,xmax,xi,nd=len(c),ni=len(xi))\n"
"  x = qr_solve(a,b,m=shape(a,0),n=shape(a,1))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  chebyshev_interp_1d_error = PyErr_NewException ("chebyshev_interp_1d.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));




/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"chebyshev_interp_1d");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
