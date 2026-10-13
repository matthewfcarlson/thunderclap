class Obj {
  public:
    char pad[0x48];
    int mValue;
    char Fn(int v);
};

char Obj::Fn(int v) {
    mValue = v;
    return 1;
}
