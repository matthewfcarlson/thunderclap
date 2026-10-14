class Target_47e70 {
  public:
    char Set(int value);
    char pad[0xc];
    int mValue;
};

char Target_47e70::Set(int value) {
    mValue = value;
    return 1;
}
