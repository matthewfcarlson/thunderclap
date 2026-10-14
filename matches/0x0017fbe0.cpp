class Target {
  public:
    char pad[0x64];
    int mField;
    unsigned char Set(int value);
};

unsigned char Target::Set(int value) {
    mField = value;
    return 1;
}
