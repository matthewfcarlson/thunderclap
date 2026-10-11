class RefObj {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern "C" int __cdecl GetSingleton();
extern char g_vftable[];
class ActionBase {
  public:
    void* vptr;
    ActionBase();
};
class TokenSupressAction : public ActionBase {
  public:
    char pad[0x18];
    int m1c;
    RefObj* m20;
    int m24;
    TokenSupressAction(int a, RefObj* b);
};
TokenSupressAction::TokenSupressAction(int a, RefObj* b) {
    vptr = g_vftable;
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
