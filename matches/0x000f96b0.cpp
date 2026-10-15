struct Entry {
    volatile int a;
    int b;
    int pad[2];
};
class Pool {
  public:
    Entry entries[128];
    int* put(int a, int b);
};
int* Pool::put(int a, int b) {
    for (int i = 0; i < 128; i++) {
        if (!(entries[i].a | entries[i].b)) {
            entries[i].a = a;
            entries[i].b = b;
            return (int*)&entries[i].pad[0];
        }
    }
    return 0;
}