import time
n=(input("Enter the number of men/women:\t"))
men = dict([(raw_input('Enter the name of man:\t').strip(), raw_input('Enter the preference list:\n').split()[::-1]) for i in range(n)])
women = dict([(raw_input('Enter the name of woman:\t').strip(), raw_input('Enter the preference list:\n').split()) for i in range(n)])
pairs = {}
not_engaged = set(men)
start=time.clock()
while not_engaged:
    man = not_engaged.pop()
    if men[man] == []:
        print('No stable match exists')
        break
    woman = men[man].pop()
    if woman in pairs:
        if women[woman].index(pairs[woman]) > women[woman].index(man):
            not_engaged.add(pairs[woman])
            pairs[woman] = man
        else:
            not_engaged.add(man)
    else:
        pairs[woman]=man
else:
    for i in pairs:
        print (pairs[i],'is paired with',i)
end=time.clock()
print ("The program ran for: ",end-start,"seconds")
