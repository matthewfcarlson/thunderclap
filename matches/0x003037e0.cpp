struct Obj {
    int mFirst;  // offset 0
    int mSecond; // offset 4
    void CopyFirstToSecond();
};

void Obj::CopyFirstToSecond() {
    mSecond = mFirst;
}
