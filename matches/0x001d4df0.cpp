class Target {
    char pad[0xa8];

  public:
    int value;
    bool Check();
};
bool Target::Check() {
    return value != 0;
}