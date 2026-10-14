class Obj_10c130 {
  public:
    char pad[12];
    char value;
    bool Set(char c);
};

bool Obj_10c130::Set(char c) {
    value = c;
    return true;
}
