void thunk_FUN_00267090(int);
void FUN_002e61c0(int* param_1, int* param_2) {
    for (; param_1 != param_2; param_1 += 3) {
        if (*param_1 != 0)
            thunk_FUN_00267090(*param_1);
    }
}