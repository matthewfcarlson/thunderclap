struct C3_1721c0 {
    void Apply(void* p, int f);
};
struct C2_1721c0 {
    C3_1721c0* Get2();
};
struct C1_1721c0 {
    C2_1721c0* Get();
};
class SyncToLocatorAction {
  public:
    char pad[0x20];
    C1_1721c0* member20;
    char pad24[0x0c];
    void* member30;
    void vfunc_4();
};
void SyncToLocatorAction::vfunc_4() {
    C2_1721c0* a = member20->Get();
    C3_1721c0* b = a->Get2();
    if (b)
        b->Apply(member30, 0);
}
