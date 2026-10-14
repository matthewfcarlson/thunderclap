struct Part_24130 {
    char x[8];
    void F();
};
struct Obj_24130 {
    char pad[0x40];
    Part_24130 a;
    Part_24130 b;
    Obj_24130* Target();
};
Obj_24130* Obj_24130::Target() {
    a.F();
    b.F();
    return this;
}
