namespace audio {
class SeqAction {
  public:
    int vptr;
    SeqAction(int);
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
extern char g_bss[];
audio::SeqAction::SeqAction(int flag) {
    vptr = 0x4298fc;
    if (flag & 1)
        FUN_00247550(g_bss, this);
}
