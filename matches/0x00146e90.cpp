class T_146e90 {
  public:
    char pad[0x18];
    float v;
    unsigned char f(float x);
};

unsigned char T_146e90::f(float x) {
    v = x * 0.017453293f;
    return 1;
}
