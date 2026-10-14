class Obj {
  public:
    char pad[0xc];
    int mValue;
    char Set(int v);
};
char Obj::Set(int v) {
    mValue = v;
    return 1;
}