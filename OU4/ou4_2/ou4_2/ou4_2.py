#!/usr/bin/env python3

from heltal import Heltal
from time import perf_counter

def main():
	f = Heltal(5)
	print(f.get())
	f.set(7)
	print(f.get())




def fib_py(n):
	if n <= 1:
		return n
	else:
		return fib_py(n-1) + fib_py(n-2)
	

def fib_c(f):
	return f.fib()

if __name__ == '__main__':
	value = 10


	start_fib_py = perf_counter()
	print(fib_py(value))
	end_fib_py = perf_counter()
	print(f"Python process took {round(start_fib_py - end_fib_py, 2)} seconds")

	f = Heltal(value)

	start_fib_c = perf_counter()
	print(f.fib())
	end_fib_c = perf_counter()
	print(f"c++ process took {round(start_fib_c - end_fib_c, 2)} seconds")

