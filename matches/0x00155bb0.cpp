extern "C" char DAT_00414ad0[];
extern "C" char DAT_0042773c[];
extern "C" void* __cdecl Alloc(unsigned int);
class Param {
  public:
    void Init(const char*);
    char pad[0x20];
};
extern "C" void __cdecl Register(void*, void**, int);
extern "C" int gCount;
extern "C" void* gSlot;
extern "C" int gValue;
void FUN_00155bb0() {
    if (gCount) {
        ++gCount;
        return;
    }
    void* tmp;
    Param* p = (Param*)Alloc(0x20);
    if (p) {
        int v = gValue;
        p->Init("compare");
        *(int*)((char*)p + 0x14) = v;
        *(int*)p = ((int)DAT_00414ad0);
        *(int*)((char*)p + 0x10) = ((int)DAT_0042773c);
        *(int*)((char*)p + 0x18) = 0x14c730;
        tmp = p;
    } else
        tmp = 0;
    Register(&gSlot, &tmp, 1);
    ++gCount;
}