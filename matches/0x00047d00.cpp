class V {
  public:
    char f(float x);
    char pad[0x10];
    float v;
};

char V::f(float x) {
    v = x * 0.017453292f;
    return 1;
}
