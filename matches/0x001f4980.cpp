class CSoundVoiceManager {
  public:
    void Init(void*, int);
    int vf;
    char pad4[0x0c];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int a;
    CSoundVoiceManager* Fn(void*, int);
};
extern "C" char __cdecl FUN_001d04d0(void*);
CSoundVoiceManager* CSoundVoiceManager::Fn(void* p, int v) {
    Init(p, 3);
    vf = 0x424b0c;
    a = v;
    b18 = FUN_001d04d0((void*)0x48e100);
    b10 = FUN_001d04d0((void*)0x48e0e4);
    b11 = FUN_001d04d0((void*)0x48e0e4);
    b12 = FUN_001d04d0((void*)0x48e0e4);
    return this;
}