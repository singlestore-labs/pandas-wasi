#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "udf.h"
#include <stddef.h>

void *__cxa_allocate_exception(size_t s) {
    abort();
}

void __cxa_throw(void *a, void *b, void(*c)(void *d)) {
    abort();
}

#include <setjmp.h>

void longjmp(jmp_buf environment, int value) {
    abort();
}

int setjmp(jmp_buf environment) {
    return 0;
}

static PyObject *main_mod;
static PyObject *msgpack_mod;
static PyObject *pack;
static PyObject *unpack;

PyMODINIT_FUNC PyInit__wasi_sql(void);
PyMODINIT_FUNC PyInit__common(void);
PyMODINIT_FUNC PyInit__sfc64(void);
PyMODINIT_FUNC PyInit__pcg64(void);
PyMODINIT_FUNC PyInit_mtrand(void);
PyMODINIT_FUNC PyInit__bounded_integers(void);
PyMODINIT_FUNC PyInit__generator(void);
PyMODINIT_FUNC PyInit__philox(void);
PyMODINIT_FUNC PyInit__mt19937(void);
PyMODINIT_FUNC PyInit_bit_generator(void);
PyMODINIT_FUNC PyInit_lapack_lite(void);
PyMODINIT_FUNC PyInit__umath_linalg(void);
PyMODINIT_FUNC PyInit__pocketfft_internal(void);
PyMODINIT_FUNC PyInit__simd(void);
PyMODINIT_FUNC PyInit__multiarray_umath(void);
PyMODINIT_FUNC PyInit__umath_tests(void);
PyMODINIT_FUNC PyInit__multiarray_tests(void);
PyMODINIT_FUNC PyInit__rational_tests(void);
PyMODINIT_FUNC PyInit_struct_ufunc_tests(void);
PyMODINIT_FUNC PyInit_operand_flag_tests(void);

PyMODINIT_FUNC PyInit_missing(void);
PyMODINIT_FUNC PyInit_json(void);
PyMODINIT_FUNC PyInit_indexing(void);
PyMODINIT_FUNC PyInit_writers(void);
PyMODINIT_FUNC PyInit_index(void);
PyMODINIT_FUNC PyInit_interval(void);
PyMODINIT_FUNC PyInit_algos(void);
PyMODINIT_FUNC PyInit_reshape(void);
PyMODINIT_FUNC PyInit_sparse(void);
PyMODINIT_FUNC PyInit_parsers(void);
PyMODINIT_FUNC PyInit_reduction(void);
PyMODINIT_FUNC PyInit_indexers(void);
PyMODINIT_FUNC PyInit_aggregations(void);
PyMODINIT_FUNC PyInit_hashing(void);
PyMODINIT_FUNC PyInit_ccalendar(void);
PyMODINIT_FUNC PyInit_np_datetime(void);
PyMODINIT_FUNC PyInit_timestamps(void);
PyMODINIT_FUNC PyInit_base(void);
PyMODINIT_FUNC PyInit_offsets(void);
PyMODINIT_FUNC PyInit_vectorized(void);
PyMODINIT_FUNC PyInit_nattype(void);
PyMODINIT_FUNC PyInit_period(void);
PyMODINIT_FUNC PyInit_timezones(void);
PyMODINIT_FUNC PyInit_fields(void);
PyMODINIT_FUNC PyInit_parsing(void);
PyMODINIT_FUNC PyInit_dtypes(void);
PyMODINIT_FUNC PyInit_conversion(void);
PyMODINIT_FUNC PyInit_tzconversion(void);
PyMODINIT_FUNC PyInit_strptime(void);
PyMODINIT_FUNC PyInit_timedeltas(void);
PyMODINIT_FUNC PyInit_ops_dispatch(void);
PyMODINIT_FUNC PyInit_properties(void);
PyMODINIT_FUNC PyInit_testing(void);
PyMODINIT_FUNC PyInit_internals(void);
PyMODINIT_FUNC PyInit_join(void);
PyMODINIT_FUNC PyInit_lib(void);
PyMODINIT_FUNC PyInit_arrays(void);
PyMODINIT_FUNC PyInit_ops(void);
PyMODINIT_FUNC PyInit_groupby(void);
PyMODINIT_FUNC PyInit_hashtable(void);
PyMODINIT_FUNC PyInit_tslib(void);
PyMODINIT_FUNC PyInit__byteswap(void);
PyMODINIT_FUNC PyInit__sas(void);

