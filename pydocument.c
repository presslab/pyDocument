/*
Copyright (c) 2009 Prima Tech Informatica Ltda.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <Python.h>

static PyObject *PyDocError;

static PyObject *
document_new(PyObject *self, PyObject *args)
{
    return Py_BuildValue("i", 1);
}

static PyMethodDef pyDocumentMethods[] = {
    {"document", document_new, METH_VARARGS, "Create a new document object."},
    {NULL, NULL, 0, NULL}
};

static char pydocument__doc__[] =
"Python interface to low level of PyDocuments functions";

PyMODINIT_FUNC
init_pydocument(void)
{
    PyObject *m;

    m = Py_InitModule4("_pydocument",
                       pyDocumentMethods,
                       pydocument__doc__,
                       NULL,
                       PYTHON_API_VERSION);
    if (m == NULL)
        return;

    PyDocError = PyErr_NewException("pydocument.error", NULL, NULL);
    Py_INCREF(PyDocError);
    PyModule_AddObject(m, "error", PyDocError);
}

