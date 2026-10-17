// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033e1b0 @ 0x0033e1b0
int __cdecl FUN_00339dc0(int,int);
int __cdecl FUN_00212d70(int,...);
int __cdecl FUN_002139f0(int,int,int,int);
void __cdecl FUN_00213520(int,...);
void __cdecl FUN_00212e20(int,...);
void __cdecl FUN_0033e1b0(int handle) {
    FUN_00339dc0(handle,1);
    int count = FUN_00212d70(handle,-1,0);
    int result = FUN_002139f0(handle,count-1,-1,0);
    FUN_00213520(handle,result==0,handle,count-1,-1,0);
    FUN_00212e20(handle,1,handle,result==0,handle,count-1,-1,0);
    FUN_00212d70(handle,handle,1,handle,result==0,handle,count-1,-1,0);
}