typedef struct {
    const char *name;
    PyMODINIT_FUNC initfunc;
} _inittab;

struct _inittab _extensions[] = {
   {"numpy.core._multiarray_umath", PyInit__multiarray_umath},
   {"numpy.core._simd", PyInit__simd},
   {"numpy.fft._pocketfft_internal", PyInit__pocketfft_internal},
   {"numpy.linalg._umath_linalg", PyInit__umath_linalg},
   {"numpy.linalg.lapack_lite", PyInit_lapack_lite},
   {"numpy.random._common", PyInit__common},
   {"numpy.random._sfc64", PyInit__sfc64},
   {"numpy.random._pcg64", PyInit__pcg64},
   {"numpy.random.mtrand", PyInit_mtrand},
   {"numpy.random._bounded_integers", PyInit__bounded_integers},
   {"numpy.random._generator", PyInit__generator},
   {"numpy.random._philox", PyInit__philox},
   {"numpy.random._mt19937", PyInit__mt19937},
   {"numpy.random.bit_generator", PyInit_bit_generator},
   {"numpy.core._umath_tests", PyInit__umath_tests},
   {"numpy.core._multiarray_tests", PyInit__multiarray_tests},
   {"numpy.core._rational_tests", PyInit__rational_tests},
   //{"numpy.core._struct_ufunc_tests", PyInit_struct_ufunc_tests},
   //{"numpy.core._operand_flag_tests", PyInit_operand_flag_tests},
   {"pandas._libs.missing", PyInit_missing},
   {"pandas._libs.json", PyInit_json},
   {"pandas._libs.indexing", PyInit_indexing},
   {"pandas._libs.writers", PyInit_writers},
   {"pandas._libs.index", PyInit_index},
   {"pandas._libs.interval", PyInit_interval},
   {"pandas._libs.algos", PyInit_algos},
   {"pandas._libs.reshape", PyInit_reshape},
   {"pandas._libs.sparse", PyInit_sparse},
   {"pandas._libs.parsers", PyInit_parsers},
   {"pandas._libs.reduction", PyInit_reduction},
   {"pandas._libs.window.indexers", PyInit_indexers},
   {"pandas._libs.window.aggregations", PyInit_aggregations},
   {"pandas._libs.hashing", PyInit_hashing},
   {"pandas._libs.tslibs.ccalendar", PyInit_ccalendar},
   {"pandas._libs.tslibs.np_datetime", PyInit_np_datetime},
   {"pandas._libs.tslibs.timestamps", PyInit_timestamps},
   {"pandas._libs.tslibs.base", PyInit_base},
   {"pandas._libs.tslibs.offsets", PyInit_offsets},
   {"pandas._libs.tslibs.vectorized", PyInit_vectorized},
   {"pandas._libs.tslibs.nattype", PyInit_nattype},
   {"pandas._libs.tslibs.period", PyInit_period},
   {"pandas._libs.tslibs.timezones", PyInit_timezones},
   {"pandas._libs.tslibs.fields", PyInit_fields},
   {"pandas._libs.tslibs.parsing", PyInit_parsing},
   {"pandas._libs.tslibs.dtypes", PyInit_dtypes},
   {"pandas._libs.tslibs.conversion", PyInit_conversion},
   {"pandas._libs.tslibs.tzconversion", PyInit_tzconversion},
   {"pandas._libs.tslibs.strptime", PyInit_strptime},
   {"pandas._libs.tslibs.timedeltas", PyInit_timedeltas},
   {"pandas._libs.ops_dispatch", PyInit_ops_dispatch},
   {"pandas._libs.properties", PyInit_properties},
   {"pandas._libs.testing", PyInit_testing},
   {"pandas._libs.internals", PyInit_internals},
   {"pandas._libs.join", PyInit_join},
   {"pandas._libs.lib", PyInit_lib},
   {"pandas._libs.arrays", PyInit_arrays},
   {"pandas._libs.ops", PyInit_ops},
   {"pandas._libs.groupby", PyInit_groupby},
   {"pandas._libs.hashtable", PyInit_hashtable},
   {"pandas._libs.tslib", PyInit_tslib},
   //{"pandas.io.sas._byteswap", PyInit__byteswap},
   {"pandas.io.sas._sas", PyInit__sas},
   {0, 0}
};

