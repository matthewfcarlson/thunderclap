struct Obj_149b0;
struct Manager_149b0 {
    void* Find(int);
};
struct Root_149b0 {
    char pad[0x44];
    Manager_149b0* mgr;
};
extern Root_149b0* gRoot_149b0;
struct Obj_149b0 {
    void Apply(int, int);
};

struct CStunAnimationAction {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x1c - 4];
    void* mAnim;
    char pad2[4];
    int mValue;
};

void CStunAnimationAction::v4() {
    int x = *(int*)((char*)mAnim + 8);
    Obj_149b0* o = (Obj_149b0*)gRoot_149b0->mgr->Find(x);
    if (o)
        o->Apply(mValue, 0);
}
