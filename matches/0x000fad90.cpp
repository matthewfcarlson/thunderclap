struct Base {
    int a;
    int b;
    int c;
};
struct Obj {
    char pad0[8];
    Base* mRoot;
    Base* mCur;
    char pad10[4];
    unsigned char mDone;
};
extern int __cdecl GetThing(Base*, int, void*, void*, int);
extern int desc1;
extern int desc2;
int __fastcall Target(Obj* self) {
    Base* p = self->mRoot;
    if (!p)
        return 0;
    Base* q;
    if (self->mDone == 1)
        q = 0;
    else {
        q = self->mCur;
        if (q == 0)
            q = (Base*)*(int*)((char*)p + 4);
        else
            q = (Base*)*(int*)((char*)q + 4);
        if (q == 0 || *(int*)((char*)q + 8) >= 2) {
        } else
            q = 0;
    }
    self->mCur = q;
    if (q == 0)
        self->mDone = 1;
    return *(int*)((char*)GetThing(self->mCur, 0, &desc1, &desc2, 0) + 16);
}