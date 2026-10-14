class X_114fe0 {
  public:
    char pad[0xe];
    bool Set(char c);
};

bool X_114fe0::Set(char c) {
    pad[0xe] = c;
    return true;
}
