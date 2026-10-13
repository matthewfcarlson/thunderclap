class Target {
  public:
    char Set(int value);
    char pad[0xc];
    int mValue;
};

char Target::Set(int value) {
    mValue = value;
    return 1;
}
