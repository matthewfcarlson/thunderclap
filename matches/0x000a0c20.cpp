class Obj { public: char pad[0x49c]; float value; };
float __fastcall target(Obj* self) { return self->value; }