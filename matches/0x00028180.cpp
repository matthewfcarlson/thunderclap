struct Part {
    void Clear();
};
struct Item {
    char a[0xb4];
    Part p;
    char b[0x27];
    Part q;
    void Done();
    Part* GetP() { return this ? &p : 0; }
    Part* GetQ() { return this ? &q : 0; }
};
struct Owner {
  public:
    Item* Find(__int64);
    char Run(int);
};
extern "C" __int64 __cdecl Lookup(int, int, int);
char Owner::Run(int x) {
    __int64 id = Lookup(x, 0, 0);
    Item* i = Find(id);
    if (!i)
        return 0;
    Part* q = i->GetQ();
    if (q)
        q->Clear();
    Part* p = i->GetP();
    if (p)
        p->Clear();
    i->Done();
    return 1;
}