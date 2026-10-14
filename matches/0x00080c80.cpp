class Obj_80c80 {
  public:
    char pad[0x28];
    unsigned int flags;
    void Set(char value);
};
void Obj_80c80::Set(char value) {
    if (value)
        flags |= 0x100;
    else
        flags &= 0xfffffeff;
}