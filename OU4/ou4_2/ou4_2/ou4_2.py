#!/usr/bin/env python3

from heltal import Heltal


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
	return f.getfib()

if __name__ == '__main__':
	print(fib_py(10))

	f = Heltal(10)
	print(fib_c(f))