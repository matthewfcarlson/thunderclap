// Same code shape as 0x00086290 (propagated; names are from that function)
class Obj_91f70 {
  public:
    char pad[0x24];
    int mValue;
    int GetValue();
};

int Obj_91f70::GetValue() {
    return mValue;
}