class Obj {
  public:
    void Fn(void*, unsigned char*);
};
struct A {
    char pad[0x28];
    int count;
};
struct B {
    char pad[0x3c];
    unsigned char* bytes;
};
struct C {
    char pad[0x44];
    B* b;
};
class Controller {
  public:
    char pad0[0x34];
    void* p34;
    char pad38[4];
    A* p3c;
    C* p40;
    Obj** p44;
    char pad48[8];
    unsigned char* p50;
    void vfunc_0();
    void vfunc_1();
    void vfunc_2();
    void vfunc_3();
    void vfunc_4();
    void vfunc_5();
    void vfunc_6();
    void vfunc_7();
};
void Controller::vfunc_7() {
    int n = p3c->count;
    for (int i = 0; i < n; i++) {
        if (p50[i] != 0xff && p44[i]) {
            unsigned char x;
            p44[i]->Fn(p34, &x);
            p40->b->bytes[p50[i] * 12] = x;
        }
    }
}
