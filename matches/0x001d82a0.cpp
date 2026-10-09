class Base { public: virtual void A(); virtual void B(); };
class Obj { public: char pad[0x21c]; Base* ptr; void Do(); };
void __fastcall target(Obj* self) { self->Do(); if (self->ptr) { self->ptr->B(); self->ptr = 0; } }