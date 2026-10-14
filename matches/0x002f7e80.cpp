class Ref_2f7e80 {
  public:
    virtual void Release(int);
};
class Owner_2f7e80 {
    char pad[8];
    Ref_2f7e80* mRef;

  public:
    void Clear();
};
void Owner_2f7e80::Clear() {
    if (mRef) {
        mRef->Release(1);
        mRef = 0;
    }
}