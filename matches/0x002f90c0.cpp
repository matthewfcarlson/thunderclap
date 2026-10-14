struct Vec_2f90c0 {
    float f[6];
    bool Same(Vec_2f90c0* b);
};
bool Vec_2f90c0::Same(Vec_2f90c0* b) {
    if (!(b->f[3] <= f[3]) || !(b->f[0] >= f[0]) || !(b->f[4] <= f[4]) || !(b->f[1] >= f[1]) ||
        !(b->f[5] <= f[5]) || !(b->f[2] >= f[2]))
        return false;
    return true;
}
