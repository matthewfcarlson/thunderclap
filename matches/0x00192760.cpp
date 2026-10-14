class Target_192760 {
  public:
    char pad[0x44];
    int m44;
    bool Set(int value);
};
bool Target_192760::Set(int value) {
    m44 = value;
    return true;
}
