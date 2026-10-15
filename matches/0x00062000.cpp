// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_62000;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CWeaponCollisionTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CWeaponCollisionTrack::vfunc_0(int index) {
    int* p = gTable_62000;
    return p[index];
}
