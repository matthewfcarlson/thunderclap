// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000d3ef0 @ 0x000d3ef0
struct Thing { int first; int second; void FUN_000d3ef0(int a, int b); void FUN_000f7050(Thing*); };
Thing* thunk_FUN_000fc1b0();
void Thing::FUN_000d3ef0(int a, int b) {
    first = a;
    second = b;
    thunk_FUN_000fc1b0()->FUN_000f7050(this);
}