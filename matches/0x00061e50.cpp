class Obj {
  public:
    char Pad[0xc];
    int mValue;
    char Set(int v);
};

char Obj::Set(int v) {
    mValue = v;
    return 1;
}
