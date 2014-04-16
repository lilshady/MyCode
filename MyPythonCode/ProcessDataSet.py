inputfile = open("D:\\u.data")
output = open("D:\\result_20.data",'w')
statis = {}
for line in inputfile:
	l=line.split('\t')
	count=statis.get(l[1],0)
	if count == 0:
		statis[l[1]] = 1
	else:
		statis[l[1]] +=1
inputfile.close()
inputfile = open("D:\\u.data")
L=[]
for line in inputfile:
	
	l=line.split('\t')
	if statis[l[1]] >= 20:
		L.append(line)
output.writelines(L)




