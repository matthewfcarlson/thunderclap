extern "C" char DAT_0042ea40[];
class Image {
  public:
    char pad0[0x10];
    int f10, f14, f18, f1c, f20, f24;
    char b28, b29;
    void InitBase();
    Image* FUN();
};
Image* Image::FUN() {
    InitBase();
    f24 = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    b29 = 0;
    b28 = 0;
    *(int*)this = ((int)DAT_0042ea40);
    f20 = 8;
    return this;
}