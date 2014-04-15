class MetaOne(type):
	def __new__(meta,classname,supers,classdict):
		print("in MetaOne.new",classname,supers,classdict,sep="\n")
		return type.__new__(meta,classname,supers,classdict)

class Eggs:
	pass

print("Making class")

class Spam(Eggs,metaclass=MetaOne):
	data = 1
	def meth(self,arg):
		pass

print("making instance")

X = Spam()
print('data：',X.data)
print(type(X)) 

#因为自定义的类对象 为 type类的实例，type定义了__call__.
#所以MetaOne为type的实例，有__call__的定义。
#所以Spam的结尾有MetaOne（XXXX）
#Spam的元类为MetaOne,所以类对象Spam为MetaOne的实例。
print(type(Spam))
