partiton_list = []
one_list = []

def allisone(l):
    for i in l:
        if not (i == 1):
            return False
    return True

def patrtitonnumber(number):
    partiton_list.append(number)
    themin = 0
    print partiton_list
    print one_list
    print "-------------------" 
    while not allisone(partiton_list):
        partiton_list.sort()
        for i in range(len(partiton_list)):
            if partiton_list[i] > 1:
                themin = partiton_list[i]
                partiton_list[i] -= 1
                break;
        
        one_list.append(1)
        one_list.sort()
        asum = 0
        count = 0
        
        for i in one_list:
            asum += i
            if (asum == themin - 1):
                partiton_list.append(asum)
                asum = 0
                count += themin - 1
        while count:
            one_list.pop()
            count -= 1
        print partiton_list
        print one_list
        print "-------------------"
patrtitonnumber(4)