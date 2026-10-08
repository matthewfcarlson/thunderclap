// Same code shape as 0x000862d0 (propagated; names are from that function)
struct X { char pad[0x14]; unsigned value; };
unsigned __fastcall target(X* self) { return self->value; }