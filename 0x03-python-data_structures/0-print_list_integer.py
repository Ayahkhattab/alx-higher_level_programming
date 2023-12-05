i#!/usr/bin/python3
def print_list_integer(_list=[]):
    for i in _list:
        print('{:d}'.format(i))

vi 1-element_at.py

#!/usr/bin/python3
def element_at(my_list, idx):
    return(my_list[idx] if 0 <= idx < len(my_list) else "None")
