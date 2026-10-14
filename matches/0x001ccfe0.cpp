class O {
  public:
    char pad[0x14a8];
    unsigned char m;
    void Set(unsigned char v);
};
void O::Set(unsigned char v) {
    m = v;
}
