class Target_b07e0 {
    char pad[0x49c];
    unsigned int value;

  public:
    bool Set(unsigned int);
};
bool Target_b07e0::Set(unsigned int x) {
    value = x;
    return true;
}