float f(float* a, float* b, float* c)
{
    if (*a >= *b && *a <= *c)
        return *a;
    if (*a > *c)
        return *c;
    return *b;
}