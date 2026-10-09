class ImageSelector {
public:
    char pad[0x2a8];
    int value;
    int compare;
    void vfunc_1(int);
};
void ImageSelector::vfunc_1(int param) {
    if (param == compare) value = *(int *)(compare + 0x40);
}