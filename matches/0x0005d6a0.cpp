class A {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char A::Set(int value) {
    mValue = value;
    return 1;
}
