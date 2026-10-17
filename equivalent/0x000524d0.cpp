// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 9/10, incomplete)
// CGrappleFightNodeTimeCondition::vfunc_7 @ 0x000524d0
struct Result { char pad[0xdc]; };
struct Node { char pad[0x330]; Result* first; Result* second; Result* third; };
struct Intermediate { Node* FUN_00059a30(); };
struct Input { Intermediate* FUN_000592a0(); };
struct CGrappleFightNodeTimeCondition {
    Result* vfunc_7(Input* input);
};
Result* CGrappleFightNodeTimeCondition::vfunc_7(Input* input) {
    if (!input) return 0;
    Node* node = input->FUN_000592a0()->FUN_00059a30();
    Result* result = node->second;
    if (!result) result = node->first;
    if (!result) result = node->third;
    if (!result) return 0;
    return (Result*)((char*)result + 0xdc);
}