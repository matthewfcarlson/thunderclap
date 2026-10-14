// cl-flags: /O2 /GR /GX
extern int* g_table_68fb0;

class CJumpTrack {
  public:
    virtual int vfunc_0(int index);
};

int CJumpTrack::vfunc_0(int index) {
    return g_table_68fb0[index];
}
