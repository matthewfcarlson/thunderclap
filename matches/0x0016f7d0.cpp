class Obj {
  public:
    char Pad[0x40];
    int mValue;
    char Set(int v);
};

char Obj::Set(int v) {
    mValue = v;
    return 1;
}
