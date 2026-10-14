class Obj_cae80 {
  public:
    char pad[0x88];
    void* mObj;
    void Fn(float f);
};
class Sub_cae80 {
  public:
    void Fn(float f);
};
void Obj_cae80::Fn(float f) {
    if (mObj)
        ((Sub_cae80*)mObj)->Fn(f);
}
