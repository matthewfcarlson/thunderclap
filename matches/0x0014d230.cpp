class A {
  public:
    char pad[12];
    int mField;
    char Set(int value);
};

char A::Set(int value) {
    mField = value;
    return 1;
}
