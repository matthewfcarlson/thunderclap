extern void** gTable;
struct Track {
    void* vfunc_0(int i);
};
void* Track::vfunc_0(int i) {
    return gTable[i];
}
