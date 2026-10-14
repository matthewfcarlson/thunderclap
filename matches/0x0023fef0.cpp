typedef unsigned int U_23fef0;
class Obj_23fef0 {
  public:
    void Use(char* p);
};
extern "C" void __cdecl CopyLike(char* buf, U_23fef0 size, U_23fef0 v, void* p);
Obj_23fef0* __cdecl Target(Obj_23fef0* a, U_23fef0 b, void* c) {
    char buf[0x1000];
    CopyLike(buf, 0x1000, b, &c);
    buf[0xfff] = 0;
    a->Use(buf);
    return a;
}
