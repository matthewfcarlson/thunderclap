// STATUS: equivalent (tools/equiv.py level 3: 166 inputs, branch coverage 9/10, incomplete)
// FUN_002431a0 @ 0x002431a0
struct Pool {
    unsigned int stride;
    char *head;
    char *buf;
};
Pool *FUN_002431a0(Pool *p, char *buf, unsigned int total, unsigned int elem)
{
    if (elem < 4)
        elem = 4;
    if ((elem & 3) != 0)
        elem = elem - (elem & 3) + 4;
    unsigned int count = total / elem;
    p->stride = elem;
    p->buf = buf;
    if (count == 0) {
        p->head = 0;
        return p;
    }
    p->head = buf;
    char **cur = (char **)buf;
    for (unsigned int i = 0; i < count; i++) {
        char *next = p->head + p->stride * i;
        *cur = next;
        cur = (char **)next;
    }
    *cur = 0;
    return p;
}
