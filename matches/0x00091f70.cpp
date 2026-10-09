// Same code shape as 0x00086290 (propagated; names are from that function)
class Obj {
  public:
    char pad[0x24];
    int mValue;
    int GetValue();
};

int Obj::GetValue() {
    return mValue;
}