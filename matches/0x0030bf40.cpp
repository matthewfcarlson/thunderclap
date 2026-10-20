typedef unsigned int U32_30bf40;
U32_30bf40* FUN_0030bf40(U32_30bf40* param_1, int param_2, U32_30bf40* param_3) {
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