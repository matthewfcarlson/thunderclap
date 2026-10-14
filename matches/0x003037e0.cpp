struct Obj_3037e0 {
    int mFirst;  // offset 0
    int mSecond; // offset 4
    void CopyFirstToSecond();
};

void Obj_3037e0::CopyFirstToSecond() {
    mSecond = mFirst;
}
