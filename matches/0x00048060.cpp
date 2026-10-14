class Target_48060 {
  public:
    char pad[12];
    int field;
    bool Set(int x);
};

bool Target_48060::Set(int x) {
    field = x;
    return true;
}