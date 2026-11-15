// STATUS: must fail, also with EQUIV_ON=nanpayload (tools/equiv.py --wine level 3)
// (integ1, rev3 review of D39) deliberately wrong: a byte store into a word that holds -1 (the fuzzer's M32, 1 input
// in 16) stores x ^ 1. 0xffffffXX words both read as quiet NaNs, but the last store to the word is a byte, not a float.
struct Target_35ce0 { char pad[0x1cf4]; unsigned char value; unsigned char pad2[3]; void FUN_00035ce0(unsigned char x); };

void Target_35ce0::FUN_00035ce0(unsigned char x) {
    if (*(volatile int*)&value == -1)
        value = x ^ 1;      // WRONG where the word was -1
    else
        value = x;
}
