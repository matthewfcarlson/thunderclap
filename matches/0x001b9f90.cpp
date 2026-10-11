extern "C" char DAT_00420e74[];
extern "C" char DAT_0048e0f0[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0049b95c[];
extern "C" void __stdcall FUN_001d0480(unsigned int, unsigned int);
extern "C" char FUN_001d04d0(const char*);
class CRenderManager {
  public:
    CRenderManager(unsigned int, unsigned int);
    int vptr;
    char pad04[0x0c];
    char b10, b11, b12, b13, b14, b15, b16, b17, b18;
    char pad19[3];
    int field1c;
};
CRenderManager::CRenderManager(unsigned int a, unsigned int b) {
    FUN_001d0480(a, 4);
    vptr = ((int)DAT_00420e74);
    field1c = b;
    b18 = FUN_001d04d0((const char*)((int)DAT_0049b95c));
    b10 = FUN_001d04d0((const char*)((int)DAT_0048e0f0));
    b11 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    b12 = FUN_001d04d0((const char*)((int)DAT_0048e128));
    b13 = FUN_001d04d0((const char*)((int)DAT_0048e128));
}