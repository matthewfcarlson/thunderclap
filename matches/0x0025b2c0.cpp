struct E_25b2c0 {
    char x[12];
    void Init();
};
struct A_25b2c0 {
    char pad[0x10];
    E_25b2c0 a;
    E_25b2c0 b;
    E_25b2c0 c[10];
};
A_25b2c0* __fastcall Target(A_25b2c0* self) {
    self->a.Init();
    self->b.Init();
    int i = 10;
    do {
        self->c[10 - i].Init();
        --i;
    } while (i != 0);
    return self;
}