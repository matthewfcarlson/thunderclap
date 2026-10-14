// STATUS: equivalent (tools/equiv.py level 3: 1948 inputs, branch coverage 14/14)
// FUN_002199d0 @ 0x002199d0
// equiv-conv: FUN_002199d0 edx stack stack stack
void FUN_002199d0(int *nums, int total, int *narray, int *diff)
{
    int a = nums[0];
    int kept = a;
    int best = (a != 0) ? 0 : -1;
    int limit = *narray;
    if (a < limit) {
        const int *p = nums + 1;
        int i = 0;
        do {
            int twotoi = 1 << i;
            if (limit < twotoi)
                break;
            int count = *p;
            if (count > 0) {
                a += count;
                if (a >= twotoi) {
                    best = i + 1;
                    kept = a;
                }
            }
            p++;
            i++;
        } while (a < *narray);
    }
    *diff = total - kept;
    if (best == -1)
        *narray = 0;
    else
        *narray = 1 << best;
}
