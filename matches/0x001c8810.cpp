class Bag { public: char pad0[0x138]; int items[256]; volatile unsigned int count; void Add(int value); };
void Bag::Add(int value) {
    if (value != 0) {
        unsigned int n = count;
        unsigned int i = 0;
        if (n > 0) {
            int *p = items;
            do {
                if (*p == value) return;
                ++i;
                ++p;
            } while (i < count);
        }
        if (n < 0x100) {
            count = n + 1;
            items[n] = value;
        }
    }
}