extern "C" void __cdecl subFree(void* p);
extern "C" void __cdecl objDelete(void* p);
extern const char CMotionTrailQueue_vftable[];

class CMotionTrailQueue {
  public:
    virtual ~CMotionTrailQueue();
    char pad[0x58];
    void* m_sub;
    void Cleanup();
    CMotionTrailQueue* vfunc_2(unsigned char flag);
};

CMotionTrailQueue* CMotionTrailQueue::vfunc_2(unsigned char flag) {
    void* sub = m_sub;
    *(const char**)this = CMotionTrailQueue_vftable;
    subFree(sub);
    Cleanup();
    if (flag & 1) {
        objDelete((void*)this);
    }
    return this;
}
