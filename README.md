##### On x64, stack is created quite similar to PPC64, i.e. "return address" is stored in caller's stack, not in callee:

```
(gdb) disas main
Dump of assembler code for function main:
   0x0000000000400501 <+0>:	push   %rbp
   0x0000000000400502 <+1>:	mov    %rsp,%rbp
   0x0000000000400505 <+4>:	callq  0x4004f6 <f>
   0x000000000040050a <+9>:	mov    $0x0,%eax
   0x000000000040050f <+14>:	pop    %rbp
   0x0000000000400510 <+15>:	retq
End of assembler dump.
(gdb) disas f
Dump of assembler code for function f:
   0x00000000004004f6 <+0>:	push   %rbp
   0x00000000004004f7 <+1>:	mov    %rsp,%rbp
   0x00000000004004fa <+4>:	mov    $0x0,%eax
   0x00000000004004ff <+9>:	pop    %rbp
   0x0000000000400500 <+10>:	retq
End of assembler dump.
(gdb)
```

##### Example 1: [vsldoi.c] (vsldoi.c)

This is an example of two things: 1) how `vsldoi` works and 2) how a 128-bit
vector can be populated out of two different 64-bit general purpose registers
using the VSX merge operation `xxmrghd`. The merge operation, although a
Vector-Scalar, can operate over Vector registers since VSX and VMX registers
overlap.

How `vsldoi` works is clear after inspecting the shift operations over a vector:

```
v1 = 0x00000000000000000000000000000000
v0 = 0x5555555555555555ffffffffffffffff

vsldoi  v2,v1,v0,8:
v1 || v0 = 0x000000000000000000000000000000005555555555555555ffffffffffffffff
v2       =                 0x00000000000000005555555555555555

vsldoi  v2,v0,v1,4:
v0 || v1 = 0x5555555555555555ffffffffffffffff00000000000000000000000000000000
v2       =         0x55555555ffffffffffffffff00000000
```
