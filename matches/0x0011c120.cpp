class Obj {
  public:
    char pad[0x48];
    unsigned char field;
    unsigned char Fn(unsigned char value);
};
unsigned char Obj::Fn(unsigned char value) {
    field = value;
    return 1;
}
