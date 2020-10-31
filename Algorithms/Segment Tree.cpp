struct tree {
  ll t[N << 2], u[N << 2];
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
  void push(int v, int tl, int tr) {
    if (u[v]) {
      int tm = tl + tr >> 1;
      t[v << 1] += u[v] * (tm - tl + 1);
      t[v << 1 | 1] += u[v] * (tr - tm);
      u[v << 1] += u[v];
      u[v << 1 | 1] += u[v];
      u[v] = 0;
    }
  }
  int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
    if (l <= tl && tr <= r) return t[v];
    if (tl > r || tr < l) return 0;
    int tm = tl + tr >> 1;
    push(v, tl, tr);
    return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
  }
  void change(int pos, int val, int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
      t[v] = val;
      return;
    } 
    int tm = tl + tr >> 1;
    push(v, tl, tr);
    if (pos <= tm) change(pos, val, v << 1, tl, tm);
    else change(pos, val, v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
  void upd(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
    if (l <= tl && tr <= r) {
      t[v] += x * (tr - tl + 1);
      u[v] += x;
      return;
    }
    if (tl > r || tr < l) return;
    int tm = tl + tr >> 1;
    push(v, tl, tr);    
    upd(l, r, x, v << 1, tl, tm);
    upd(l, r, x, v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
};
