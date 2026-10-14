class X {
  public:
    char pad[0x2c];
    float value;
    unsigned char Set(float angle);
};

unsigned char X::Set(float angle) {
    value = angle * 0.017453292f;
    return 1;
}
