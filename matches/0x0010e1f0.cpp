struct Pair {
    int a, b;
    void Set(const Pair*);
};
struct Actor {
    char pad[0x1b98];
    Pair p;
    int count;
};
struct Source {
    char pad[0x18];
    Pair p;
};
struct Handle {
    Actor* Get();
};
struct Thing {
    Handle* Get();
};
namespace hulkfight {
namespace ai {
class AIHistorySetAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad[0x18];
    Source* src;
    Thing* thing;
};
} // namespace ai
} // namespace hulkfight
void hulkfight::ai::AIHistorySetAction::vfunc_4() {
    if (thing) {
        Actor* a = thing->Get()->Get();
        Pair* p = &src->p;
        Pair* q = &a->p;
        if (q->a == p->a && q->b == p->b)
            ++a->count;
        else {
            q->Set(p);
            a->count = 1;
        }
    }
}