class X_16fb50 {
  public:
    char pad[0x2c];
    float value;
    unsigned char Set(float angle);
};

unsigned char X_16fb50::Set(float angle) {
    value = angle * 0.017453292f;
    return 1;
}
