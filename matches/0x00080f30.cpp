class Thing_80f30 {
    char pad[0xcc];

  public:
    int value;
    void Set(int);
};
void Thing_80f30::Set(int x) {
    value = x;
}