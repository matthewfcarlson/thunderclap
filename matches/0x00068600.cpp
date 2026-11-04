class Obj_68600 {
  public:
    char pad[0x10];
    int m10;
    bool SetTimeEnd_00068600(int x);
};
bool Obj_68600::SetTimeEnd_00068600(int x) {
    m10 = x;
    return true;
}
