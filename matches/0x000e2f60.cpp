class TextSelector {
  public:
    char pad0[0x154];
    int mValue;
    char pad1[0x1d94 - 0x158];
    int mSelected;
    void vfunc_1(int param);
};

void TextSelector::vfunc_1(int param) {
    if (param == mSelected)
        mValue = *(int*)(mSelected + 0x40);
}
