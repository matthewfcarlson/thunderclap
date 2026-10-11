extern "C" char DAT_004265fc[];
extern "C" char DAT_00426948[];
extern "C" char* FUN_00212f20(int, int index) {
    if (index == -1)
        return (char*)((int)DAT_004265fc);
    return *(char**)(((int)DAT_00426948) + index * 4);
}