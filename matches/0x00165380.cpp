class Obj {
  public:
    char pad[0xc];
    int mVal;
    char Fn(int x);
};
char Obj::Fn(int x) {
    mVal = x;
    return 1;
}
