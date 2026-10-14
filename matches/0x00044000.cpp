class Obj_44000 {
  public:
    char pad[0x360];
    int value;
    void Fn(int x);
};
void Obj_44000::Fn(int x) {
    value = x;
}