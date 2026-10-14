// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002227d0 @ 0x002227d0
struct Resource {
 virtual void AddRef();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 virtual unsigned GetFirst();
 virtual unsigned GetSecond();
};
struct Entry {
 Resource* resource;
 float value;
 bool negative;
 char padding[3];
 unsigned first, second, parameter;
 float clamped;
 unsigned arg5, arg6, zero;
};
struct Owner {
 char padding[0x68];
 unsigned count;
 Entry entries[16];
 bool changed;
 bool FUN_002227d0(Resource* resource, float value, unsigned parameter, float clamped, unsigned arg5, unsigned arg6);
};
bool Owner::FUN_002227d0(Resource* resource, float value, unsigned parameter, float clamped, unsigned arg5, unsigned arg6) {
 if(count >= 16) return false;
 Entry& entry = entries[count];
 entry.resource = resource;
 resource->AddRef();
 entry.value = value;
 entry.negative = value < 0.0f;
 entry.first = resource->GetFirst();
 entry.second = resource->GetSecond();
 entry.parameter = parameter;
 entry.clamped = clamped < 0.0f ? 0.0f : clamped;
 entry.arg5 = arg5;
 entry.arg6 = arg6;
 entry.zero = 0;
 ++count;
 changed = true;
 return true;
}