// STATUS: equivalent (tools/equiv.py level 3: 3078 inputs, branch coverage 17/17)
// FUN_0021dd30 @ 0x0021dd30
// equiv-conv: FUN_0021dd30 eax
int FUN_0021dd30(int op)
{
    switch (op) {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '^':
        return 4;
    case 0x117:
        return 5;
    case 0x11c:
        return 6;
    case 0x119:
        return 7;
    case '<':
        return 8;
    case 0x11b:
        return 9;
    case '>':
        return 10;
    case 0x11a:
        return 11;
    case 0x101:
        return 12;
    case 0x10f:
        return 13;
    }
    return 14;
}
