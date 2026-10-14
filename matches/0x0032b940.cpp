class A {
  public:
    char pad[0x88];
    char b88;
    void Set(void* p);
};
void A::Set(void* p) {
    b88 = (p != 0);
}