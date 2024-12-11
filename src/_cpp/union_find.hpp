#pragma once
#include <vector>

class UF {
protected:
  int N;

public:
  UF(int N);
  virtual ~UF() = default;
  virtual void union_elements(int p, int q) = 0;
  virtual bool connected(int p, int q) = 0;
};

class QuickFind : public UF {
private:
  std::vector<int> ids;

public:
  QuickFind(int N);
  void union_elements(int p, int q) override;
  bool connected(int p, int q) override;
};

class QuickUnion : public UF {
protected:
  std::vector<int> ids;
  int root(int index);

public:
  QuickUnion(int N);
  void union_elements(int p, int q) override;
  bool connected(int p, int q) override;
};

class WeightedUnion : public QuickUnion {
private:
  std::vector<int> sizes;

public:
  WeightedUnion(int N);
  void union_elements(int p, int q) override;
};
