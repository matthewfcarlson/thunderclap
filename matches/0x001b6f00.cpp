class Obj {
    char pad[9];

  public:
    char Fn();
};
char Obj::Fn() {
    return pad[9];
}