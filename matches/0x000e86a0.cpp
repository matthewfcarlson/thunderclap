extern const float limit = -1.0f;
class Obj { public: char pad0[0x3c]; float value; char pad40[4]; float input; char pad48[8]; unsigned char flag; void Set(float); };
void Obj::Set(float x) { input = x; if (value > limit && x > limit) { int r; if (value <= x) r = 1; else r = 0; flag = (unsigned char)r; } }
