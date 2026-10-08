class C { char pad[0x6f]; public: unsigned char value; };
unsigned char __fastcall target(C* self) { return self->value; }