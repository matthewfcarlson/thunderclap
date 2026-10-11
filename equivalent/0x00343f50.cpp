// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 24/24)
// FUN_00343f50 @ 0x00343f50
struct FftPlan {
    int count;
    int size;
    int reorder[1];
};

// equiv-conv: FUN_0033ed90 eax ecx edi
void FUN_0033ed90(FftPlan *plan, int quarter, float *table);
// equiv-conv: FUN_0033eef0 eax edx esi
void FUN_0033eef0(FftPlan *plan, int n, float *table);
// equiv-conv: FUN_00342e50 eax esi stack stack
void FUN_00342e50(float *table, float *data, int n, int limit);
// equiv-conv: FUN_00342d90 eax esi stack stack
void FUN_00342d90(float *table, float *data, int n, int limit);
// equiv-conv: FUN_00342f10 ebx stack stack stack
void FUN_00342f10(float *table, int n, float *data, int limit);
// equiv-conv: FUN_00343ce0 eax ecx stack stack stack
void FUN_00343ce0(float *table, float *data, int n, int *reorder, int count);
// equiv-conv: FUN_00343bb0 eax ecx stack stack stack
void FUN_00343bb0(float *table, float *data, int n, int *reorder, int count);

void __stdcall FUN_00343f50(int n, int direction, float *data, FftPlan *plan, float *table)
{
    int count = plan->count;
    if (n > count * 4) {
        FUN_0033ed90(plan, n >> 2, table);
        count = n >> 2;
    }
    int limit = plan->size;
    if (n > limit) {
        limit = n;
        FUN_0033eef0(plan, n, table + count);
    }

    if (direction < 0) {
        float last = data[n - 1];
        for (int i = n - 2; i >= 2;) {
            float t = data[i];
            i -= 2;
            data[i + 3] = t - data[i + 1];
            data[i + 2] = data[i + 1] + data[i + 2];
        }
        float first = data[0];
        data[1] = first - last;
        data[0] = last + data[0];
        if (n > 4) {
            FUN_00342e50(table + count, data, n, limit);
            FUN_00343ce0(table, data, n, plan->reorder, count);
        } else if (n == 4) {
            FUN_00343ce0(table, data, 4, plan->reorder, count);
        }
    }

    FUN_00342f10(table + count, n, data, limit);

    if (direction >= 0) {
        if (n > 4) {
            FUN_00343bb0(table, data, n, plan->reorder, count);
            FUN_00342d90(table + count, data, n, limit);
        } else if (n == 4) {
            FUN_00343bb0(table, data, 4, plan->reorder, count);
        }
        float diff = data[0] - data[1];
        data[0] = data[1] + data[0];
        for (int i = 2; i < n;) {
            float t = data[i];
            i += 2;
            data[i - 3] = t - data[i - 1];
            data[i - 2] = data[i - 1] + data[i - 2];
        }
        data[n - 1] = diff;
    }
}
