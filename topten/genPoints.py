import math
import random
if __name__ == "__main__":
	file = open("input.txt","w")
	ps = []
	random.seed()
	#low = -4294967295
	#high = 4294967295
	low = -65536
	high = 65536
	for i in range(1,10000):
		x = random.randint(low,high)
		y = random.randint(low,high)
		z = random.randint(low,high)
		file.write("%d %d %d\n" % (x,y,z))
	file.close()
