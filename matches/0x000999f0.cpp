struct Obj_999f0 {
    void G(int, int);
};
class T_999f0 {
  public:
    char pad[0xc4];
    Obj_999f0* p;
    void Target(int, int);
};
void T_999f0::Target(int a0, int a1) {
    ((Obj_999f0*)((char*)p + 0x250))->G(a0, a1);
}
