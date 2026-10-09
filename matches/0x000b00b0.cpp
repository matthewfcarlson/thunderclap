class CHapticControllerManager {
  public:
    void Init(int, int);
    CHapticControllerManager(int, int);
};
extern "C" unsigned char __cdecl Read(const char*);
CHapticControllerManager::CHapticControllerManager(int a, int b) {
    Init(a, 4);
    *(int*)this = 0x405ea8;
    *(int*)((char*)this + 0x1c) = b;
    *(char*)((char*)this + 0x18) = Read((const char*)0x48e100);
    *(char*)((char*)this + 0x10) = Read((const char*)0x48e134);
    *(char*)((char*)this + 0x11) = Read((const char*)0x48e128);
    *(char*)((char*)this + 0x12) = Read((const char*)0x48e128);
    *(char*)((char*)this + 0x13) = Read((const char*)0x48e128);
}
