class X_115410 {
  public:
    char flag;
    char pad[19];
    float radians;
    char Set(float degrees);
};

char X_115410::Set(float degrees) {
    radians = degrees * 0.017453292f;
    return 1;
}
