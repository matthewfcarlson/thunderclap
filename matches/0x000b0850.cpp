extern int DAT;
struct C {
    int data[100];
    int* Get(int, int, int);
};
int* C::Get(int x, int y, int z) {
    if (x >= 0 && x < 2 && y >= 0 && y < 2 && z >= 0 && z < 3) {
        int* p = data + (z + (y + 15 + x * 2) * 3) * 2;
        if (p[0] > 0)
            return (int*)p[1];
    }
    return &DAT;
}