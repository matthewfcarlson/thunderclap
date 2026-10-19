class Target_1d4df0 {
    char pad[0xa8];

  public:
    int value;
    int Check();
};
int Target_1d4df0::Check() {
    return value != 0;
}