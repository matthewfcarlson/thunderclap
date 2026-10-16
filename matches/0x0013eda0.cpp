class X {
  public:
    char pad[0x28];
    float angle;
    char Set(float x);
};
char X::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}