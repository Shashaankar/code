#!/bin/python


import socket
import os
import time

UDP_IP = "127.0.0.1"
SPEEDTEST_PORT = 6161
MAX_RECV_SIZE = 65535

recv_size = 0
recv_cnt = 0
max_recv_cnt = 100000
start_time = 0
end_time = 0

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, SPEEDTEST_PORT))

print "Speedtest server listening ... "

while True:
    data, addr = sock.recvfrom(MAX_RECV_SIZE) 
    data_len = len(data)
    recv_size = recv_size + data_len


    # Terminate loop condition
    recv_cnt = recv_cnt + 1
    if recv_cnt == max_recv_cnt:
        print "Number of packets received:=", recv_cnt
        print "Total data size:=", recv_size/1000000, " Mbytes"

        break

