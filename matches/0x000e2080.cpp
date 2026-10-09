class SingleLayout {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int vfunc_19();
    virtual void v20(); virtual void v21(); virtual void v22();
    char pad[0x40];
    struct Obj *mObj;
};
struct Obj { char pad[0x141]; char a; char b; };
int SingleLayout::vfunc_19() {
    Obj *p = mObj;
    if (p && p->a && p->b) return 1;
    return 0;
}