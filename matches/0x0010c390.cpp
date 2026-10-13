class Obj {
  public:
    char pad[0xd];
    char v;
    char Set(unsigned char x);
};

char Obj::Set(unsigned char x) {
    v = x;
    return 1;
}
