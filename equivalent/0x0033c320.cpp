// STATUS: equivalent (tools/equiv.py level 3: 3045 inputs, branch coverage 21/21)
// FUN_0033c320 @ 0x0033c320
extern "C" int __cdecl FUN_00345475(int);
extern "C" int __cdecl _isalpha(int);
extern "C" int __cdecl _iscntrl(int);
extern "C" int __cdecl _isdigit(int);
extern "C" int __cdecl _islower(int);
extern "C" int __cdecl _ispunct(int);
extern "C" int __cdecl _isspace(int);
extern "C" int __cdecl _isupper(int);
extern "C" int __cdecl _isalnum(int);
extern "C" int __cdecl _isxdigit(int);
// equiv-conv: FUN_0033c320 eax edi
int __cdecl FUN_0033c320(int character, int classCode) {
    int result;
    switch (FUN_00345475(classCode)) {
    case 'a': result = _isalpha(character); break;
    case 'c': result = _iscntrl(character); break;
    case 'd': result = _isdigit(character); break;
    case 'l': result = _islower(character); break;
    case 'p': result = _ispunct(character); break;
    case 's': result = _isspace(character); break;
    case 'u': result = _isupper(character); break;
    case 'w': result = _isalnum(character); break;
    case 'x': result = _isxdigit(character); break;
    case 'z': result = character == 0; break;
    default: return classCode == character;
    }
    return _islower(classCode) ? result : !result;
}
