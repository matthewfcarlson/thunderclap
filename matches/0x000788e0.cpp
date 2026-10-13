class Thing {
  public:
    char pad[0x3740];
    int mValue;
    void Set();
};
void Thing::Set() {
    mValue = 0;
}
