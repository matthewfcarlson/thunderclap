typedef unsigned short ushort_2f4590;
extern void FUN_002f3b10(ushort_2f4590*, ushort_2f4590*, ushort_2f4590*, int, int);
void FUN_002f4590(ushort_2f4590* param_1, ushort_2f4590* param_2) {
    ushort_2f4590* puVar4;
    ushort_2f4590* puVar5;
    if (param_1 != param_2) {
        puVar4 = param_1 + 1;
        if (puVar4 != param_2) {
            puVar5 = param_1 + 2;
            do {
                ushort_2f4590 uVar1 = *puVar4;
                ushort_2f4590* puVar2 = param_1;
                if (uVar1 < *param_1) {
                    if (puVar2 != puVar4 && puVar4 != puVar5)
                        FUN_002f3b10(puVar2, puVar4, puVar5, 0, 0);
                } else {
                    ushort_2f4590* puVar3 = puVar5 - 2;
                    if (uVar1 < *puVar3) {
                        do {
                            puVar2 = puVar3;
                            puVar3 = puVar2 - 1;
                        } while (uVar1 < *puVar3);
                        if (puVar2 != puVar4 && puVar4 != puVar5)
                            FUN_002f3b10(puVar2, puVar4, puVar5, 0, 0);
                    }
                }
                puVar4++;
                puVar5++;
            } while (puVar4 != param_2);
        }
    }
}