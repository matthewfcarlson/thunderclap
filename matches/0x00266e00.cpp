class Item_266e00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Get(int);
};
struct Entry_266e00 {
    Item_266e00* p;
    char pad[12];
};
extern Entry_266e00 gItems_266e00[4];
extern int(__cdecl* gCallback_266e00)(int, int, int, int);
extern int gContext;
int FUN_00266e00(int a, int b) {
    int r = gItems_266e00[a].p->Get(b);
    if (!r && gCallback_266e00)
        gCallback_266e00(gContext, a, b, 1);
    return r;
}