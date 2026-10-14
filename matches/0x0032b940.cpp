class A_32b940 {
  public:
    char pad[0x88];
    char b88;
    void Set(void* p);
};
void A_32b940::Set(void* p) {
    b88 = (p != 0);
}