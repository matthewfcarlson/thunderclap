class FEContainer { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void vfunc_6(); void *mContext; void helper(int); };
void FEContainer::vfunc_6() {
    helper(8);
    int state = *(int *)((char *)mContext + 0x17f8);
    if (state == 0) helper(0xc);
    state = *(int *)((char *)mContext + 0x17f8);
    if (state == 1) helper(0xd);
}