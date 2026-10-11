extern "C" char DAT_004233f8[];
class Obj {
  public:
    int v;
    char pad[0x14];
    char b18;
    char p19[3];
    int m1c;
    char p20[0x20];
    void Init(const char*, int);
    Obj* Make(const char*, int);
};
extern char gA[];
extern char gB[];
extern char gC[];
extern char __cdecl FUN_001d04d0(const char*);
Obj* Obj::Make(const char* p, int x) {
    Init(p, 5);
    v = ((int)DAT_004233f8);
    m1c = x;
    b18 = FUN_001d04d0(gA);
    pad[12] = FUN_001d04d0(gB);
    pad[13] = FUN_001d04d0(gB);
    pad[14] = FUN_001d04d0(gC);
    pad[15] = FUN_001d04d0(gC);
    pad[16] = FUN_001d04d0(gC);
    return this;
}