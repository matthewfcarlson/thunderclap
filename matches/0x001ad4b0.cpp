// Same code shape as 0x00066860 (propagated; names are from that function)
void FUN_00230b60();
struct Target { Target* Run(int); };
Target* Target::Run(int x) { FUN_00230b60(); return this; }