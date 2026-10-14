typedef float F_1c61e0;
struct O_1c61e0 {
    void Fill(F_1c61e0*, int, int, int);
};
struct C_1c61e0 {
    char pad[0x284];
    O_1c61e0* m;
    F_1c61e0 Run();
};
F_1c61e0 C_1c61e0::Run() {
    F_1c61e0 x;
    m->Fill(&x, 1, 4, 1);
    return x;
}