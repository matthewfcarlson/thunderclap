extern const float gConstant;
class Sub {
  public:
    float Fn();
};
class Obj {
  public:
    char pad[0xb8];
    Sub* mSub;
    float Fn();
};
float Obj::Fn() {
    if (mSub)
        return mSub->Fn();
    return gConstant;
}
