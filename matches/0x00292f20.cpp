class X { char pad[0x114]; public: int value; };
int __fastcall target(X* self) { return self->value; }