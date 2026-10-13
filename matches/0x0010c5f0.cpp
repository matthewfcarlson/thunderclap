class Obj {
  public:
    char Pad[0x20];
    int value;
    char Set(int v);
};

char Obj::Set(int v) {
    value = v;
    return 1;
}
