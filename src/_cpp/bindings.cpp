#include "union_find.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

class PyUF : public UF {
public:
  /* Inherit the constructors */
  using UF::UF;

  /* Trampoline (need one for each virtual function) */
  void union_elements(int p, int q) override {
    PYBIND11_OVERRIDE_PURE(
        void,           /* Return type */
        UF,             /* Parent class */
        union_elements, /* Name of function in C++ (must match Python name) */
        p, q            /* Argument(s) */
    );
  }

  bool connected(int p, int q) override {
    PYBIND11_OVERRIDE_PURE(bool, UF, connected, p, q);
  }
};

PYBIND11_MODULE(_core, m) {
  m.doc() = R"pbdoc(
      Pybind11 example plugin
      -----------------------
      .. currentmodule:: python_example
      .. autosummary::
         :toctree: _generate
         add
         subtract
  )pbdoc";

  py::class_<UF, PyUF /* <--- trampoline*/>(m, "UF")
      .def(py::init<int>())
      .def("union", &UF::union_elements)
      .def("connected", &UF::connected);

  py::class_<QuickFind, UF>(m, "QuickFind")
      .def(py::init<int>())
      .def("union", &QuickFind::union_elements)
      .def("connected", &QuickFind::connected);

  py::class_<QuickUnion, UF>(m, "QuickUnion")
      .def(py::init<int>())
      .def("union", &QuickUnion::union_elements)
      .def("connected", &QuickUnion::connected);

  py::class_<WeightedUnion, QuickUnion>(m, "WeightedUnion")
      .def(py::init<int>())
      .def("union", &WeightedUnion::union_elements)
      .def("connected", &WeightedUnion::connected);
}
