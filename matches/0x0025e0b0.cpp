struct Buffer {
    char p0[4];
    unsigned capacity;
    char p8[8];
    unsigned char full;
    char p11[3];
    unsigned position;
    unsigned end;
    unsigned readCount;
    unsigned writeCount;
    unsigned wraps;
};
bool FUN_0025e0b0(Buffer* b, unsigned amount, int mode) {
    if (!amount)
        return true;
    unsigned pos = b->position, end = b->end, available;
    if (pos == end && !b->full)
        available = b->capacity;
    else if (pos > end)
        available = (b->capacity - pos) + end;
    else
        available = end - pos;
    bool overflow = amount > available;
    b->position = (pos + amount) % b->capacity;
    if (b->position == end)
        b->full = 1;
    if (mode == 0)
        b->readCount += amount;
    else if (mode == 1)
        b->writeCount += amount;
    if (overflow)
        b->wraps += b->capacity;
    return !overflow;
}