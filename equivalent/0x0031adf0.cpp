// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 20/22, incomplete)
// FUN_0031adf0 @ 0x0031adf0
extern int DAT_004d35dc;
extern int FUN_00356667();
struct DisplayMode_31adf0 { int width; unsigned char bytes[8]; };
extern DisplayMode_31adf0 DAT_004d350c[];
int __cdecl FUN_0031adf0(int index) {
    int flags = DAT_004d35dc;
    if (flags == -1) {
        flags = FUN_00356667();
        DAT_004d35dc = flags;
    }
    DisplayMode_31adf0 &mode = DAT_004d350c[index];
    int width = mode.width;
    int result = 1;
    if (width == 480) {
        if (mode.bytes[1] && !(flags & 1)) result = 0;
        else if (mode.bytes[0] && !(flags & 8)) result = 0;
    }
    if (result && width == 720 && !(flags & 2)) result = 0;
    if (result && width == 1080 && !(flags & 4)) result = 0;
    return (flags & ~255) | result;
}