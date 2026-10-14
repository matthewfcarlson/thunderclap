class O_192700 {
  public:
    char F(float x);
    char pad[0x3c];
};

char O_192700::F(float x) {
    *(float*)((char*)this + 0x3c) = x * 0.017453292f;
    return 1;
}
