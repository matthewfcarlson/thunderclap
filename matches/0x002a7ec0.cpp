class Obj_2a7ec0 {
  public:
    void Fn(void*, unsigned char*);
};
struct A_2a7ec0 {
    char pad[0x28];
    int count;
};
struct B_2a7ec0 {
    char pad[0x3c];
    unsigned char* bytes;
};
struct C_2a7ec0 {
    char pad[0x44];
    B_2a7ec0* b;
};
class Controller_2a7ec0 {
  public:
    char pad0[0x34];
    void* p34;
    char pad38[4];
    A_2a7ec0* p3c;
    C_2a7ec0* p40;
    Obj_2a7ec0** p44;
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
void Controller_2a7ec0::vfunc_7() {
    int n = p3c->count;
    for (int i = 0; i < n; i++) {
        if (p50[i] != 0xff && p44[i]) {
            unsigned char x;
            p44[i]->Fn(p34, &x);
            p40->b->bytes[p50[i] * 12] = x;
        }
    }
}
