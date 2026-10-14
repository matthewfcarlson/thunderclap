typedef unsigned int u32_2546f0;
extern u32_2546f0 FUN_00267f80();
class SeqActionSilence {
    char pad[0x14];

  public:
    u32_2546f0 m14;
    u32_2546f0 m18;
    void vfunc_1(int);
};
void SeqActionSilence::vfunc_1(int) {
    m14 = FUN_00267f80();
    m18 = 3;
}