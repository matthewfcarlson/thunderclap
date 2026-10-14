struct Sub_99ca0 {
    char pad[0x1f0];
    int value;
};
class Obj_99ca0 {
  public:
    char pad[0xc4];
    Sub_99ca0* ptr;
    void Set(int x);
};
void Obj_99ca0::Set(int x) {
    ptr->value = x;
}
