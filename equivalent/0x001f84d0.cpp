// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 15/18, incomplete)
// FUN_001f84d0 @ 0x001f84d0
struct Key { unsigned int low; unsigned int high; signed char category; signed char subcategory; bool FUN_001f84d0(const Key *other); };
bool Key::FUN_001f84d0(const Key *other) {
    if (category < other->category) return true;
    if (category > other->category) return false;
    if (high < other->high) return true;
    if (high > other->high) return false;
    if (low < other->low) return true;
    if (low > other->low) return false;
    return subcategory < other->subcategory;
}