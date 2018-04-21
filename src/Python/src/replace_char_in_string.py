#!/usr/bin/python

def replace_char_at(my_string, index, char):
    my_string = my_string[:index] + my_string[index:index+1].replace(my_string[index], char) + my_string[index+1:]
    return my_string


# index starts at 0, ends at len(str)-1
print replace_char_at("hello", 1, "T")
