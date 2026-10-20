// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// FEThingsBase::vfunc_33 @ 0x000e7700
class Thing_e7700 {
  public:
    void* FUN_000f7240(unsigned __int64 id);
};
class Other_e7700 {
  public:
    void FUN_000f8500(void* a, Thing_e7700* b, int c);
    void FUN_000f7a10(void* a, int b);
};
class Source_e7700 {
  public:
    virtual void v0();
    virtual unsigned __int64 GetId();
    char pad04[0xc];
    void* child;
};
class FEThingsBase {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32();
    virtual char FUN_000e7700(Source_e7700* s, Other_e7700* o);
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43();
    virtual Thing_e7700* Lookup();
};
char FEThingsBase::FUN_000e7700(Source_e7700* s, Other_e7700* o) {
    if (s->GetId() == 2) {
        void* child = s->child;
        o->FUN_000f8500(child, Lookup(), 1);
        return 1;
    }
    unsigned __int64 id = s->GetId();
    o->FUN_000f7a10(Lookup()->FUN_000f7240(id), 0);
    return 1;
}
