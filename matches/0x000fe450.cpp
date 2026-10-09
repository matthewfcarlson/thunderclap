class CGolem {
    char pad[0xf8];
};
class CActorGolem : public CGolem {
  public:
    int vfunc_6();
};
int CActorGolem::vfunc_6() {
    return *(int*)((char*)this + 0xf8);
}