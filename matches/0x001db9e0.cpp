class Obj {
  public:
    char pad[0x10];
    int value;
    int Get() { return value; }
};

void Target() {
    Obj o;
    o.Get();
}
