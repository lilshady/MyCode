filename = raw_input("the file name")

Lines = [line.rstrip() for line in open(filename)]

newfilename = "D:\\testnew.txt"

with open(newfilename,'w') as temp:
	temp.write(' '.join(Lines))