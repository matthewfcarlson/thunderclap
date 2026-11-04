class Obj_68b50 {
  public:
    char pad[0x10];
    int value;
    bool SetTimeEnd_00068b50(int x);
};

bool Obj_68b50::SetTimeEnd_00068b50(int x) {
    value = x;
    return true;
}
