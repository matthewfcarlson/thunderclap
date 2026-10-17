// STATUS: equivalent (tools/equiv.py level 3: 3096 inputs, branch coverage 14/16, incomplete)
// FUN_0028fb20 @ 0x0028fb20
void __cdecl FUN_0028fb20(char *destination, const char *path)
{
    int length = 0;
    while (path[length] != '\0')
        ++length;

    int separator = length;
    while (separator >= 0 && path[separator] != '/' && path[separator] != '\\')
        --separator;

    int count = length - separator;
    for (int i = 0; i < count; ++i)
        destination[i] = path[separator + i + 1];
}
