#include "union_find.hpp"
#include <numeric>

UF::UF(int N) : N(N) {};

QuickFind::QuickFind(int N) : UF(N), ids(N) {
  std::iota(ids.begin(), ids.end(), 0);
};

void QuickFind::union_elements(int p, int q) {
  int new_id = ids[p];
  int old_id = ids[q];
  if (new_id == old_id)
    return;
  for (int i = 0; i < N; i++) {
    if (ids[i] == old_id)
      ids[i] = new_id;
  }
};

bool QuickFind::connected(int p, int q) { return ids[p] == ids[q]; };

QuickUnion::QuickUnion(int N) : UF(N), ids(N) {
  std::iota(ids.begin(), ids.end(), 0);
};

int QuickUnion::root(int index) {
  while (ids[index] != index) {
    index = ids[index];
  };
  return index;
};

void QuickUnion::union_elements(int p, int q) { ids[p] = root(q); };

bool QuickUnion::connected(int p, int q) { return root(p) == root(q); };

WeightedUnion::WeightedUnion(int N) : QuickUnion(N), sizes(N, 1) {};

void WeightedUnion::union_elements(int p, int q) {
  int i = root(p);
  int j = root(q);
  if (sizes[i] < sizes[j]) {
    ids[i] = j;
    sizes[j] = sizes[j] + sizes[i];
  } else {
    ids[j] = i;
    sizes[i] = sizes[i] + sizes[j];
  }
};
