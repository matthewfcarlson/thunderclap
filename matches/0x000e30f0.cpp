class Notifier {
  public:
    void Notify(int);
};
class TextSelector {
  public:
    virtual void vfunc_0();
    char pad0[0x150];
    int flag;
    char pad1[0x1d94 - 0x158];
    Notifier* notifier;

  public:
    void vfunc_26(int index, int value);
};
void TextSelector::vfunc_26(int index, int value) {
    *(int*)((char*)this + (index + 7) * 0x38) = value;
    if (notifier)
        notifier->Notify(flag);
    vfunc_0();
}