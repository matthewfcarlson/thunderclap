class Item { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual int Get(int); };
struct Entry { Item* p; char pad[12]; };
extern Entry gItems[4];
extern int (__cdecl *gCallback)(int,int,int,int);
extern int gContext;
int FUN_00266e00(int a, int b) {
    int r = gItems[a].p->Get(b);
    if (!r && gCallback) gCallback(gContext,a,b,1);
    return r;
}