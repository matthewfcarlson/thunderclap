struct Obj { char pad[0x20c]; int a; int b; int c; };
void FUN_002e6ba0(Obj* self, int a, int b, int c) { self->a = a; self->b = b; self->c = c; }