extern "C" char DAT_004233f8[];
class Obj_1e0550 {
  public:
    int v;
    char pad[0x14];
    char b18;
    char p19[3];
    int m1c;
    char p20[0x20];
    void Init(const char*, int);
    Obj_1e0550* Make(const char*, int);
};
extern char gA_1e0550[];
extern char gB_1e0550[];
extern char gC_1e0550[];
extern char __cdecl FUN_001d04d0(const char*);
Obj_1e0550* Obj_1e0550::Make(const char* p, int x) {
    Init(p, 5);
    v = ((int)DAT_004233f8);
    m1c = x;
    b18 = FUN_001d04d0(gA_1e0550);
    pad[12] = FUN_001d04d0(gB_1e0550);
    pad[13] = FUN_001d04d0(gB_1e0550);
    pad[14] = FUN_001d04d0(gC_1e0550);
    pad[15] = FUN_001d04d0(gC_1e0550);
    pad[16] = FUN_001d04d0(gC_1e0550);
    return this;
}