// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 26/28, incomplete)
// FUN_00233fe0 @ 0x00233fe0
struct Item {
 virtual void AddRef() = 0;
 virtual void Release() = 0;
 Item* FUN_00232fe0();
};
struct Source {
 Item* FUN_00233650(unsigned key);
 Item* FUN_00232f60();
};
struct Handle {
 Item* object;
 unsigned key;
 int index;
 void FUN_00233ef0(Source* source, Item* object);
 bool FUN_00233fe0(Source* source);
};
bool Handle::FUN_00233fe0(Source* source) {
 if (object) return true;
 if (!source) return false;
 if (key) {
  Item* found = source->FUN_00233650(key);
  if (found) found->AddRef();
  if (object) object->Release();
  object = found;
 } else if (index >= 0) {
  Item* current = source->FUN_00232f60();
  if (!current) return false;
  int remaining = index;
  while (remaining > 0) {
   current = current->FUN_00232fe0();
   --remaining;
   if (!current) break;
  }
  FUN_00233ef0(source, current);
 }
 return object != 0 || (key == 0 && index < 0);
}
