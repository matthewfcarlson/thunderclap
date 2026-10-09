class CChaseAgent {
  public:
    char pad0[8];
    int m8;
    char padc[0x68 - 0x0c];
    int m68;
    char pad6c[4];
    int m70;
    void vfunc_9();
};
void CChaseAgent::vfunc_9() {
    m8 = 0;
    m68 = (int)0xbf800000;
    m70 = 0;
    *((unsigned char*)this + 0x6c) = 0;
}