// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/11)
// FUN_0035a590 @ 0x0035a590
// FUN_0035a590 @ 0x0035a590: one-letter language/region code for the index FUN_00209f50 returns (1..9).
int __cdecl FUN_00209f50();
int FUN_0035a590()
{
    int code = '?';
    switch (FUN_00209f50()) {
    case 1: code = 'E'; break;
    case 2: code = 'J'; break;
    case 3: code = 'G'; break;
    case 4: code = 'F'; break;
    case 5: code = 'S'; break;
    case 6: code = 'I'; break;
    case 7: code = 'K'; break;
    case 8: code = 'C'; break;
    case 9: code = 'P'; break;
    }
    return code;
}
