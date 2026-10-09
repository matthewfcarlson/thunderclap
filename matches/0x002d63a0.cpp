struct Sub { void Init(); char pad[0x114]; };
struct Base {
    Base();
    virtual void V1();
};
struct Emitter : Base {
    Emitter();
    virtual void V1();
    char pad[0xa8 - 4];
    Sub sub;
    int f1bc, f1c0, f1c4, f1c8, f1cc, f1d0, f1d4, f1d8;
};
Emitter::Emitter() {
    sub.Init();
    f1bc = 0; f1c0 = 0; f1c4 = 0; f1c8 = 0; f1cc = 0; f1d4 = 0; f1d8 = 0;
}
