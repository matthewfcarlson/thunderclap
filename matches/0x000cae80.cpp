class Obj {
  public:
    char pad[0x88];
    void* mObj;
    void Fn(float f);
};
class Sub {
  public:
    void Fn(float f);
};
void Obj::Fn(float f) {
    if (mObj)
        ((Sub*)mObj)->Fn(f);
}
