#!/usr/bin/python3
def safe_print_list_integers(my_list=[], x=0):
    count = 0
    for i in range(x):
        try:
            print("{:d}".format(my_list[i]), end="")
            count += 1
        except (ValueError, TypeError):
            pass
    print()
    return count

# Example usage:
my_list = [1, 'a', 2, 'b', 3]
count = safe_print_list_integers(my_list, len(my_list))
print("Number of integers printed:", count)
