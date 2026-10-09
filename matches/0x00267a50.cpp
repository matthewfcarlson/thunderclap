extern int count;
extern int first;
extern int second;
void __stdcall FUN_00354ce2(int*);
void FUN_00267a50() {
    count++;
    if (count == 1) {
        int local[2];
        FUN_00354ce2(local);
        first = local[0];
        second = local[1];
    }
}