class MyOperator:
	def __init__(self,num):
		self.num=num
	def __call__(self,right):
		self.num+=right
		print self.num


a = MyOperator(4)
a(5)
		