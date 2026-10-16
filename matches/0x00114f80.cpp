class Obj {
    char pad[0x1c];
    unsigned char value;

  public:
    unsigned char Set(unsigned char x);
};
unsigned char Obj::Set(unsigned char x) {
    value = x;
    return 1;
}