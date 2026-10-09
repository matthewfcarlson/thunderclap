class Obj {
    char pad[0x494];
    int value;

  public:
    unsigned char Set(int x);
};
unsigned char Obj::Set(int x) {
    value = x;
    return 1;
}