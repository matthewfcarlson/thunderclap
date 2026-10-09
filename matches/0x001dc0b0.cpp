class CGrabAction {
  public:
    int Get(int index);
    char pad[0x1e820];
    int mCount;
};
int CGrabAction::Get(int index) {
    int r = 0;
    if (index < mCount) {
        if (index >= 0)
            r = *(int*)((char*)this + 0x1e620 + index * 4);
    }
    return r;
}
