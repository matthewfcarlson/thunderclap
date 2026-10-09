class TextSelector {
  public:
    char pad[0x1d58];
    int count;
    void vfunc_21(int index, unsigned char value);
};
void TextSelector::vfunc_21(int index, unsigned char value) {
    if (index >= 0 && index < count)
        ((char*)this)[index * 0x38 + 0x18c] = value;
}