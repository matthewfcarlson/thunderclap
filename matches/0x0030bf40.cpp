typedef unsigned int U32_30bf40;
extern "C" unsigned int * FUN_0030bf40(unsigned int * param_1, int param_2, unsigned int * param_3) {
    U32_30bf40* out = param_3;
    if (param_2 != 0) {
        do {
            if (out != 0)
                *out = *param_1;
            ++param_1;
            ++out;
        } while (--param_2 != 0);
    }
    return out;
}