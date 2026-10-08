class C { public: char pad[0x0c]; int value; };
int __fastcall target(C* self) { return self->value + 0x14; }