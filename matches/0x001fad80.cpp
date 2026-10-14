// Same code shape as 0x000b3ef0 (propagated; names are from that function)
class Ref_1fad80 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_1fad80 {
  public:
    char pad[4];
    Ref_1fad80* p;
    void Clear();
};
void Owner_1fad80::Clear() {
    if (p) {
        p->Release();
        p = 0;
    }
}