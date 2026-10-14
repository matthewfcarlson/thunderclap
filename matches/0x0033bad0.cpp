extern int Count(int);
extern float Value(int, int);
extern void Set(int, float);
int FUN_0033bad0(int x) {
    int n = Count(x);
    float v = Value(x, 1);
    for (int i = 2; i <= n; i++) {
        float t = Value(x, i);
        if (t > v)
            v = t;
    }
    Set(x, v);
    return 1;
}