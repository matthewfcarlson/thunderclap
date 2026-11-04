class Base_68330 {
  public:
    char pad[0x14];
};

class Target_68330 : public Base_68330 {
  public:
    int mField;
    char SetDistance_00068330(int);
};

char Target_68330::SetDistance_00068330(int x) {
    mField = x;
    return 1;
}
