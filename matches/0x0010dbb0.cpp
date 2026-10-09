extern void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern const int RTTI_Params;
extern const int RTTI_CFightParams;
struct Holder {
    char pad[0x14];
    Holder* next;
};
struct Sub {
    Holder* h;
    bool Valid();
};
struct Owner {
    char pad[0xb4];
    Sub sub;
};
struct Mid {
    Owner* GetOwner();
};
struct P {
    Mid* GetMid();
};
class AIFightNodeCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void*, P* p, void*);
    char pad[8];
    Holder* node;
};
bool AIFightNodeCondition::vfunc_6(void*, P* p, void*) {
    if (FUN_00344e74(p, 0, &RTTI_Params, &RTTI_CFightParams, 0)) {
        Owner* o = p->GetMid()->GetOwner();
        if (o) {
            Holder* n = node;
            if (n) {
                Sub* s = &o->sub;
                if (s) {
                    Holder* h = s->h;
                    if (h) {
                        if (s->Valid()) {
                            Holder* c = h->next;
                            while (c) {
                                if (c == n)
                                    return true;
                                c = c->next;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
