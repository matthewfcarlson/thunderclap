class Target_68710 {
  public:
    char pad[0x88];
    int value;
    bool Fn(int x);
};
bool Target_68710::Fn(int x) {
    value = x;
    return true;
}