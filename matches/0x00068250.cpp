class Obj {
  public:
    char pad[12];
    int mValue;
    unsigned char Set(int v);
};
unsigned char Obj::Set(int v) {
    mValue = v;
    return 1;
}
