class Obj {
  public:
    char pad[0x30];
    int value;
    unsigned char Set(int x);
};
unsigned char Obj::Set(int x) {
    value = x;
    return 1;
}