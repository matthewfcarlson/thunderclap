struct CCameraShakeTrack {
    virtual int vfunc_0(int);
};
extern void* g_table;
int CCameraShakeTrack::vfunc_0(int index) {
    void** p = (void**)g_table;
    return (int)p[index];
}
