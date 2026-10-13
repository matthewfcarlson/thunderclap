class Base {
  public:
    char pad[0x14];
};

class Target : public Base {
  public:
    int mField;
    char Set(int);
};

char Target::Set(int x) {
    mField = x;
    return 1;
}
