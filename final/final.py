import random

def avg(nums):
	return sum(nums) / 100

def greaterCount(nums, avg):
	count = 0
	for i in nums:
		if (i > avg):
			count+=1
	return count

def getRandomNum(min, max):
	return random.randint(min, max)

nums = []
for i in range(100):
	nums += [random.randint(-11, 83)]

print(nums)

print("Average: ", avg(nums), " Count: ", greaterCount(nums, avg(nums)))