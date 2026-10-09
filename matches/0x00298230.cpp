struct CompositeDrawable {
    void* vf;
    char pad[0x3c];
    int a, b, c, d, e;
    void Init();
    CompositeDrawable* Run();
};
CompositeDrawable* CompositeDrawable::Run() {
    Init();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    vf = (void*)0x42d484;
    return this;
}