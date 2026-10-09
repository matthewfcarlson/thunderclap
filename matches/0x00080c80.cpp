class Obj {
  public:
    char pad[0x28];
    unsigned int flags;
    void Set(char value);
};
void Obj::Set(char value) {
    if (value)
        flags |= 0x100;
    else
        flags &= 0xfffffeff;
}