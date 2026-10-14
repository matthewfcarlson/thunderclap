class O {
  public:
    char F(float x);
    char pad[0x3c];
};

char O::F(float x) {
    *(float*)((char*)this + 0x3c) = x * 0.017453292f;
    return 1;
}
