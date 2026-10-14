class Obj {
  public:
    char pad[0x588];
    unsigned char mValue;
    void Set(unsigned char value);
};

void Obj::Set(unsigned char value) {
    mValue = value;
}
