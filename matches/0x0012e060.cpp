class Target {
  public:
    char pad[0x10];
    int mValue;
    char mFlag;
    char Set(int value);
};

char Target::Set(int value) {
    mValue = value;
    return 1;
}
