// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003400e0 @ 0x003400e0
struct Transform {
    char reserved0[8];
    float firstX;
    float firstY;
    char reserved1[8];
    unsigned int secondX;
    unsigned int secondY;
    float thirdX;
    float thirdY;
    char reserved2[8];
    unsigned int fourthX;
    unsigned int fourthY;
};
// equiv-conv: FUN_003400e0 eax
extern "C" void FUN_003400e0(void *transform)
{
    float x = ((Transform *)transform)->firstX;
    float y = ((Transform *)transform)->firstY;
    ((Transform *)transform)->firstX = ((Transform *)transform)->thirdX;
    ((Transform *)transform)->firstY = ((Transform *)transform)->thirdY;
    ((Transform *)transform)->thirdX = x;
    ((Transform *)transform)->thirdY = y;

    unsigned int bx = ((Transform *)transform)->secondX;
    unsigned int by = ((Transform *)transform)->secondY;
    ((Transform *)transform)->secondX = ((Transform *)transform)->fourthX;
    ((Transform *)transform)->secondY = ((Transform *)transform)->fourthY;
    ((Transform *)transform)->fourthX = bx;
    ((Transform *)transform)->fourthY = by;
}