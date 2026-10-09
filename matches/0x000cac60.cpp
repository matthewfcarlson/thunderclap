class Obj {
  public:
    char pad0[0x264];
    char a[8][0x40];
    char pad1[0x14];
    int x478;
    int x47c;
    int x480;
    int x484;
    int x488;
    int x48c;
    char pad2[4];
    int x494;
    int x498;
    int x49c;
    void Init();
};
void Obj::Init() {
    int i;
    for (i = 0; i < 8; i++)
        a[i][0] = 0;
    x478 = 0;
    x47c = 0;
    x480 = 0;
    x484 = 0;
    x488 = 0;
    x48c = 0;
    x494 = 0xff;
    x498 = -1;
    x49c = (int)0xbf800000;
}