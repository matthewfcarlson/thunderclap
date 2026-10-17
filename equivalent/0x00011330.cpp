// STATUS: equivalent (tools/equiv.py level 3: 2859 inputs, branch coverage 0/0)
// FUN_00011330 @ 0x00011330
struct Random { unsigned int low; unsigned int high; unsigned int FUN_00011330(unsigned int maximum); };
unsigned int Random::FUN_00011330(unsigned int maximum) {
    low = (low & 0xffffU) * 0x9069U + (low >> 16);
    high = (high & 0xffffU) * 0x4650U + (high >> 16);
    return ((low << 16) + (high & 0xffffU)) % (maximum + 1U);
}
