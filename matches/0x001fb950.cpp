class Obj { public: char pad[0xcd]; unsigned char a; char pad2; unsigned char b; int c; };
void __fastcall target(Obj* p) { p->a = p->b; p->c = 0; }