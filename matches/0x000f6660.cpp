int FUN_000f6660(int a, int b) {
    if (a >= 0)
        return a % b;
    return b - (-a % b);
}