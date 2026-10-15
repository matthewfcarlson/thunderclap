class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};

void __cdecl Set(Obj** slot, Obj* obj) {
    if (obj)
        obj->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = obj;
}
