class Thing {
  public:
    char pad[0x44];
    int value;
    void Set(int x);
};

void Thing::Set(int x) {
    value = x;
}