class C_357a0 {
    char pad[0x1b4];

  public:
    volatile float a;
    float b, c;
    void Add(float* p);
};
void C_357a0::Add(float* p) {
    a = a + p[0];
    b = p[1] + b;
    c = p[2] + c;
}