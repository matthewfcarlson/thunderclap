class Obj { char pad[0x22b4]; public: int value; };
int __fastcall target(Obj* self) { return self->value; }