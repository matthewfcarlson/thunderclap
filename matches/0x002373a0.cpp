extern int gPayload;
extern void (__cdecl *gUnknown)(int, int, int, int*, int*);
class OpportunityAction {
public:
    char pad[0x1c]; int mFirst;
    char pad2[0x1c]; int mSecond; int mOut1; int mOut2;
    bool vfunc_3(int value, int unused);
};
bool OpportunityAction::vfunc_3(int value, int unused) {
    int adjusted = value - 1;
    mOut1 = adjusted;
    mOut2 = adjusted;
    if (gUnknown) gUnknown(mFirst, mSecond, gPayload, &mOut1, &mOut2);
    return true;
}
