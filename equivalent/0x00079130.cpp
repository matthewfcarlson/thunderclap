// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00079130 @ 0x00079130
extern float DAT_003f32f4;
extern float DAT_003fef38;
extern float DAT_003fef3c;
struct Position { float x,y,z; };
// equiv-conv: FUN_00079130 eax esi
Position * FUN_00079130(int index, Position *result)
{
    int quotient = (index - 1) / 30;
    int remainder = (index - 1) % 30;
    int parity = remainder % 2;
    int row = -2 * quotient - (parity != 0);
    result->y = 0.0f;
    result->x = (float)row * DAT_003fef3c;
    result->z = ((float)remainder - DAT_003f32f4) * DAT_003fef38;
    return result;
}