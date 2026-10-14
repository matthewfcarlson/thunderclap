class Target_47b10 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Target_47b10::Set(int v) {
    value = v;
    return true;
}
