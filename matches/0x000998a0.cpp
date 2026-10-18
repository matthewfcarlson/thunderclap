class Sub_998a0 {
  public:
    void Fn(int, int);
};
class Obj_998a0 {
  public:
    void Fn(int, int);
    char pad[0xc4];
    Sub_998a0* mSub;
};
void Obj_998a0::Fn(int a0, int a1) {
    ((char*)mSub + 0x1a8);
    ((Sub_998a0*)((char*)mSub + 0x1a8))->Fn(a0, a1);
}
