class Thing { char pad[0x32c]; public: unsigned char a; char pad2; unsigned char b; };
unsigned char __fastcall FUN_00035d80(Thing* self) { if (self->b && self->a) return 1; return 0; }