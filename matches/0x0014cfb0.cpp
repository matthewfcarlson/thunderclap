class Target {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char Target::Set(int value) {
    mValue = value;
    return 1;
}
