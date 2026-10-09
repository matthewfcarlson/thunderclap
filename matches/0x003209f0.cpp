extern const float a, b, c, d, e, g, h, i;
float FUN(float x) {
    if (x <= a)
        return a;
    if (x <= b)
        return b;
    if (x <= c)
        return c;
    if (x <= d)
        return d;
    if (x <= e)
        return e;
    if (x <= g)
        return g;
    if (x <= h)
        return h;
    return i;
}