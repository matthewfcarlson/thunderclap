namespace pure3d {
struct DisplayRect {
    int x;
    int y;
    int height;
    int width;
};
struct d3dDisplay {
    char pad[0x478];
    int width;
    int height;
    void vfunc_15(int a, int b);
    void FUN_0031b230(int, int, DisplayRect*, int);
};
} // namespace pure3d
void pure3d::d3dDisplay::vfunc_15(int a, int b) {
    DisplayRect rect;
    rect.y = 0;
    rect.x = 0;
    rect.width = width;
    rect.height = height;
    FUN_0031b230(a, b, &rect, 0);
}