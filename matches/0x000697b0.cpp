extern int* gValues;
class CComboMessageTrack {
  public:
    virtual int vfunc_0(int index);
};
int CComboMessageTrack::vfunc_0(int index) {
    return gValues[index];
}