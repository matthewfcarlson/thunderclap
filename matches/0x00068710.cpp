class Target {
  public:
    char pad[0x88];
    int value;
    bool Fn(int x);
};
bool Target::Fn(int x) {
    value = x;
    return true;
}