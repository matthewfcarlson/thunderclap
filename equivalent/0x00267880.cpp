// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00267880 @ 0x00267880
void __cdecl FUN_00267880(char *destination, const char *source, int capacity)
{
    int length = 0;
    while (destination[length] != '\0')
        ++length;

    const char *current = source;
    char value = *current;
    while (value != '\0' && length < capacity - 1) {
        destination[length] = value;
        ++length;
        ++current;
        value = *current;
    }
    destination[length] = '\0';
}
