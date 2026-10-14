class A {
  public:
    char pad[0x30];
    float m;
    unsigned char Fn(float x);
};

unsigned char A::Fn(float x) {
    m = x * 0.017453292519943295f;
    return 1;
}