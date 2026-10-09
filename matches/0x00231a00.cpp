struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual int Test(int, int); int a[3]; int type; Item* Next(); int target(int); };
int Item::target(int param) {
    Item* p = Next();
    while (p) {
        if (p->type != 2) {
            int r = p->Test(param, 0);
            if (r) return r;
        }
        p = p->Next();
    }
    return 0;
}