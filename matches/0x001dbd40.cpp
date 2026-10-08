class Obj { public: char pad[0x1eee4]; int x; };
void __fastcall target(Obj* self) { self->x = 0x32; }