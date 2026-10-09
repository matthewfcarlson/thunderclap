typedef float F;
struct O {
    void Fill(F*, int, int, int);
};
struct C {
    char pad[0x284];
    O* m;
    F Run();
};
F C::Run() {
    F x;
    m->Fill(&x, 1, 4, 1);
    return x;
}