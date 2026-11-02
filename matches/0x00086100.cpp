extern float scale_86100;
extern "C" void __cdecl FUN_001eb200();
class Thing_86100 {
  public:
    char pad[0x38];
    __int64 value;
    void Set(float);
};
void Thing_86100::Set(float x) {
    value = (__int64)(x * 65536.0f);
    FUN_001eb200();
}