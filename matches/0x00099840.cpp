class Thing {
  public:
    char pad[0xc4];
    struct Inner* inner;
    void Set(int v);
};
struct Inner {
    char pad[0x2c4];
    int value;
};
void Thing::Set(int v) {
    inner->value = v;
}