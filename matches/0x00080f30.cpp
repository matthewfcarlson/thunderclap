class Thing {
    char pad[0xcc];

  public:
    int value;
    void Set(int);
};
void Thing::Set(int x) {
    value = x;
}