class Target_14cfb0 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char Target_14cfb0::Set(int value) {
    mValue = value;
    return 1;
}
