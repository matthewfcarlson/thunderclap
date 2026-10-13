class Obj {
  public:
    char pad[0x20];
    int value;
    unsigned char Set(int x);
};

unsigned char Obj::Set(int x) {
    value = x;
    return 1;
}
