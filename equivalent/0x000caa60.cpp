// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000caa60 @ 0x000caa60
extern int DAT_0049fcb0;
void __stdcall FUN_000caa60(char *state, int *value)
{
    if (value && state) {
        if (*state == 0) {
            int next = *value + DAT_0049fcb0;
            *value = next;
            if (next > 255) {
                *value = 255;
                *state = 1;
            }
        } else {
            int next = *value - DAT_0049fcb0;
            *value = next;
            if (next < 0) {
                *value = 0;
                *state = 0;
            }
        }
    }
}