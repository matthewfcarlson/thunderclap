class C { char pad[0x11a8]; public: float value; };
float __fastcall target(C* self) { return self->value; }