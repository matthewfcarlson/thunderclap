typedef unsigned short ushort_2f4590;
extern void FUN_002f3b10(ushort_2f4590*, ushort_2f4590*, ushort_2f4590*, int, int);
extern "C" void FUN_002f4590(unsigned short * first, unsigned short * last) {
    ushort_2f4590* cur;
    ushort_2f4590* next;
    if (first != last) {
        cur = first + 1;
        if (cur != last) {
            next = first + 2;
            do {
                ushort_2f4590 value = *cur;
                ushort_2f4590* pos = first;
                if (value < *first) {
                    if (pos != cur && cur != next)
                        FUN_002f3b10(pos, cur, next, 0, 0);
                } else {
                    ushort_2f4590* prev = next - 2;
                    if (value < *prev) {
                        do {
                            pos = prev;
                            prev = pos - 1;
                        } while (value < *prev);
                        if (pos != cur && cur != next)
                            FUN_002f3b10(pos, cur, next, 0, 0);
                    }
                }
                cur++;
                next++;
            } while (cur != last);
        }
    }
}