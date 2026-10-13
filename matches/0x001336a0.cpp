class O {
  public:
    char pad[0x10];
    int mField;
    bool Fn(int a);
};

bool O::Fn(int a) {
    mField = a;
    return true;
}
