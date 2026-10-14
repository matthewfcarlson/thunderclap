class C {
  public:
    char pad[0x54];
    float m;
    char Set(float x);
};

char C::Set(float x) {
    m = x * 0.0174532925f;
    return 1;
}
