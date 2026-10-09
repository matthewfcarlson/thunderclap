extern "C" void __stdcall Init(void*, int);
extern "C" char __cdecl ReadBool(const char*);
extern const char A[];
extern const char B[];
extern const char C[];
class CTriggerVolumeManager {
  public:
    int vptr;
    char pad4[12];
    char b10;
    char b11;
    char b12;
    char b13;
    char pad14[4];
    char b18;
    char pad19[3];
    int value;
    CTriggerVolumeManager(int x, int y);
};
CTriggerVolumeManager::CTriggerVolumeManager(int x, int y) {
    Init((void*)x, 4);
    vptr = 0x425354;
    value = y;
    b18 = ReadBool(A);
    b10 = ReadBool(B);
    b11 = ReadBool(C);
    b12 = ReadBool(C);
    b13 = ReadBool(A);
}