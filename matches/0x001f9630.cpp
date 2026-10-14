struct Obj_1f9630 {
    char pad[0x20];
    unsigned short value;
};
extern "C" void FUN_001f92f0();
class R_1f9630 {
  public:
    Obj_1f9630* find(void (*)(), void*);
};
class C_1f9630 {
  public:
    char pad[0xc6c];
    R_1f9630* field;
    unsigned short target(int a, int b, int c, int d);
};
class Cleanup_1f9630 {
  public:
    void go();
};
unsigned short C_1f9630::target(int a, int b, int c, int d) {
    Obj_1f9630* o = field->find(FUN_001f92f0, (void*)&a);
    if (!o) {
        ((Cleanup_1f9630*)&a)->go();
        return 0xfffe;
    }
    unsigned short v = o->value;
    ((Cleanup_1f9630*)&a)->go();
    return v;
}
