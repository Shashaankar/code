#!/bin/python


import socket
import os
import time


UDP_IP = "127.0.0.1"
UDP_PORT = 6161

# UDP message of 1500 Bytes
MESSAGE = "12345"*300
message_count = 100000
loop_count = 0
start_time = 0
end_time = 0

print "UDP Speedtest target IP:", UDP_IP
print "UDP Speedtest target port:", UDP_PORT
print "message size:=", len(MESSAGE), "Bytes"

start_time = time.time()
while True:
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))

    # Terminate for every message_count pkts sent
    loop_count = loop_count+1
    if loop_count == message_count:
        end_time = time.time()
        print "Number of packets sent:=", loop_count, "; Bytes sent:=",\
        (loop_count * len(MESSAGE)) / 1000000, " MBytes"
        print "Time taken :=", end_time - start_time
        print "Upink data rate:=", ((loop_count * len(MESSAGE)) /
        1000000) / (end_time - start_time), " MBytes per second"
        break
