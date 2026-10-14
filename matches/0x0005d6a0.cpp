class A_5d6a0 {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char A_5d6a0::Set(int value) {
    mValue = value;
    return 1;
}
