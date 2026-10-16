class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
void __cdecl FUN_000fe0c0(Obj** slot, Obj* value) {
    if (value)
        value->Add();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}