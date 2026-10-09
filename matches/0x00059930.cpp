extern char CFightParamsCollision_vftable[4];
extern char CFightParams_vftable[4];

class RefObj {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

class SubObj {
  public:
    void destroy();
};

class CFightParams {
  public:
    void baseDtor();
};

void operator delete(void* p);

union VPtr {
    unsigned int n;
    volatile unsigned int v;
};

class CFightParamsCollision {
  public:
    VPtr m_vptr;
    char pad0[8];
    RefObj* volatile m_pC;
    RefObj* volatile m_p10;
    char pad1[4];
    SubObj m_sub;

    CFightParamsCollision* vfunc_2(unsigned char flag);
};

CFightParamsCollision* CFightParamsCollision::vfunc_2(unsigned char flag) {
    this->m_vptr.n = (unsigned int)&CFightParamsCollision_vftable[0];
    this->m_sub.destroy();
    this->m_vptr.v = (unsigned int)&CFightParams_vftable[0];
    RefObj* p10 = this->m_p10;
    if (p10 != 0) {
        p10->vfunc_1();
        this->m_p10 = 0;
    }
    RefObj* pc = this->m_pC;
    if (pc != 0) {
        pc->vfunc_1();
        this->m_pC = 0;
    }
    reinterpret_cast<CFightParams*>(this)->baseDtor();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
