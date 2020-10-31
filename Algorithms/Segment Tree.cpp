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
  int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
    if (l <= tl && tr <= r) return t[v];
    if (tl > r || tr < l) return 0;
    int tm = tl + tr >> 1;
    return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
  }
  void change(int pos, int val, int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
      t[v] = val;
      return;
    } 
    int tm = tl + tr >> 1;
    if (pos <= tm) change(pos, val, v << 1, tl, tm);
    else change(pos, val, v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
};
