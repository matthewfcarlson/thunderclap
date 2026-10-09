struct E { char x[12]; void Init(); };
struct A { char pad[0x10]; E a; E b; E c[10]; };
A* __fastcall Target(A* self) {
    self->a.Init();
    self->b.Init();
    int i = 10;
    do { self->c[10-i].Init(); --i; } while (i != 0);
    return self;
}