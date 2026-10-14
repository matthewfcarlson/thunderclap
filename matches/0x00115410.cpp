class X {
  public:
    char flag;
    char pad[19];
    float radians;
    char Set(float degrees);
};

char X::Set(float degrees) {
    radians = degrees * 0.017453292f;
    return 1;
}
