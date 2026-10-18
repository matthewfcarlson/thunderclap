struct Triple_283d60 {
    int a, b, c;
};
class Mgr_283d60 {
  public:
    int Fn(int, int, int, int, int, int, int, int, Triple_283d60, int, int, int);
};
class Obj_283d60 {
    char pad[24];
    Mgr_283d60* mgr;

  public:
    int Go(int, int, int, int, int, int, int, int, Triple_283d60, int, int, int);
};
int Obj_283d60::Go(int a, int b, int c, int d, int e, int f, int g, int h, Triple_283d60 t, int j, int k, int l) {
    return mgr->Fn(a, b, c, d, e, f, g, h, t, j, k, l);
}