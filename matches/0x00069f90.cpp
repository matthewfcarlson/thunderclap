extern int* gComboTimerValues;
class CComboTimerTrack {
  public:
    virtual int vfunc_0(int index);
};
int CComboTimerTrack::vfunc_0(int index) {
    return gComboTimerValues[index];
}