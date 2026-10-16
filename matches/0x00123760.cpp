class X {
    char pad[16];
    float angle;

  public:
    char Set(float x);
};
char X::Set(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}