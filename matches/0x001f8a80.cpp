class Helper_1f8a80 {
  public:
    void Release(int);
};
class Owner_1f8a80 {
  public:
    char pad[0x20];
    volatile int member;
    Helper_1f8a80* GetHelper();
    void Set(int);
};
void Owner_1f8a80::Set(int value) {
    Helper_1f8a80* h = GetHelper();
    h->Release(member);
    member = value;
}