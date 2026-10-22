// cl-flags: /Oy-

int g_4dd834;
int g_4dd830;

void FUN_0008ed60();
void FUN_0008d660();
void FUN_0026f070();
void FUN_0026eea0(int, int, int, int);
void thunk_FUN_002709b0(int, int, int, int);
void thunk_FUN_00270f10(int, int);
void FUN_00265b70(int);
void FUN_0008fca0();
void* FUN_0008d690(int);
void FUN_00333b80();
void FUN_00268490();
void FUN_00265c40();
void thunk_FUN_00270f90(int);
void thunk_FUN_00271070();
void FUN_0026f000();
void FUN_0026eeb0();
void FUN_00266d70();
void FUN_0026dab0();
void FUN_00267a90();

class CGame_8ee30 {
  public:
    CGame_8ee30* Ctor();
    void Init();
    virtual void Vfn(int);
};

int FUN_0008ee30() {
    g_4dd834 += 0x15b;
    FUN_0008ed60();
    g_4dd830 = 0x2ad2b093;
    FUN_0008d660();
    FUN_0026f070();
    FUN_0026eea0(2, 0x2148, 0, 0);
    thunk_FUN_002709b0(0x32, 0x20, 0x8000, 0);
    thunk_FUN_00270f10(0, 0);
    FUN_00265b70(0);
    FUN_0008fca0();
    CGame_8ee30* esi;
    void* p = FUN_0008d690(0x54);
    if (p)
        esi = ((CGame_8ee30*)p)->Ctor();
    else
        esi = 0;
    esi->Init();
    if (esi)
        esi->Vfn(1);
    FUN_00333b80();
    FUN_00268490();
    FUN_00265c40();
    thunk_FUN_00270f90(0);
    thunk_FUN_00271070();
    FUN_0026f000();
    FUN_0026eeb0();
    FUN_00266d70();
    FUN_0026dab0();
    FUN_00267a90();
    return 0;
}
