class CEffectManager {
  public:
    int vtable;
    char pad4[0x0c];
    char pad10[8];
    char c18;
    char pad19[3];
    int field1c;
    void Base(int, int);
    CEffectManager* Build(int, int);
};
extern "C" char __cdecl FUN_001d04d0(const char*);
CEffectManager* CEffectManager::Build(int a, int b) {
    Base(a, 3);
    vtable = 0x424d6c;
    field1c = b;
    c18 = FUN_001d04d0((const char*)0x49b95c);
    *((char*)this + 0x10) = FUN_001d04d0((const char*)0x49cad8);
    *((char*)this + 0x11) = FUN_001d04d0((const char*)0x48e128);
    *((char*)this + 0x12) = FUN_001d04d0((const char*)0x48e128);
    return this;
}