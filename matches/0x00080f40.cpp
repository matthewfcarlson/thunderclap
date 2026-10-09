class C {
    char pad[0x28];
    unsigned int flags;

  public:
    void F(bool b);
};
void C::F(bool b) {
    if (b)
        flags |= 0x10;
    else
        flags &= 0xffffffef;
}