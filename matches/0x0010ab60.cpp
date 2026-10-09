class CSeekBehaviour {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b, float* p, int d, int e);
    char pad[4];
    float scale;
    unsigned char flag;
};
void helper(int, void*, float*);
bool CSeekBehaviour::vfunc_3(int a, int b, float* p, int d, int e) {
    helper(b, (char*)this + 16, p);
    if (flag) {
        float f = scale;
        *p = f * *p;
        p[1] = f * p[1];
        p[2] = f * p[2];
    }
    return true;
}
