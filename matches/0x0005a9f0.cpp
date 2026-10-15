// Same code shape as 0x00048300 (propagated; names are from that function)
extern int* gTable_5a9f0;
class CCondition {
  public:
    virtual int vfunc_0(int);
};
class CGrappleAttachTrack : public CCondition {
  public:
    int vfunc_0(int);
};
int CGrappleAttachTrack::vfunc_0(int index) {
    int* p = gTable_5a9f0;
    return p[index];
}
