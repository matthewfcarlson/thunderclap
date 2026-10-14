class Obj_60400 {
  public:
    char pad[0xc8];
    bool Set(char c);
};
bool Obj_60400::Set(char c) {
    pad[0xc8] = c;
    return true;
}
