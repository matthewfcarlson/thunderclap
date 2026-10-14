class Obj_1a2580 {
  public:
    char pad[0x99];
    char m99;
    bool Set(char c);
};
bool Obj_1a2580::Set(char c) {
    m99 = c;
    return true;
}
