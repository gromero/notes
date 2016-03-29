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
