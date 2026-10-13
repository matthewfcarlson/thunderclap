class Obj {
  public:
    char pad[0x4c];
    int mVal;
    char Fn(int v) throw();
};
char Obj::Fn(int v) throw() {
    mVal = v;
    return 1;
}
