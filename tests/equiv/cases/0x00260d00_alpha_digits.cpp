// atof-style parser: optional '-', digits, optional '.', up to six fractional digits.
// Any other character gives 0.
float __cdecl FUN_00260d00(const char *s)
{
    int whole = 0;
    int frac = 0;
    int digits = 0;
    bool negative = false;
    bool inWhole = true;

    if (*s == '-') {
        negative = true;
        s++;
    }
    for (const char *p = s; *p; p++) {
        char c = *p;
        if (c == '.') {
            inWhole = false;
        } else if (c < '0' || c > '9') {
            return 0.0f;
        } else if (inWhole) {
            whole = whole * 10 + (c - '0');
        } else if (digits < 6) {
            frac = frac * 10 + (c - '0');
            digits++;
        }
    }

    int scale = 10;
    for (int k = 1; k < digits; k++)
        scale *= 10;
    float value = whole + (1.0f / scale) * frac;
    if (negative)
        value = -value;
    return value;
}
