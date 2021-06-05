#!/usr/bin/env python3

from heltal import Heltal
from time import perf_counter
import matplotlib.pyplot as plt

def main():
	value = 35


	start_fib_py = perf_counter()
	print(fib_py(value))
	end_fib_py = perf_counter()
	print(f"Python process took {round(end_fib_py - start_fib_py, 2)} seconds")

	f = Heltal(value)

	start_fib_c = perf_counter()
	print(f.fib())
	end_fib_c = perf_counter()
	print(f"c++ process took {round(end_fib_c - start_fib_c, 2)} seconds")


def timetaking(lower_bound, upper_bound):
	data = []
	for x in range(lower_bound, upper_bound):
		mystart = perf_counter()
		fib_py(x)
		myend = perf_counter()

		f = Heltal(x)

		newstart = perf_counter()
		fib_c(f)
		newend = perf_counter()

		data.append((x, round(myend - mystart, 2), round(newend - newstart, 2)))
	plt.scatter(data[0], data[1], c="b", label="Only Python")
	plt.scatter(data[0], data[2], c="r", label="Running in c++")
	plt.legend(loc="upper left")
	plt.savefig("Fib_times.png")


def fib_py(n):
	if n <= 1:
		return n
	else:
		return fib_py(n-1) + fib_py(n-2)
	

def fib_c(f):
	return f.fib()




if __name__ == '__main__':
	#main()

	timetaking(10,33)