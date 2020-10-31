struct tree {
  int t[N << 2];
  void biuld(int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
};
