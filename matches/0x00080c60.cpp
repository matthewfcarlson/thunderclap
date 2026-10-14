class Obj_80c60 {
    char pad[0x28];
    unsigned int flags;

  public:
    void Set(char value);
};
void Obj_80c60::Set(char value) {
    if (value)
        flags |= 2;
    else
        flags &= 0xfffffffd;
}