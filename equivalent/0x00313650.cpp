// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 32/32)
// FUN_00313650 @ 0x00313650
struct Ranking {
    int best;
    int others[3];
};

void __stdcall FUN_00313540(int *others, float a, float b, float c);

void __stdcall FUN_00313650(Ranking *out, const float *v)
{
    if (v[0] >= v[1] && v[0] >= v[2] && v[0] >= v[3]) {
        out->best = 0;
        FUN_00313540(out->others, v[1], v[2], v[3]);
        out->others[0] = out->others[0] + 1;
        out->others[1] = out->others[1] + 1;
        out->others[2] = out->others[2] + 1;
    } else if (v[1] >= v[0] && v[1] >= v[2] && v[1] >= v[3]) {
        out->best = 1;
        FUN_00313540(out->others, v[0], v[2], v[3]);
        for (int i = 0; i < 3; i++) {
            if (out->others[i] > 0) out->others[i]++;
        }
    } else if (v[2] >= v[0] && v[2] >= v[1] && v[2] >= v[3]) {
        out->best = 2;
        FUN_00313540(out->others, v[0], v[1], v[3]);
        for (int i = 0; i < 3; i++) {
            if (out->others[i] > 1) out->others[i]++;
        }
    } else {
        out->best = 3;
        FUN_00313540(out->others, v[0], v[1], v[2]);
        for (int i = 0; i < 3; i++) {
            if (out->others[i] > 2) out->others[i]++;
        }
    }
}
