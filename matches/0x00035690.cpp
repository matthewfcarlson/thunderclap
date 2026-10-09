extern "C" double __cdecl sqrt(double);
class Obj { public: char pad[0x74]; float a; char pad2[4]; float b; };
float __fastcall FUN_00035690(Obj* p) { return (float)sqrt((double)p->b * p->b + (double)p->a * p->a); }