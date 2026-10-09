int FUN_002f0030(float a, float b, float c) {
    if ((!(a > c) || !(b > c)) && (!(a < -c) || !(b < -c))) return 0;
    return 1;
}
