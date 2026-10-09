typedef unsigned int U;
class Obj {
  public:
    void Use(char* p);
};
extern "C" void __cdecl CopyLike(char* buf, U size, U v, void* p);
Obj* __cdecl Target(Obj* a, U b, void* c) {
    char buf[0x1000];
    CopyLike(buf, 0x1000, b, &c);
    buf[0xfff] = 0;
    a->Use(buf);
    return a;
}
