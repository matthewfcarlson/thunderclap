class Target {
  public:
    char pad[0x10];
    int mArg;
    char Fn(int x);
};
char Target::Fn(int x) {
    mArg = x;
    return 1;
}
