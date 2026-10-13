class Obj {
  public:
    char pad[12];
    unsigned char value;
    unsigned char Set(unsigned char x);
};
unsigned char Obj::Set(unsigned char x) {
    value = x;
    return 1;
}