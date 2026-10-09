extern "C" void* malloc(unsigned);

unsigned FUN_00270570(int param_1, unsigned param_2) {
    if (param_2 < 4)
        param_2 = 4;
    unsigned total = param_1 + param_2;
    if (total == 0)
        total = 1;
    void* p = malloc(total);
    unsigned rem = (unsigned)p % param_2;
    unsigned q = (unsigned)p - rem + param_2;
    *(int*)(q - 4) = (int)p;
    return q;
}
