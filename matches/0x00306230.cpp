struct Vec3 {
    float x, y, z;
};
struct PtrVec {
    int* b;
    int* e;
};
class Node {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3* GetPos();
    virtual void v5();
    virtual int GetKind();
    int pad4;
    int mIdx;
    int pad0c;
    int pad10;
    PtrVec* mKids;
    int pad18;
    Vec3 mPos;
    void Reset();
};
void Node::Reset() {
    mIdx = -1;
    if (GetKind() != 1) {
        Vec3* p = GetPos();
        mPos.x = p->x;
        mPos.y = p->y;
        mPos.z = p->z;
    }
    if (mKids) {
        for (unsigned i = 0; i < (unsigned)(mKids->e - mKids->b); i++)
            ((Node*)mKids->b[i])->Reset();
    }
}
