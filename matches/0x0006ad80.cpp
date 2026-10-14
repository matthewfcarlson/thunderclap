extern int* gTable;
class CAlertStatusTrack {
  public:
    virtual int vfunc_0(int i);
};
int CAlertStatusTrack::vfunc_0(int i) {
    return gTable[i];
}
