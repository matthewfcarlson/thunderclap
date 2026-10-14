class RefCounted {
  public:
    virtual void AddRef();
    virtual void Release();
};

extern RefCounted* gObj_2eccb0;

void __cdecl FUN_002eccb0() {
    gObj_2eccb0->Release();
    gObj_2eccb0 = 0;
}
