typedef unsigned char byte;
extern void __cdecl thunk(unsigned int);
class Obj { public: unsigned int a; char pad[8]; unsigned int b; Obj* target(byte p); };
Obj* Obj::target(byte p) { thunk(a); thunk(b); if (p & 1) thunk((unsigned int)this); return this; }