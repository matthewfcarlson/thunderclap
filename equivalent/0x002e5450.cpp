// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 6/6)
// FUN_002e5450 @ 0x002e5450
struct Triple { unsigned int first, second, third; };

Triple* __cdecl FUN_002e5450(Triple* destination, unsigned int count, const Triple* source)
{
    char* current = (char*)destination;
    for (unsigned int i = 0; i != count; ++i) {
        if (current) {
            Triple* item = (Triple*)current;
            item->first = source->first;
            item->second = source->second;
            item->third = source->third;
        }
        current += sizeof(Triple);
    }
    return (Triple*)current;
}