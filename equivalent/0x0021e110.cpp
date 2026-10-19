// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0021e110 @ 0x0021e110
struct Resource { char pad[0x24]; int replacement; };
struct Owner { char pad[0x1c]; Resource* resource; };
struct Entry { Entry* next; int type; int first; int second; };
struct Source { int unused; int value; };
void __cdecl FUN_00220bd0(Resource*, int, int, int, int);
void __cdecl FUN_00220850(Resource*, int);
// equiv-conv: FUN_0021e110 ecx eax edi
void FUN_0021e110(Owner* owner, Entry* entry, Source* source)
{
    Resource* resource = owner->resource;
    int replacement = resource->replacement;
    bool changed = false;
    for (; entry; entry = entry->next) {
        if (entry->type == 8) {
            if (entry->first == source->value) {
                changed = true;
                entry->first = replacement;
            }
            if (entry->second == source->value) {
                changed = true;
                entry->second = replacement;
            }
        }
    }
    if (changed) {
        FUN_00220bd0(resource, 0, resource->replacement, source->value, 0);
        FUN_00220850(resource, 1);
    }
}