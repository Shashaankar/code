#!/bin/python

import socket

TCP_IP = '127.0.0.1'
TCP_PORT = 6161
BUFFER_SIZE = 65535

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(10)

conn, addr = s.accept()
print 'Client address:', addr
while 1:
    data = conn.recv(BUFFER_SIZE)
    if not data: break
    print "received data:", data
    conn.close()
