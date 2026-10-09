struct Obj { char pad[0x1e4]; float value; };
extern const float zero;
int __fastcall target(Obj* self) { return self->value > zero; }