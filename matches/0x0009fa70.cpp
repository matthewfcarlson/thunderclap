int FUN_0009fa70(int* a, int* b, int* c) {
    int x = *a;
    int y = *b;
    if (x >= y && x <= *c)
        return x;
    {
        int z = *c;
        if (x > z)
            return z;
        return y;
    }
}
