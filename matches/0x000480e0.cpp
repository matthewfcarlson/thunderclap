class Target_480e0 {
  public:
    char pad[12];
    int value;
    bool Set(int x);
};

bool Target_480e0::Set(int x) {
    value = x;
    return true;
}
