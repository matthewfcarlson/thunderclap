typedef unsigned short U16;
class Buffer_2f9930 {
  public:
    char pad0[4];
    U16* cur;
    U16* end;
    void Insert(U16*, int, int);
};
void Buffer_2f9930::Insert(U16* src, int count, int value) {
    U16* p = cur;
    U16* q = p + count;
    if (q <= end) {
        cur = q;
        while (p != src) {
            --p;
            --q;
            if (q != 0)
                *q = *p;
        }
        U16* r = src;
        if (count != 0) {
            int d = value - (int)src;
            int n = count;
            do {
                if (r != 0)
                    *r = *(U16*)(d + (int)r);
                ++r;
                --n;
            } while (n != 0);
        }
    }
}
