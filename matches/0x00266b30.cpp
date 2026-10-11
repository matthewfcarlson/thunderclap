class Manager {
  public:
    int Get();
    void Fn(int*, int, int, int);
};
struct E {
    int a, b, c, d;
};
class Obj {
  public:
    char pad0[0x80];
    E e[1];
    char pad1[0x280 - 0x90];
    int count;
    Manager* mgr;
    int Target(int);
};
int Obj::Target(int arg) {
    count++;
    e[count].d = mgr->Get() - 4;
    e[count].a = arg;
    mgr->Fn(&arg, 1, 4, 1);
    e[count].b = arg;
    mgr->Fn(&arg, 1, 4, 1);
    e[count].c = arg;
    return e[count].a;
}
