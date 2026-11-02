struct S_8c710 {
    char pad[0x10];
    unsigned char b[0x20];
};
extern "C" void FUN_0008c710(void * a, unsigned short* d) {
    if (d) {
        unsigned char* p = ((S_8c710 *)a)->b;
        int i = 0;
        do {
            if (p[0] == 0)
                break;
            d[i] = p[i];
            i++;
        } while (i < 0x1f);
        d[i] = 0;
    }
}
