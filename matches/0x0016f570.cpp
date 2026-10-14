class Obj {
  public:
    char pad[0x50];
    int value;
    char ret;
    char Set(int v);
};

char Obj::Set(int v) {
    value = v;
    return 1;
}