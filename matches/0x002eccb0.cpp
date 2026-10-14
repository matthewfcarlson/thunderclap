class RefCounted {
  public:
    virtual void AddRef();
    virtual void Release();
};

extern RefCounted* gObj;

void __cdecl FUN_002eccb0() {
    gObj->Release();
    gObj = 0;
}
