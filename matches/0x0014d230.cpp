class A_14d230 {
  public:
    char pad[12];
    int mField;
    char Set(int value);
};

char A_14d230::Set(int value) {
    mField = value;
    return 1;
}
