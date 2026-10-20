struct Vec3 {
    unsigned int x, y, z;
};
struct Destination {
    char pad0[0x3c];
    unsigned int value;
    char pad1[0x38];
    Vec3 position;
};
struct Source {
    unsigned int state;
    Destination* destination;
    char pad0[0x18];
    Vec3 position;
    unsigned int pad1;
    volatile unsigned int value;
    void FUN_000fb420();
};
inline void copyVec(Vec3* d, volatile Vec3* s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}
void Source::FUN_000fb420() {
    destination->value = value;
    volatile Vec3 tmp = position;
    copyVec(&destination->position, &tmp);
    state = 0;
}