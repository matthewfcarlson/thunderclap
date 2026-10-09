class C {
    char pad[0x100];
    unsigned char value;

  public:
    void Set(unsigned char x);
};
void C::Set(unsigned char x) {
    value = x;
}