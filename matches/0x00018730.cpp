class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
void f(Obj** slot, Obj* value) {
    if (value)
        value->Add();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}