extern "C" char DAT_00405ea8[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0048e134[];
class CHapticControllerManager {
  public:
    void Init(int, int);
    CHapticControllerManager(int, int);
};
extern "C" unsigned char __cdecl Read(const char*);
CHapticControllerManager::CHapticControllerManager(int a, int b) {
    Init(a, 4);
    *(int*)this = ((int)DAT_00405ea8);
    *(int*)((char*)this + 0x1c) = b;
    *(char*)((char*)this + 0x18) = Read((const char*)((int)DAT_0048e100));
    *(char*)((char*)this + 0x10) = Read((const char*)((int)DAT_0048e134));
    *(char*)((char*)this + 0x11) = Read((const char*)((int)DAT_0048e128));
    *(char*)((char*)this + 0x12) = Read((const char*)((int)DAT_0048e128));
    *(char*)((char*)this + 0x13) = Read((const char*)((int)DAT_0048e128));
}
