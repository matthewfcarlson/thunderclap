class Obj_861f0;
class A_861f0 {
  public:
    void F();
    void G(Obj_861f0*, int);
};
class Obj_861f0 {
  public:
    char pad[4];
    int m4;
    char pad2[0x18];
    A_861f0* m20;
    void Target();
};
void Obj_861f0::Target() {
    m20->F();
    m20->G(this, m4);
}