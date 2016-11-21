# HITCON-Training
For Linux binary Exploitation

## Environment Setup

    git clone https://github.com/scwuaptx/HITCON-Training.git ~/
    cd HITCON-Training && chmod u+x ./env_setup.sh && ./env_setup.sh

## Outline

+ Basic Knowledge
	+ Introduction
		+ Reverse Engineering
			+ Static Analysis
			+ Dynamic Analysis 
		+ Exploitation
		+ Useful Tool
			+ IDA PRO
			+ GDB
			+ Pwntool
		+ lab 1 - sysmagic
	+ Section
	+ Compile,linking,assmbler
	+ Execution
		+ how program get run
		+ Segment 
	+ x86 assembly
		+ Calling convention 
		+ lab 2 - open/read/write
		+ shellcoding
+ Stack Overflow
	+ Buffer Overflow
	+ Return to Text/Shellcode
		+ lab 3 - ret2shellcode 
	+ Protection
		+ ASLR/DEP/PIE/StackGuard
	+ Lazy binding
	+ Return to Library
		+ lab 4 - ret2lib 
+ Return Oriented Programming
	+ ROP
		+ lab 5 - simple rop 
	+ Using ROP bypass ASLR
		+ ret2plt
	+ Stack migration
		+ lab 6 - migration
+ Format String Attack
	+ Format String 
	+ Read from arbitrary memory
		+ lab 7 - crack
	+ Write to arbitrary memory
		+ lab 8 - craxme
	+ Advanced Trick
		+ EBP chain 
		+ lab 9 - playfmt 
+ x64 Binary Exploitation
	+ x64 assembly
	+ ROP
	+ Format string Attack

+ Heap exploitation
	+ Glibc memory allocator overview
	+ Vulnerablility on heap
		+ Use after free
			+ lab 10 - hacknote
		+ Heap overflow 
			+ house of force 
				+ lab 11 - 1 - bamboobox1
			+ unlink
				+ lab 11 - 2 - bamboobox2
+ Advanced heap exploitation
	+ Fastbin attack
		+ lab 12 - babysecretgarden 
	+ Shrink the chunk
	+ Extend the chunk
		+ lab 13 -  heapcreator
	+ Unsortbin attack
		+ lab 14 - magicheap
+ C++ Exploitation
	+ Name Mangling 
	+ Vtable fucntion table
	+ Vector & String
	+ New & delete
	+ Copy constructor & assignment operator
		+ lab 15 - zoo 
+ 那些 Pwning 的奇淫技巧:
