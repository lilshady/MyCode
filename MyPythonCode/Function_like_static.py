def test():
	test.a += 1
	print "this is cool"

def func(x=[]):
	x.append(1)
	print x

test.a = 0;
test()
print test.a
test()
print test.a

func([3,3])
func()
func()
func()

