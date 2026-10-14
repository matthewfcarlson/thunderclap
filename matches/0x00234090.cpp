class Ref_234090 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_234090 {
  public:
    Ref_234090* mRef;
    bool Clear(Ref_234090*);
};
bool Owner_234090::Clear(Ref_234090* unused) {
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    return true;
}