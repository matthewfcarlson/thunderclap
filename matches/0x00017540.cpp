struct A_17540 {
    A_17540* get();
    A_17540* valid();
    void apply(void*, int);
};
class COrientTargetAction {
  public:
    char pad[0x1c];
    A_17540* m1;
    char pad20[8];
    void* m28;
    void vfunc_4();
};
void COrientTargetAction::vfunc_4() {
    A_17540* a = m1->get();
    a = a->valid();
    if (a)
        a->apply(m28, 0);
}