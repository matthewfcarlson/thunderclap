struct V3 {
    int x, y, z;
};
class Vector3DOFChannel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, float*, V3*);
    virtual void f4();
    virtual void f5();
    char pad[16];
    short* mIndices;
    V3* mValues;
};
void Vector3DOFChannel::vfunc_3(int index, float* outIndex, V3* outValue) {
    *outIndex = (float)mIndices[index];
    V3* p = mValues + index;
    int a = p->x;
    V3* q = p;
    outValue->x = a;
    outValue->y = q->y;
    outValue->z = q->z;
}