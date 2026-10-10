// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0026f330 @ 0x0026f330
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
struct PathBuilder {
    char pad[0xc4];
    char directory[0x114];
    const char* prefix;
    int prefixLength;
    void FUN_0026f330(const char* name, char* result, int capacity);
};
void PathBuilder::FUN_0026f330(const char* name, char* result, int capacity)
{
    int directoryLength = 0;
    while (directory[directoryLength] != '\0') ++directoryLength;
    int position = directoryLength + 1;
    strncpy(result, directory, capacity - 1);
    strncpy(result + directoryLength, "\\", capacity - position);
    if (prefix) {
        strncpy(result + position, prefix, capacity - position - 1);
        position += prefixLength;
    }
    if (*name == '\\') ++name;
    strncpy(result + position, name, capacity - position - 1);
    result[capacity - 1] = '\0';
}