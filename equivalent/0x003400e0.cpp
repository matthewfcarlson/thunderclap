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
void FUN_003400e0(Transform *transform)
{
    float x = transform->firstX;
    float y = transform->firstY;
    transform->firstX = transform->thirdX;
    transform->firstY = transform->thirdY;
    transform->thirdX = x;
    transform->thirdY = y;

    unsigned int bx = transform->secondX;
    unsigned int by = transform->secondY;
    transform->secondX = transform->fourthX;
    transform->secondY = transform->fourthY;
    transform->fourthX = bx;
    transform->fourthY = by;
}