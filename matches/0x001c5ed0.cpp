struct Owner_1c5ed0 {
    char pad[16];
    int* target;
    void Copy(void* src);
};
void Owner_1c5ed0::Copy(void* src) {
    int* d = target;
    if (d) {
        int* s = (int*)src;
        d[9] = s[0];
        d[10] = s[1];
        d[11] = s[2];
    }
}