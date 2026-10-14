struct Triple {
    int a, b, c;
};
class Mgr {
  public:
    void Fn(int, int, int, int, int, int, int, int, Triple, int, int, int);
};
class Obj {
    char pad[24];
    Mgr* mgr;

  public:
    void Go(int, int, int, int, int, int, int, int, Triple, int, int, int);
};
void Obj::Go(int a, int b, int c, int d, int e, int f, int g, int h, Triple t, int j, int k, int l) {
    mgr->Fn(a, b, c, d, e, f, g, h, t, j, k, l);
}