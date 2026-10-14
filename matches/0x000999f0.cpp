struct Obj_999f0 {
    void G();
};
class T_999f0 {
  public:
    char pad[0xc4];
    Obj_999f0* p;
    void Target();
};
void T_999f0::Target() {
    ((Obj_999f0*)((char*)p + 0x250))->G();
}
