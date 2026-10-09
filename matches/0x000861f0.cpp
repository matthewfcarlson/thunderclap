class Obj;
class A {
  public:
    void F();
    void G(Obj*, int);
};
class Obj {
  public:
    char pad[4];
    int m4;
    char pad2[0x18];
    A* m20;
    void Target();
};
void Obj::Target() {
    m20->F();
    m20->G(this, m4);
}