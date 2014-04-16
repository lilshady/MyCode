class Person:
	def __init__(self, name, job=None, pay=0):
		self.name = name
		self.job = job
		self.pay = pay
	def lastName(self):
		return self.name.split()[-1]
	def giveRaise(self,percent):
		self.pay = int(self.pay*(1+percent))
	def __str__(self):
		return "[name:%s,job:%s,pay:%d]" %(self.name,self.job,self.pay)
class Manager(Person):
	def giveRaise(self,percent,bonus=.10):
		Person.giveRaise(self,percent+bonus)

if __name__ == "__main__":

    bob = Person("bob Fuck")
    print bob.name,bob.job,bob.pay

    julia = Manager("julia Fuck",job="manger",pay=100)
    print julia.name,julia.lastName()
    julia.giveRaise(0.1)
    print julia.pay
    print julia