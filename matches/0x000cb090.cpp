struct Vec {
    float x, y, z;
};
class Mgr {
  public:
    int Run(int, int, Vec, Vec);
};
class Obj {
    char pad[0x88];
    Mgr* mgr;

  public:
    int Go(int a, int b, Vec c, Vec d);
};
int Obj::Go(int a, int b, Vec c, Vec d) {
    int result = -1;
    if (mgr)
        result = mgr->Run(a, b, c, d);
    return result;
}