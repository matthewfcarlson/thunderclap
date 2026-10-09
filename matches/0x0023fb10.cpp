class C {
    char pad[8];
    unsigned short value;

  public:
    void Set(unsigned short x);
};
void C::Set(unsigned short x) {
    value = x;
}