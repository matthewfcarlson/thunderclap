class Obj {
  public:
    char pad[0x14];
    int mValue;
    char Set(int v);
};
char Obj::Set(int v) {
    mValue = v;
    return 1;
}