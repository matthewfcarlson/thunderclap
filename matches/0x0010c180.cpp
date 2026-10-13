class A {
  public:
    char Pad[12];
    int mVal;
    char Fn(int x);
};
char A::Fn(int x) {
    mVal = x;
    return 1;
}
