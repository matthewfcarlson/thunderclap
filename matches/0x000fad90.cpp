struct Base_fad90 {
    int a;
    int b;
    int c;
};
struct Obj_fad90 {
    char pad0[8];
    Base_fad90* mRoot;
    Base_fad90* mCur;
    char pad10[4];
    unsigned char mDone;
};
extern int __cdecl GetThing(Base_fad90*, int, void*, void*, int);
extern int desc1_fad90;
extern int desc2_fad90;
int __fastcall Target(Obj_fad90* self) {
    Base_fad90* p = self->mRoot;
    if (!p)
        return 0;
    Base_fad90* q;
    if (self->mDone == 1)
        q = 0;
    else {
        q = self->mCur;
        if (q == 0)
            q = (Base_fad90*)*(int*)((char*)p + 4);
        else
            q = (Base_fad90*)*(int*)((char*)q + 4);
        if (q == 0 || *(int*)((char*)q + 8) >= 2) {
        } else
            q = 0;
    }
    self->mCur = q;
    if (q == 0)
        self->mDone = 1;
    return *(int*)((char*)GetThing(self->mCur, 0, &desc1_fad90, &desc2_fad90, 0) + 16);
}