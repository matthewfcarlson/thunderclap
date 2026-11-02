// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00220a50 @ 0x00220a50
struct Data { char pad[12]; unsigned int *words; };
struct Owner { Data *data; };
struct State { unsigned int kind; unsigned int index; };
extern "C" void __cdecl FUN_00220a50(void * owner_, void *state, int value)
{
    Owner * owner = (Owner *)owner_;
    if (((State *)state)->kind != 12) return;
    unsigned int &word = owner->data->words[((State *)state)->index];
    word ^= (((value + 1) << 6) ^ word) & 0x7fc0;
    if (value == 1) {
        ((State *)state)->kind = 11;
        ((State *)state)->index = ((unsigned char *)&owner->data->words[((State *)state)->index])[3];
    }
}