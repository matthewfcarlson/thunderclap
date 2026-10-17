// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::d3dDisplay::vfunc_15 @ 0x0031b610
namespace pure3d { struct DisplayRect { int x; int y; int height; int width; }; struct d3dDisplay { char pad[0x478]; int width; int height; void vfunc_15(int a, int b); void FUN_0031b230(int, int, DisplayRect *, int); }; }
void pure3d::d3dDisplay::vfunc_15(int a, int b) {
    DisplayRect rect;
    rect.x = 0;
    rect.y = 0;
    rect.height = height;
    rect.width = width;
    FUN_0031b230(a, b, &rect, 0);
}