extern int gTable[1];
int FUN_0024c2f0(unsigned int* p) {
    unsigned int v = *p;
    int index = (int)(v << 28) >> 28;
    return (int)((v >> 4) & 31) * *(int*)((char*)gTable + index * 24);
}