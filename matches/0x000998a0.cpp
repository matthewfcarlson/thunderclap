class Sub_998a0 {
  public:
    void Fn();
};
class Obj_998a0 {
  public:
    void Fn();
    char pad[0xc4];
    Sub_998a0* mSub;
};
void Obj_998a0::Fn() {
    ((char*)mSub + 0x1a8);
    ((Sub_998a0*)((char*)mSub + 0x1a8))->Fn();
}
