class A {
  public:
    char pad[12];
    char mField;
    char Set(char p);
};
char A::Set(char p) {
    mField = p;
    return 1;
}
