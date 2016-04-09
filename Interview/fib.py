#!/usr/bin/env python


def fibonacci(num):
    if num == 1 or num == 2:
        return 1;
    return fibonacci(num-1) + fibonacci(num-2)


def fibLoop(num):
    if num == 1 or num == 2:
        return 1;
    fib1 = 1
    fib2 = 1 
    total = 1
    for i in range(0,3):
        total = fib1+fib2
        fib1 = fib2
        fib2 = total
    return total

print(fibonacci(5));
print(fibLoop(5));

