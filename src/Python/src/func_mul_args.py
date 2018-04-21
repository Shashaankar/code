#!/usr/bin/python

def bar(first, second, third, **options):
    if options.get("action") == "sum":
        print "The sum is: %d" % (first + second + third)

    if options.get("number") == "first":
        return first

    print options


def foo(first, second, third, *options):
    print "first %s" % first
    print "second %s" % second
    print "third %s" % third

    print list(options)

result = bar(1, 2, 3, action = "sum", number = "first")
print "Result: %d" % result

foo(4,5,6,7,8)
