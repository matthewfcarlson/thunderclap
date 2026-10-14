class A_d6f80 {
  public:
    char pad[8];
    char* p;
    void Set(unsigned char b);
};
void A_d6f80::Set(unsigned char b) {
    p[4] = (char)b;
}
