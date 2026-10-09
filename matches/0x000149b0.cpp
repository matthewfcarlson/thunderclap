struct Obj;
struct Manager { void* Find(int); };
struct Root { char pad[0x44]; Manager* mgr; };
extern Root* gRoot;
struct Obj { void Apply(int, int); };

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
    Obj* o = (Obj*)gRoot->mgr->Find(x);
    if (o) o->Apply(mValue, 0);
}
