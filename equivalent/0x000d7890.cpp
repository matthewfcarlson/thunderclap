// STATUS: equivalent (tools/equiv.py level 3: 169 inputs, branch coverage 10/10)
// FUN_000d7890 @ 0x000d7890
class Handler_d7890;
struct Item_d7890 {
    virtual void v0();
    virtual void v1();
};
struct Cursor_d7890 {
    bool FUN_000f9ef0();
    void FUN_000f9f30();
    bool FUN_000f9e50();
    Item_d7890* FUN_000fb110();
    void FUN_000fa0a0();
    void FUN_000f9fb0();
};
struct Dispatcher_d7890 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual bool v34(Cursor_d7890* c, Item_d7890* it, int zero);
    virtual bool v35(Cursor_d7890* c, int flag, Handler_d7890* h, Item_d7890* it);
    virtual bool v36(Cursor_d7890* c, int flag, Handler_d7890* h, Item_d7890* it);
};

class Handler_d7890 {
public:
    bool FUN_000d7890(Cursor_d7890* c, Dispatcher_d7890* d, int flag);
};

bool Handler_d7890::FUN_000d7890(Cursor_d7890* c, Dispatcher_d7890* d, int flag)
{
    if (c->FUN_000f9ef0()) {
        c->FUN_000f9f30();
        while (c->FUN_000f9e50()) {
            Item_d7890* it = c->FUN_000fb110();
            it->v1();
            if (d->v35(c, flag, this, it))
                continue;
            if (d->v36(c, flag, this, it))
                continue;
            if (d->v34(c, it, 0))
                continue;
            c->FUN_000fa0a0();
            break;
        }
        c->FUN_000f9fb0();
    }
    return true;
}
