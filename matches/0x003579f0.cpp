struct V {
    float x, y, z;
};
static inline float dot(V* a, V* b) {
    return a->z * b->z + a->y * b->y + a->x * b->x;
}
void Proj(V* d, V** t, float* mn, float* mx) {
    V* a = t[0];
    float v0 = a->z * d->z + a->y * d->y + a->x * d->x;
    *mn = v0;
    *mx = v0;
    float v1 = dot(d, t[1]);
    if (v1 < *mn)
        *mn = v1;
    else if (v1 > *mx)
        *mx = v1;
    float v2 = dot(d, t[2]);
    if (v2 < *mn)
        *mn = v2;
    else if (v2 > *mx)
        *mx = v2;
}
