// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::OpportunityTrack::vfunc_10 @ 0x002379e0
void* __cdecl FUN_0008d690(unsigned size);
struct Sub { int w[3]; };
struct Node {
    void* FUN_00237470(void* a1, void* self, float a, float b, int f18, int f24, Sub* sub, void* a2, void* a3);
};
class OpportunityTrack {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void* vfunc_10(void* a1, void* a2, void* a3);
    char pad[8];
    float start;
    float end;
    float peak;
    int f18;
    char pad2[8];
    int f24;
    Sub sub;
};
void* OpportunityTrack::vfunc_10(void* a1, void* a2, void* a3) {
    float rise = end - start;
    float fall = peak - start;
    if (!(fall < 0.0f)) {
    } else if (peak >= 0.0f) {
        fall = 0.0f;
    }
    Node* n = (Node*)FUN_0008d690(0x50);
    if (!n) return 0;
    return n->FUN_00237470(a1, this, rise, fall, f18, f24, &sub, a2, a3);
}
