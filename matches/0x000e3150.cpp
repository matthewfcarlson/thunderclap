class TextSelector {
  public:
    char pad0[0x44];
    int value;
    char pad48[0x100];
    int saved;
    char pad14c[0x1c3c];
    void* other;
    void vfunc_14(int);
};
void TextSelector::vfunc_14(int x) {
    saved = value;
    if (other)
        *(int*)((char*)other + 0x44) = value;
}