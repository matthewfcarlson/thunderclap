class Obj {
  public:
    char pad[0x14];
    float mVal;
    float GetValue();
};

float Obj::GetValue() {
    return mVal;
}
