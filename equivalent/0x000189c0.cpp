// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000189c0 @ 0x000189c0
void __cdecl FUN_003442bc(); // equiv-conv: FUN_003442bc st0
float __cdecl FUN_000189c0(float value)
{
    volatile float clamped = value;
    if (clamped < -1.0f) clamped = -1.0f;
    else if (clamped > 1.0f) clamped = 1.0f;
    FUN_003442bc();
    return clamped;
}