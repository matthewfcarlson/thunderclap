class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
void FUN_000b0000(Obj** slot, Obj* value) {
    if (value)
        value->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}