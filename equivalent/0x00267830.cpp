// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00267830 @ 0x00267830
char * __cdecl FUN_00267830(char *destination, const char *source, int capacity)
{
    int copied = 0;
    if (*source != '\0') {
        while (copied < capacity - 1 && *source != '\0') {
            destination[copied++] = *source++;
        }
    }
    destination[copied] = '\0';
    return destination;
}