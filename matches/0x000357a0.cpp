class C {
    char pad[0x1b4];

  public:
    volatile float a;
    float b, c;
    void Add(float* p);
};
void C::Add(float* p) {
    a = a + p[0];
    b = p[1] + b;
    c = p[2] + c;
}