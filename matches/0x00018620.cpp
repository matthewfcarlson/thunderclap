struct ObjA {
    void* Get();
};
struct ObjB {
    void* Next();
};
struct ObjC {
    int Run();
};
class CClearHitRecordsAction {
  public:
    char pad[0x1c];
    ObjA* mThing;
    bool vfunc_6(int);
};
bool CClearHitRecordsAction::vfunc_6(int x) {
    ObjA* a = mThing;
    void* r = a->Get();
    void* b = ((ObjB*)r)->Next();
    if (b)
        ((ObjC*)b)->Run();
    return false;
}