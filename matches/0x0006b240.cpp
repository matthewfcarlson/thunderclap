class CTargetTrack {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable;
int CTargetTrack::vfunc_0(int i) {
    return gTable[i];
}