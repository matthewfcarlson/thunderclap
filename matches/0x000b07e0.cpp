class Target {
    char pad[0x49c];
    unsigned int value;

  public:
    bool Set(unsigned int);
};
bool Target::Set(unsigned int x) {
    value = x;
    return true;
}