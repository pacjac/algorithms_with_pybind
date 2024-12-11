from __future__ import annotations

import importlib.metadata

import algo as m


def test_version():
    assert importlib.metadata.version("algo") == m.__version__