int find_func_name(char *path, int path_l)
//
// Find the last '.' in the given path
//
// Parameters
// ----------
// path : string
//     Period-delimited string containing the absolute path to
//     a Python function
// path_l : int
//     The length of `path`
//
// Returns
// -------
// int : the position of the last '.' in the string, or zero if
//       there is no '.'
//
{
    for (int i = path_l - 1; i > 0; i--)
    {
        if (path[i] == '.')
        {
            return i + 1;
        }
    }
    return 0;
}

static int py_initialize()
//
// Initialize the Python interpreter
//
// Returns
// -------
// int : 0 for success, -1 for error
//
{
    int rc = 0;
    PyObject *py_msgpack_str = NULL;
    PyObject *py_main_str = NULL;

    if (Py_IsInitialized()) return 0;

    for (int i = 0; _extensions[i].name; i++) {
        rc = PyImport_AppendInittab(_extensions[i].name, _extensions[i].initfunc);
        if (rc) goto error;
    }

    Py_SetProgramName(Py_DecodeLocale("python", NULL));
    Py_Initialize();

    //for (int i = 0; _extensions[i].name; i++) {
    //    PyObject *mod = _extensions[i].initfunc();
    //}

#if 0
    // Add /lib and /app to PYTHONPATH
    const char *c = "import sys\n"
                    "sys.path.insert(0, '/lib')\n"
                    "sys.path.insert(0, '/app')\n";
    rc = PyRun_SimpleString(c);
    if (rc) goto error;

    py_msgpack_str = PyUnicode_FromString("msgpack");
    if (!py_msgpack_str) goto error;

    msgpack_mod = PyImport_Import(py_msgpack_str);
    if (!msgpack_mod) goto error;

    pack = PyObject_GetAttrString(msgpack_mod, "packb");
    if (!pack) goto error;

    unpack = PyObject_GetAttrString(msgpack_mod, "unpackb");
    if (!pack) goto error;

    py_main_str = PyUnicode_FromString("__main__");
    if (!py_main_str) goto error;

    main_mod = PyImport_Import(py_main_str);
    if (!main_mod) goto error;
#endif

exit:
    Py_XDECREF(py_msgpack_str);
    Py_XDECREF(py_main_str);

    return rc;

error:
    if (PyErr_Occurred())
    {
        PyErr_Print();
    }
    rc = -1;
    goto exit;
}

int udf_exec(udf_string_t *code)
//
// Execute arbitrary code
//
// Parameters
// ----------
// code : string
//     The code to execute
//
// Returns
// -------
// int : 0 for success, -1 for error
//
{
    int rc = 0;
    char *c = malloc(code->len + 1);
    memcpy(c, code->ptr, code->len);
    c[code->len] = '\0';

    if (py_initialize()) goto error;

    rc = PyRun_SimpleString(c);

exit:
    if (c) free(c);
    return rc;

error:
    if (PyErr_Occurred())
    {
        PyErr_Print();
    }
    rc = -1;
    goto exit;
}

