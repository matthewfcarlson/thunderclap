void FUN_00213550(int* p, int value) {
    int* q = *(int**)((char*)p + 8);
    q[1] = value;
    q[0] = 2;
    *(int*)((char*)p + 8) += 8;
}