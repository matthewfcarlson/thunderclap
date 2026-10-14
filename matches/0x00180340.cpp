class Obj {
  public:
    char pad[12];
    int mValue;
    char Fn(int x);
};
char Obj::Fn(int x) {
    mValue = x;
    return 1;
}
