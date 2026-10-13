class Obj {
  public:
    char pad[0xc];
    char m;
    char Set(char v);
};

char Obj::Set(char v) {
    m = v;
    return 1;
}