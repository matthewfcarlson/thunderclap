class Obj {
    char pad[12];
    unsigned char value;

  public:
    unsigned char Set(unsigned char v);
};
unsigned char Obj::Set(unsigned char v) {
    value = v;
    return 1;
}