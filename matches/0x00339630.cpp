struct Thing { int* a; int b; int c; };
void FUN_00339630(int param_1, Thing* param_2) {
    param_2->c = param_1;
    param_2->a = (int*)((char*)param_2 + 12);
    param_2->b = 0;
}