from __future__ import annotations

import importlib.metadata

import algo as m


def test_version():
    assert importlib.metadata.version("algorithms_with_pybind") == m.__version__
