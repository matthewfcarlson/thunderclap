class Obj {
  public:
    char m[0x2b];
    char SetB(unsigned char value);
};

char Obj::SetB(unsigned char value) {
    m[0x2b] = value;
    return 1;
}
