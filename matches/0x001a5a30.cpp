class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
void Set(Ref** slot, Ref* value) {
    if (value)
        value->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}