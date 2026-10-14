class C_18f030 {
  public:
    char pad[0x54];
    float m;
    char Set(float x);
};

char C_18f030::Set(float x) {
    m = x * 0.0174532925f;
    return 1;
}
