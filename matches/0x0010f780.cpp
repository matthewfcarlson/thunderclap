class RefObj_10f780 {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern "C" int __cdecl GetSingleton();
extern char g_vftable_10f780[];
class ActionBase_10f780 {
  public:
    void* vptr;
    ActionBase_10f780();
};
class TokenSupressAction : public ActionBase_10f780 {
  public:
    char pad[0x18];
    int m1c;
    RefObj_10f780* m20;
    int m24;
    TokenSupressAction(int a, RefObj_10f780* b);
};
TokenSupressAction::TokenSupressAction(int a, RefObj_10f780* b) {
    vptr = g_vftable_10f780;
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m1c = a;
    if (b != 0)
        b->AddRef();
    if (m20 != 0)
        m20->Release();
    m20 = b;
    int mgr = GetSingleton();
    m24 = *(int*)(mgr + 0x368);
}
