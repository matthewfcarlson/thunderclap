class Obj { public: char pad[0x64]; float a; float b; unsigned char dirty; void Set(float x, float y); };
void Obj::Set(float x, float y) { if (a != x || b != y) { a=x; b=y; dirty=0; } }