class Obj {
    char pad[0x28];
    unsigned int flags;

  public:
    void Set(char value);
};
void Obj::Set(char value) {
    if (value)
        flags |= 2;
    else
        flags &= 0xfffffffd;
}