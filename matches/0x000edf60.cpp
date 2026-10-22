class FEControl_edf60 {
  public:
    FEControl_edf60(int);
    virtual ~FEControl_edf60();
};
class ImageSelector : public FEControl_edf60 {
  public:
    char pad[0x14c];
    int b[0x40];
    char gap[0x40];
    int a[8];
    ImageSelector(int);
};
ImageSelector::ImageSelector(int arg) : FEControl_edf60(arg) {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    int* p = b;
    for (int i = 0; i < 0x40; ++i)
        p[i] = 0;
}