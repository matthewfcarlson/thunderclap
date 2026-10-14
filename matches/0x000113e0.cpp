typedef unsigned int uint;
extern uint* gState;
int Random(int low, int high) {
    uint* p = gState;
    uint* q = gState + 1;
    *gState = (*gState & 65535) * 36969 + (*gState >> 16);
    uint b = *q;
    b = (b & 65535) * 18000 + (b >> 16);
    *q = b;
    return low + ((*p << 16) + (b & 65535)) % (high - low + 1);
}