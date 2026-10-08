class C { char pad[0x14a8]; public: unsigned char value; };
unsigned char __fastcall target(C* self) { return self->value; }