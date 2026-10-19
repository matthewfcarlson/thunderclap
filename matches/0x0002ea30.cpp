extern void* VT_Method1[2];
extern void* VT_Closure1[2];
extern void* TAB_48e0f0;

struct Ctor_001d0480 {
    Ctor_001d0480(void* a1, int b);
};
char __cdecl LookupFlag(const void* tbl);

class Closure1 : public Ctor_001d0480 {
  public:
    void* vfptr;
    char pad04[12];
    char mFlag10;
    char pad11[7];
    char mFlag18;
    char pad19[3];
    int mA3;
    int mA2;

    Closure1(void* a1, int a2, int a3);
};

Closure1::Closure1(void* a1, int a2, int a3) : Ctor_001d0480(a1, 1) {
    vfptr = (void*)VT_Method1;
    mA3 = a3;
    mFlag18 = LookupFlag(&TAB_48e0f0);
    mFlag10 = LookupFlag(&TAB_48e0f0);
    vfptr = (void*)VT_Closure1;
    mA2 = a2;
}
