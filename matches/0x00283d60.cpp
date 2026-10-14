struct Triple_283d60 {
    int a, b, c;
};
class Mgr_283d60 {
  public:
    void Fn(int, int, int, int, int, int, int, int, Triple_283d60, int, int, int);
};
class Obj_283d60 {
    char pad[24];
    Mgr_283d60* mgr;

  public:
    void Go(int, int, int, int, int, int, int, int, Triple_283d60, int, int, int);
};
void Obj_283d60::Go(int a, int b, int c, int d, int e, int f, int g, int h, Triple_283d60 t, int j, int k, int l) {
    mgr->Fn(a, b, c, d, e, f, g, h, t, j, k, l);
}