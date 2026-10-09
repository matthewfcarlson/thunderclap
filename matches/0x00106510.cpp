extern void init();
extern void* alloc(unsigned int);
extern int CPatrolPath_vtable;
class CPatrolPath {
public:
    int vt;
    char pad4[12];
    void* mData;
    int mCount;
    char pad18[4];
    CPatrolPath(int count);
};
CPatrolPath::CPatrolPath(int count) {
    init();
    unsigned int size = count * 0x24;
    vt = (int)&CPatrolPath_vtable;
    *(char*)((char*)this + 0x18) = 0;
    mData = alloc(size);
    mCount = count;
}
