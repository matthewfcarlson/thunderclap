class C {
    char pad[0x440];

  public:
    void F(int i, unsigned char v);
};
void C::F(int i, unsigned char v) {
    if (i >= 0 && i < 6)
        *(unsigned char*)((char*)this + i + 0x440) = v;
}