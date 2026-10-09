struct C3 {
    void Apply(void* p, int f);
};
struct C2 {
    C3* Get2();
};
struct C1 {
    C2* Get();
};
class SyncToLocatorAction {
  public:
    char pad[0x20];
    C1* member20;
    char pad24[0x0c];
    void* member30;
    void vfunc_4();
};
void SyncToLocatorAction::vfunc_4() {
    C2* a = member20->Get();
    C3* b = a->Get2();
    if (b)
        b->Apply(member30, 0);
}
