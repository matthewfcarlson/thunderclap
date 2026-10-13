class Obj {
  public:
    int pad[3];
    int mValue;
    unsigned char Set(int v);
};
unsigned char Obj::Set(int v) {
    mValue = v;
    return 1;
}