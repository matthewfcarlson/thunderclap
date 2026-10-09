typedef unsigned int U32;
void FUN_0030bf40(U32* param_1, int param_2, U32* param_3) {
    volatile U32* out = param_3;
    if (param_2 != 0) {
        do {
            if (out != 0) *out = *param_1;
            ++param_1;
            ++out;
        } while (--param_2 != 0);
    }
}