class Target_12e060 {
  public:
    char pad[0x10];
    int mValue;
    char mFlag;
    char Set(int value);
};

char Target_12e060::Set(int value) {
    mValue = value;
    return 1;
}
