class Obj_28fe30 {
  public:
    char pad[8];
    int value;
    void reset();
    Obj_28fe30* target();
};
Obj_28fe30* Obj_28fe30::target() {
    reset();
    value = 0;
    return this;
}