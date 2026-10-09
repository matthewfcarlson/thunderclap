extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" char __cdecl FUN_001d04d0(const char*);
extern const char g1[];
extern const char g2[];
class Target {
  public:
    int v;
    char p[0x24];
    Target* Fn(void* a, int b, void* c);
};
Target* Target::Fn(void* a, int b, void* c) {
    FUN_001d0480(a, 1);
    v = 0x3f42cc;
    *(int*)((char*)this + 0x1c) = (int)c;
    *((char*)this + 0x18) = FUN_001d04d0(g1);
    *((char*)this + 0x10) = FUN_001d04d0(g2);
    v = 0x3f45ec;
    *(int*)((char*)this + 0x20) = b;
    return this;
}