class Obj {
  public:
    char pad[0xc];
    char mValue;
    unsigned char Fn(char value);
};

unsigned char Obj::Fn(char value) {
    mValue = value;
    return 1;
}
