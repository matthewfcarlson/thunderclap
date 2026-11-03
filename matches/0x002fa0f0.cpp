extern void __cdecl ReleaseThing(int);
extern void __cdecl DoPair(int, int);
struct Target_2fa0f0 {
    int first;
    int second;
    int pad;
    int third;
};
void __fastcall FUN_002fa0f0(Target_2fa0f0* object) {
    if (object->third != 0)
        ReleaseThing(object->third);
    if (object->first != 0) {
        DoPair(object->first, object->second);
        ReleaseThing(object->first);
    }
}