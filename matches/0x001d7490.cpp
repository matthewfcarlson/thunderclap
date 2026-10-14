class Ref_1d7490 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Owner_1d7490 {
  public:
    char pad[0x11c];
    Ref_1d7490* value;
    void Set(Ref_1d7490* p);
};
void Owner_1d7490::Set(Ref_1d7490* p) {
    if (p)
        p->AddRef();
    if (value)
        value->Release();
    value = p;
}