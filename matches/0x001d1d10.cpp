typedef unsigned int uint;
void __cdecl DoThing(uint, int);
class Target { char pad[8]; uint value; public: unsigned char __fastcall Run(); };
unsigned char __fastcall Target::Run() { DoThing(value, -3); return 1; }