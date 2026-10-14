class Obj_1db9e0 {
  public:
    char pad[0x10];
    int value;
    int Get() { return value; }
};

void Target() {
    Obj_1db9e0 o;
    o.Get();
}
