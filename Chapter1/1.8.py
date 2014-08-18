
s1 = "hello"
s2 = "llohe"

print "Checking whether s2 is a rotation of s1"

s2_new = s2+s2

if(s1 in s2_new):
	print "s2 is a rotation"
else:
	print "Not a rotation"