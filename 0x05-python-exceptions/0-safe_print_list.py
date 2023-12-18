#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    num = 0
    for i in range(x):
        try:
            print(my_list[i], end="")
            num += 1
        except IndexError:
            break
    print("")
    return num

# Example usage:
my_list = [1, 2, 3, 4, 5]
num_items = safe_print_list(my_list, 3)
print("Number of items printed:", num_items)
