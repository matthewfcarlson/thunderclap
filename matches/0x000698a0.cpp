extern "C" int* g_table;
class CMoveTrack {
  public:
    virtual int vfunc_0(int index);
};
int CMoveTrack::vfunc_0(int index) {
    return g_table[index];
}
