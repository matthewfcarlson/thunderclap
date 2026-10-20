extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
void __cdecl thunk_FUN_00267090(void* p);
void* __cdecl FUN_0008d6d0(unsigned int size);

class Obj_001a4330 {
public:
    char pad[0x130];
    char* name;
    bool SetName(const char* s);
};

bool Obj_001a4330::SetName(const char* s)
{
    thunk_FUN_00267090(name);
    if (s == 0) {
        name = 0;
        return true;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return true;
}
