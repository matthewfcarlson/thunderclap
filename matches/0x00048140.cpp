class X_48140 {
  public:
    char pad[0x14];
    char mVal;
    char Fn(char a);
};

char X_48140::Fn(char a) {
    mVal = a;
    return 1;
}
