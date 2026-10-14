class O_123530 {
  public:
    char m[0xc];
    float mValue;
    char Set(float v);
};
char O_123530::Set(float v) {
    mValue = v * 0.0174532925f;
    return 1;
}
