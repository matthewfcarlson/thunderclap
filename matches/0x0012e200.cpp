class X_12e200 {
  public:
    virtual void V0();
    char Set(int value);
    char pad[8];
    int m12;
    char pad2[4];
};
char X_12e200::Set(int value) {
    m12 = value;
    return 1;
}
