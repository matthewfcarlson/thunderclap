class Obj {
  public:
    char pad[0xc4];
    struct Sub {
        char pad[0x260];
        int value;
    }* sub;
    void Set(int x);
};
void Obj::Set(int x) {
    sub->value = x;
}