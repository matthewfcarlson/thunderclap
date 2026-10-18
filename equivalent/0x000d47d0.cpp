// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d47d0 @ 0x000d47d0
class Obj_d47d0 {
public:
    void FUN_000d4620(int mode, int a, int b, unsigned int color, float scale);
    void Set(int a, int b, float r, float g, float bl);
};

void Obj_d47d0::Set(int a, int b, float r, float g, float bl)
{
    unsigned int color = (((0xffffff00 | (int)r) << 8 | (int)g) << 8) | (int)bl;
    FUN_000d4620(2, a, b, color, 3.0f);
}
