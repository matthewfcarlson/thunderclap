class C { public: char pad[0x8ac]; float value; void Target(int x); };
float __cdecl Calc(int x);
void C::Target(int x) { value = Calc(x); }