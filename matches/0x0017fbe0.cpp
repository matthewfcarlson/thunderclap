class Target_17fbe0 {
  public:
    char pad[0x64];
    int mField;
    unsigned char Set(int value);
};

unsigned char Target_17fbe0::Set(int value) {
    mField = value;
    return 1;
}
