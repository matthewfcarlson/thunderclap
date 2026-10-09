class Obj {
  public:
    char pad[8];
    int value;
    void reset();
    Obj* target();
};
Obj* Obj::target() {
    reset();
    value = 0;
    return this;
}