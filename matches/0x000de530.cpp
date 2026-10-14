float __cdecl FUN_000de530(float x, float a, float b) {
    if (a > b) {
        if (x >= b && x <= a)
            return x;
        if (x > a)
            return a;
        return b;
    } else {
        if (x >= a && x <= b)
            return x;
        if (x > b)
            return b;
        return a;
    }
}