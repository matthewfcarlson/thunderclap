extern "C" char DAT_00420e44[];
extern char Helper(const char*);
extern const char g1[];
extern const char g2[];
class Base {
  public:
    void Init(int, int);
};
class Obj : public Base {
  public:
    int v;
    char p[12];
    char a[9];
    char p2[3];
    int field;
    Obj(int, int);
};
Obj::Obj(int x, int y) {
    Init(x, 6);
    v = ((int)DAT_00420e44);
    field = y;
    a[8] = Helper(g1);
    a[0] = Helper(g2);
    a[1] = Helper(g2);
    a[2] = Helper(g2);
    a[3] = Helper(g2);
    a[4] = Helper(g2);
    a[5] = Helper(g2);
}