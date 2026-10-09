struct CArriveBehaviour {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    bool vfunc_3(int a, int b, float* out, int c, int e);
    char pad04[4];
    float mScale;
    char mFlag;
    char pad0d[3];
    char pad10[12];
    int mArg;
};
void FUN_00102bf0(int, void*, int, float*);
bool CArriveBehaviour::vfunc_3(int a, int b, float* out, int c, int e) {
    FUN_00102bf0(b, this->pad10, this->mArg, out);
    if (this->mFlag) {
        float f = this->mScale;
        out[0] = f * out[0];
        out[1] = f * out[1];
        out[2] = f * out[2];
    }
    return true;
}