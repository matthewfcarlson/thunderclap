class Base {
  public:
    void Init(int, int);
};
extern "C" char __cdecl GetFlag(const char*);
class Obj : public Base {
  public:
    int v;
    char pad[0x14];
    char m18;
    char pad2[3];
    int n;
    Obj(int, int);
};
Obj::Obj(int a, int b) {
    Init(a, 4);
    v = 0x40a590;
    n = b;
    m18 = GetFlag((const char*)0x48e134);
    *((char*)this + 0x10) = GetFlag((const char*)0x48e134);
    *((char*)this + 0x11) = GetFlag((const char*)0x48e134);
    *((char*)this + 0x12) = GetFlag((const char*)0x48e10c);
    *((char*)this + 0x13) = GetFlag((const char*)0x48e10c);
}