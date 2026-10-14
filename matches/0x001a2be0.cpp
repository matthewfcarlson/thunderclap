class Obj {
  public:
    char pad[0x168];
    char m;
    char Set(unsigned char v);
};

char Obj::Set(unsigned char v) {
    m = v;
    return 1;
}
