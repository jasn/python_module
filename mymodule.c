#include "Python.h"


static PyObject* foo(PyObject *self) {
  long res = 42;
  return PyLong_FromLong(res);
}

static PyMethodDef myModuleMethods[] = {
      {"foo",  foo, METH_VARARGS,
       "returns 42 as long."},
      {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef mymodule = {
  PyModuleDef_HEAD_INIT,
  "mymodule",   /* name of module */
  NULL, /* module documentation, may be NULL */
  -1,       /* size of per-interpreter state of the module,
	       or -1 if the module keeps state in global variables. */
  myModuleMethods
};


PyMODINIT_FUNC
PyInit_mymodule(void)
{
  return PyModule_Create(&mymodule);
}

