class A {
  public:
    char pad[8];
    char* p;
    void Set(unsigned char b);
};
void A::Set(unsigned char b) {
    p[4] = (char)b;
}
