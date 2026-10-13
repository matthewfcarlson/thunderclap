class A {
  public:
    char p[0x14];
    char value;
    char Set(char arg);
};
char A::Set(char arg) {
    value = arg;
    return 1;
}