struct Sub {
    char pad[0x1f0];
    int value;
};
class Obj {
  public:
    char pad[0xc4];
    Sub* ptr;
    void Set(int x);
};
void Obj::Set(int x) {
    ptr->value = x;
}
