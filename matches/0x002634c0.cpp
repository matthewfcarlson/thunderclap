struct X { char pad[0x10]; int a; char pad14[4]; int b; int c; };
X* __fastcall FUN_002634c0(X* self) { X* p = self; p->a = 0; p->b = 0; p->c = 0; return p; }
