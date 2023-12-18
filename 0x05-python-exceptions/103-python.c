#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/**
 * print_python_list - Print information about Python lists
 * @p: PyObject pointer to a Python object
 */
void print_python_list(PyObject *p) {
    Py_ssize_t size, alloc, i;
    PyObject *item;

    if (!PyList_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);
    alloc = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", alloc);

    for (i = 0; i < size; i++) {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyFloat_Check(item))
            print_python_float(item);
    }
}

/**
 * print_python_bytes - Print information about Python bytes
 * @p: PyObject pointer to a Python object
 */
void print_python_bytes(PyObject *p) {
    Py_ssize_t size, i;
    char *str;

    if (!PyBytes_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    str = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    printf("  first %ld bytes: ", size + 1 > 10 ? 10 : size + 1);
    for (i = 0; i < size + 1 && i < 10; i++)
        printf("%02x%c", str[i] & 0xFF, i == size || i == 9 ? '\n' : ' ');
}

/**
 * print_python_float - Print information about Python float
 * @p: PyObject pointer to a Python object
 */
void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Float Object\n");
        return;
    }

    printf("[.] float object info\n");
    printf("  value: %lf\n", PyFloat_AsDouble(p));
}
