class Manager_266b30 {
  public:
    int Get();
    void Fn(int*, int, int, int);
};
struct E_266b30 {
    int a, b, c, d;
};
class Obj_266b30 {
  public:
    char pad0[0x80];
    E_266b30 e[1];
    char pad1[0x280 - 0x90];
    int count;
    Manager_266b30* mgr;
    int Target(int);
};
int Obj_266b30::Target(int arg) {
    count++;
    e[count].d = mgr->Get() - 4;
    e[count].a = arg;
    mgr->Fn(&arg, 1, 4, 1);
    e[count].b = arg;
    mgr->Fn(&arg, 1, 4, 1);
    e[count].c = arg;
    return e[count].a;
}
