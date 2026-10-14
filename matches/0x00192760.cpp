class Target {
  public:
    char pad[0x44];
    int m44;
    bool Set(int value);
};
bool Target::Set(int value) {
    m44 = value;
    return true;
}
