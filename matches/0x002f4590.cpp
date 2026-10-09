typedef unsigned short ushort;
extern void FUN_002f3b10(ushort*, ushort*, ushort*, int, int);
void FUN_002f4590(ushort* param_1, ushort* param_2) {
    ushort* puVar4;
    ushort* puVar5;
    if (param_1 != param_2) {
        puVar4 = param_1 + 1;
        if (puVar4 != param_2) {
            puVar5 = param_1 + 2;
            do {
                ushort uVar1 = *puVar4;
                ushort* puVar2 = param_1;
                if (uVar1 < *param_1) {
                    if (puVar2 != puVar4 && puVar4 != puVar5)
                        FUN_002f3b10(puVar2, puVar4, puVar5, 0, 0);
                } else {
                    ushort* puVar3 = puVar5 - 2;
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