class Thing {
public:
    char pad[0x1ec40];
    int values[4];
    int count;
    void ClearOne(int);
    void Finish();
    void Cleanup();
};
void Thing::Cleanup() {
    int i = 0;
    if (count > 0) {
        int* p = values;
        do {
            ClearOne(*p);
            ++i;
            ++p;
        } while (i < count);
    }
    Finish();
}
