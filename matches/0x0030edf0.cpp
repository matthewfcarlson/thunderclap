struct Block_30edf0 {
    int a[21];
    void Finish(int);
};
class Obj_30edf0 {
  public:
    char pad0[4];
    int value;
    char pad8[12];
    Block_30edf0 source;
    Block_30edf0 dest;
    int state;
};
extern int __fastcall clone(int);
extern void __fastcall notify(Obj_30edf0*);
Block_30edf0* __fastcall target(Obj_30edf0* p) {
    if (p->state == 2) {
        if (p->value) {
            p->dest = p->source;
            int x = clone(p->value);
            p->dest.Finish(x);
            notify(p);
        }
        p->state = 0;
    }
    return &p->dest;
}
