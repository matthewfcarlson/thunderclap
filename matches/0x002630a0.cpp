class HalRsdFileStream {
  public:
    char pad[0x3c];
    int mValue;
    int mOther;
    int mState;
    bool vfunc_8(int* out);
};
bool HalRsdFileStream::vfunc_8(int* out) {
    if (mState == 5)
        return false;
    *out = mValue;
    mState = 4;
    return true;
}