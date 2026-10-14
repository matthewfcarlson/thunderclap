class Obj {
  public:
    char pad[0x1c8c];
    char value;
    void Set(unsigned char b);
};
void Obj::Set(unsigned char b) {
    value = b;
}
