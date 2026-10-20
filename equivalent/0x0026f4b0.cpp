// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 6/6)
// FUN_0026f4b0 @ 0x0026f4b0
extern "C" int __stdcall GetLastError();
extern "C" char * __cdecl _strncpy(char *, const char *, unsigned int);
struct Result_26f4b0 { int status; char name[257]; };
struct Entry_26f4b0 { unsigned char flags; char pad[43]; char name[256]; };
struct XboxDrive_26f4b0 {
    int FUN_0026f3e0(int error);
    int FUN_0026f4b0(Result_26f4b0 *result, Entry_26f4b0 *entry, int *handle);
};
int XboxDrive_26f4b0::FUN_0026f4b0(Result_26f4b0 *result, Entry_26f4b0 *entry, int *handle)
{
    if (*handle == -1) {
        int error = GetLastError();
        if (error != 18 && error != 2)
            return FUN_0026f3e0(error);
        result->name[0] = 0;
        result->status = 2;
        return 0;
    }
    _strncpy(result->name, entry->name, 256);
    result->name[256] = 0;
    result->status = (entry->flags >> 4) & 1;
    return 0;
}