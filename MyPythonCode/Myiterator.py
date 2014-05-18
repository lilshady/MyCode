class Myiterator:
	def __init__(self):
		self.value = 0
	def __iter__(self):
		return self
	def  next(self):
		self.value += 1
		return self.value

obj = Myiterator()
i = iter(obj)
print i.next()
for i in obj:
	if i == 10:break
	print i,'\n'