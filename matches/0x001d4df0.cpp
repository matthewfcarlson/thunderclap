class Target_1d4df0 {
    char pad[0xa8];

  public:
    int value;
    bool Check();
};
bool Target_1d4df0::Check() {
    return value != 0;
}