int __stdcall GetThing(int);
int CheckThing();
void ApplyThing(int, int, float);
struct Obj {
    char pad[12];
    int value;
    void Reset(int);
};
extern Obj* gCurrent;
void __stdcall FUN_001e9a90(int a, unsigned int b) {
    Obj* p = (Obj*)GetThing(a);
    if (p && p != gCurrent) {
        if (gCurrent)
            gCurrent->Reset(b);
        if (CheckThing()) {
            int y = CheckThing();
            ApplyThing(y, p->value, (float)b);
        }
        gCurrent = p;
    }
}