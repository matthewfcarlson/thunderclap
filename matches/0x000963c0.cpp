extern const float zero;
float FUN_000963c0(float a, float b, float c, float d, float e)
{
    if (!(e <= a)) {
        if (e >= c)
            return d;
        if (c - a > zero)
            return (d - b) * ((e - a) / (c - a)) + b;
    }
    return b;
}
