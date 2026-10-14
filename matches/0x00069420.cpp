struct CDropTrack {
    virtual int vfunc_0(int index);
};
extern int* g_table;
int CDropTrack::vfunc_0(int index) {
    return g_table[index];
}
