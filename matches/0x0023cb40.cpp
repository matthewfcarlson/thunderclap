class Obj {
  public:
    char pad[12];
    unsigned char value;
    char Set(unsigned char b);
};

char Obj::Set(unsigned char b) {
    value = b;
    return 1;
}