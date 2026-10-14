class Base_68330 {
  public:
    char pad[0x14];
};

class Target_68330 : public Base_68330 {
  public:
    int mField;
    char Set(int);
};

char Target_68330::Set(int x) {
    mField = x;
    return 1;
}
