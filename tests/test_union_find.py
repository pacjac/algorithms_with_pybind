from __future__ import annotations

import algo._core as m


def test_quickfind() -> None:
    uf = m.QuickFind(10)

    uf.union(6, 4)
    uf.union(9, 0)
    uf.union(5, 4)

    assert uf.connected(5, 6)


def test_quickunion() -> None:
    uf = m.QuickUnion(10)

    uf.union(6, 4)
    uf.union(9, 0)
    uf.union(5, 4)

    assert uf.connected(5, 6)


def test_quickfind_not_connected() -> None:
    uf = m.QuickFind(10)

    assert not uf.connected(1, 2)


def test_quickunion_not_connected() -> None:
    uf = m.QuickUnion(10)

    assert not uf.connected(1, 2)
