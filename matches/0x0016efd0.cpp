class Thing {
  public:
    char pad[0x44];
    int mValue;
    bool Set(int x);
};

bool Thing::Set(int x) {
    mValue = x;
    return true;
}