void udf_call(udf_string_t *name, udf_list_u8_t *args, udf_list_u8_t *ret)
//
// Call a function with the given arguments
//
// Parameters
// ----------
// name : string
//     Absolute path to a function. For example, `urllib.parse.urlparse`.
// args : bytes
//     MessagePack blob of function arguments
//
// Returns
// -------
// ret : MessagePack blob of function return values
//
{
    PyObject *py_func_pkg_str = NULL;
    PyObject *py_func_pkg = NULL;
    PyObject *py_func_str = NULL;
    PyObject *py_func = NULL;
    PyObject *py_func_args = NULL;
    PyObject *py_func_args_tuple = NULL;
    PyObject *py_args_bytes = NULL;
    PyObject *py_result = NULL;
    PyObject *py_out = NULL;
    PyObject *py_list = NULL;

    if (py_initialize()) goto error;

    if (!pack || !unpack) 
    {
        fprintf(stderr, "msgpack is not available\n");
        goto error;
    }

    // Import function module and function
    int pos = find_func_name(name->ptr, name->len);
    if (pos > 0)
    {
        py_func_pkg_str = PyUnicode_FromStringAndSize((char*)name->ptr, pos - 1);
        if (!py_func_pkg_str) goto error;
        py_func_pkg = PyImport_Import(py_func_pkg_str);
        if (!py_func_pkg) goto error;
        py_func_str = PyUnicode_FromStringAndSize((char*)name->ptr + pos, name->len - pos);
        if (!py_func_str) goto error;
    }
    else
    {
        py_func_pkg = main_mod;
    }

    // Convert raw args to Python bytes
    py_args_bytes = PyBytes_FromStringAndSize((char*)args->ptr, args->len);
    if (!py_args_bytes) goto error;

    // Unpack function arguments
    py_func_args = PyObject_CallOneArg(unpack, py_args_bytes);
    if (!py_func_args) goto error;

    // Look up the udf and call it
    py_func = PyObject_GetAttr(py_func_pkg, py_func_str);
    if (!py_func) goto error;

    // Call the function
    py_func_args_tuple = PyList_AsTuple(py_func_args);
    if (!py_func_args_tuple) goto error;
    py_result = PyObject_CallObject(py_func, py_func_args_tuple);
    if (!py_result) goto error;

    if (PyTuple_Check(py_result))
    {
        // Pack the result as multiple return values
        py_out = PyObject_CallOneArg(pack, py_result);
        if (!py_out) goto error;
    }
    else
    {
        py_list = PyList_New(1);
        PyList_SetItem(py_list, 0, py_result);
        py_result = NULL;
        // Pack the result as a single value
        py_out = PyObject_CallOneArg(pack, py_list);
        if (!py_out) goto error;
    }

    // Copy packed result to output
    ret->len = PyBytes_Size(py_out);
    ret->ptr = malloc(ret->len);
    if (!ret->ptr)
    {
        fprintf(stderr, "Could not allocate memory for return value\n");
        goto error;
    }
    memcpy(ret->ptr, PyBytes_AsString(py_out), ret->len);

exit:
    Py_XDECREF(py_func_pkg_str);
    Py_XDECREF(py_func_pkg);
    Py_XDECREF(py_func_str);
    Py_XDECREF(py_func);
    Py_XDECREF(py_args_bytes);
    Py_XDECREF(py_func_args);
    Py_XDECREF(py_func_args_tuple);
    Py_XDECREF(py_result);
    Py_XDECREF(py_out);
    Py_XDECREF(py_list);
    return;

error:
    if (PyErr_Occurred())
    {
        PyErr_Print();
    }
    ret->ptr = NULL;
    ret->len = 0;
    goto exit;
}

int main(int argc, char *argv[]) {
    py_initialize();
    //PyRun_SimpleString("print('hi there')");
    //PyRun_SimpleString("import numpy\narr = numpy.array([0,1,2])\nprint(arr)");
    //PyRun_SimpleString("from importlib import import_module\nprint(import_module('numpy.core._multiarray_umath'))");
    //PyRun_SimpleString("import _imp\nprint('IS-BUILTIN', _imp.is_builtin('numpy.core._multiarray_umath'))");
    //PyRun_SimpleString("import sys\nprint(sys.path)\nprint(sorted(sys.builtin_module_names))");
    //PyRun_SimpleString("import sys\nprint(sorted(sys.modules.keys()))");
    //PyRun_SimpleString("from importlib import _bootstrap\nprint(_bootstrap)");
    //PyRun_SimpleString("import numpy.core._multiarray_umath");
    //PyRun_SimpleString("import numpy\narr = numpy.array([0,1,2])\nprint(arr)");
    PyRun_SimpleString(
        "import platform\n"
        "print(platform.platform(), '\\n')\n"
        "\n"
        "import numpy as np\n"
        "arr = np.array([[0, 1, 2], [3, 4, 5]])\n"
        "print(arr, '\\n')\n"
        "\n"
        "import pandas as pd\n"
        "df = pd.DataFrame([[1.234, 2, 'hi'], [3.14, 3, 'bye']], columns=['a', 'b', 'c'])\n"
        "print('COLUMNS', df.columns)\n"
        "print('DTYPES', df.dtypes, '\\n')\n"
        "print(df, '\\n')\n"
        "\n"
        "df = pd.DataFrame([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]], columns=['a', 'b', 'c'])\n"
        "df2 = df * 3.14\n"
        "print(df2, '\\n')\n"
        "\n"
        "print(df.mean(), '\\n')\n"
        "print(df2.mean(), '\\n')\n"
    );
    return 1;
}
