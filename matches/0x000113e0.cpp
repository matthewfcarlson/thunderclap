typedef unsigned int uint;
extern uint* gState_113e0;
int Random(int low, int high) {
    uint* p = gState_113e0;
    uint* q = gState_113e0 + 1;
    *gState_113e0 = (*gState_113e0 & 65535) * 36969 + (*gState_113e0 >> 16);
    uint b = *q;
    b = (b & 65535) * 18000 + (b >> 16);
    *q = b;
    return low + ((*p << 16) + (b & 65535)) % (high - low + 1);
}