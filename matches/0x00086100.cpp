extern float scale;
void __cdecl Finish();
class Thing { public: char pad[0x38]; __int64 value; void Set(float); };
void Thing::Set(float x) { value = (__int64)(x * 65536.0f); Finish(); }