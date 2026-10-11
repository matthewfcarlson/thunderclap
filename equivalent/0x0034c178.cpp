// STATUS: equivalent (tools/equiv.py level 3: 137 inputs, branch coverage 36/38, incomplete)
// FUN_0034c178 @ 0x0034c178
extern double DAT_004d9e28;
extern double DAT_004d9e30;
extern double DAT_004d9e48;
int __cdecl FUN_0034c113(double v);

union DoubleBits {
    double d;
    unsigned int w[2];
};

/* pow() special cases for infinite operands; returns 1 when the result is a NaN (domain error). */
int __cdecl FUN_0034c178(double x, double y, double *result)
{
    DoubleBits xb;
    DoubleBits yb;
    double ax;
    xb.d = x;
    yb.d = y;
    ax = x;
    if (x < 0.0)
        ax = -x;

    if (yb.w[1] == 0x7ff00000 && yb.w[0] == 0) {
        /* y == +inf */
        if (ax > 1.0) {
            *result = DAT_004d9e28;
        } else if (ax < 1.0) {
            *result = 0.0;
        } else {
            *result = DAT_004d9e30;
            return 1;
        }
        return 0;
    }
    if (yb.w[1] == 0xfff00000 && yb.w[0] == 0) {
        /* y == -inf */
        if (ax > 1.0) {
            *result = 0.0;
        } else if (ax < 1.0) {
            *result = DAT_004d9e28;
        } else {
            *result = DAT_004d9e30;
            return 1;
        }
        return 0;
    }
    if (xb.w[1] == 0x7ff00000) {
        if (xb.w[0] != 0)
            return 0;
        if (y > 0.0)
            *result = DAT_004d9e28;
        else if (y < 0.0)
            *result = 0.0;
        else
            *result = 1.0;
        return 0;
    }
    if (xb.w[1] == 0xfff00000) {
        if (xb.w[0] != 0)
            return 0;
        int odd = FUN_0034c113(y);
        if (y > 0.0) {
            double r = DAT_004d9e28;
            if (odd == 1)
                r = -r;
            *result = r;
        } else if (y < 0.0) {
            *result = (odd == 1) ? DAT_004d9e48 : 0.0;
        } else {
            *result = 1.0;
        }
        return 0;
    }
    return 0;
}
