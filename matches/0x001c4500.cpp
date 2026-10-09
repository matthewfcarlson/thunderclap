extern const float gZero;
class Obj { char pad0[0x18]; float a; char pad1[0x0c]; float b; public: bool Check(); };
bool Obj::Check() { return b != 0.0f && a != 0.0f; }