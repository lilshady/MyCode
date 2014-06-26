def GetAllPossibleValues(target,result):
	if result:
		return [i for i in range(1,target-sum(result)+1)]
	else:
		return [i for i in range(1,target+1)]

def samelist(a,b):
	a=list(a)
	b=list(b)
	a.sort()
	b.sort()
	if not len(a) == len(b):
		return False
	for i in range(len(a)):
		if not a[i] == b[i]:
			return False
	return True

def GetAllPartition(target,result,result_set):
	if sum(result)==target:
		if not list(filter(lambda s: samelist(s,result),result_set)):
			result_set.append(tuple(result))
	else:
		temp = GetAllPossibleValues(target,result)
		#print temp
		for i in temp:
			result.append(i)
			GetAllPartition(target,result,result_set)
			result.pop()

n = 15
result = []
resultset =[]
GetAllPartition(n,result,resultset)
print resultset