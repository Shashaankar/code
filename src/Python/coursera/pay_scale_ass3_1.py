#!/bin/python

hrs = raw_input("Enter Hours:")
rate = raw_input("Enter pay rate:")
h = float(hrs)
pay_rate = float(rate)
tot_pay = 0

if h <= 40:
    tot_pay = pay_rate * h

if h > 40:
    tot_pay = 40 * pay_rate
    tot_pay += 1.5 * pay_rate * (h - 40)

print tot_pay
