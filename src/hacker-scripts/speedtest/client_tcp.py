#!/bin/python



import socket


TCP_IP = '127.0.0.1'
TCP_PORT = 6161
BUFFER_SIZE = 65535
MESSAGE = "12345"*300


print "Message length:=", len(MESSAGE)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
s.send(MESSAGE)
s.close()
