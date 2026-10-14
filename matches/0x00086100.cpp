extern float scale_86100;
void __cdecl Finish();
class Thing_86100 {
  public:
    char pad[0x38];
    __int64 value;
    void Set(float);
};
void Thing_86100::Set(float x) {
    value = (__int64)(x * 65536.0f);
    Finish();
}