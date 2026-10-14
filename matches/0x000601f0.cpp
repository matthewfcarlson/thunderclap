class Sub_601f0 {
  public:
    void Call();
};
class Obj_601f0 {
    char pad[0x140];

  public:
    Obj_601f0* F();
    void G();
};
Obj_601f0* Obj_601f0::F() {
    ((Sub_601f0*)((char*)this + 0x140))->Call();
    G();
    return this;
}
