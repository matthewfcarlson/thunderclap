class Sub {
  public:
    void Fn();
};
class Obj {
  public:
    void Fn();
    char pad[0xc4];
    Sub* mSub;
};
void Obj::Fn() {
    ((char*)mSub + 0x1a8);
    ((Sub*)((char*)mSub + 0x1a8))->Fn();
}
