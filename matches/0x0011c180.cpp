class A_11c180 {
  public:
    char pad[0x50];
    int mValue;
    bool Set(int v) throw();
};

bool A_11c180::Set(int v) throw() {
    mValue = v;
    return true;
}