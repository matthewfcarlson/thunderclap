struct ObjA_18620 {
    void* Get();
};
struct ObjB_18620 {
    void* Next();
};
struct ObjC_18620 {
    int Run();
};
class CClearHitRecordsAction {
  public:
    char pad[0x1c];
    ObjA_18620* mThing;
    bool vfunc_6(int);
};
bool CClearHitRecordsAction::vfunc_6(int x) {
    ObjA_18620* a = mThing;
    void* r = a->Get();
    void* b = ((ObjB_18620*)r)->Next();
    if (b)
        ((ObjC_18620*)b)->Run();
    return false;
}