class Ref_b3ef0 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_b3ef0 {
  public:
    char pad[4];
    Ref_b3ef0* p;
    void Clear();
};
void Owner_b3ef0::Clear() {
    if (p) {
        p->Release();
        p = 0;
    }
}