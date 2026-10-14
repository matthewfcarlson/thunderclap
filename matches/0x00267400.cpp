extern unsigned char initFlag;
extern unsigned int table_267400[256];
void FUN_00267400(void) {
    if (!initFlag) {
        unsigned int i = 0;
        do {
            unsigned int v = i << 24;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            table_267400[i] = v;
            ++i;
        } while (i < 256);
        initFlag = 1;
    }
}