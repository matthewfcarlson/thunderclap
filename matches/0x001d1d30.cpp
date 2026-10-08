typedef unsigned int u32;
void __cdecl Helper(u32, int);
class Target { public: char pad[8]; u32 field; };
unsigned char __fastcall FUN_001d1d30(Target* self) { Helper(self->field, -2); return 1; }