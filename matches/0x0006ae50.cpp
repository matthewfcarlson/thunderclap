class CDeathTrack {
  public:
    virtual int vfunc_0(int arg);
};

extern int* g_table;

int CDeathTrack::vfunc_0(int arg) {
    return g_table[arg];
}
