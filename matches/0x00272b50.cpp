class X { public: char pad[0x5c]; unsigned char value; };
unsigned char __fastcall target(X* self, void*) { return self->value; }