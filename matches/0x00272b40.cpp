class C {
    char pad[0x5c];
    unsigned char value;

  public:
    void Set(unsigned char x);
};
void C::Set(unsigned char x) {
    value = x;
}