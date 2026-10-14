class Target_68760 {
  public:
    char pad[0x9c];
    int value;
    bool Set(int v);
};
bool Target_68760::Set(int v) {
    value = v;
    return true;
}