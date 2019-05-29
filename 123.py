with open("chars_16") as f:
	content = f.readlines()
content = [x.strip() for x in content]
for i,z in enumerate(content):
	if z!='':
		content[i] = int(z,2)
for i in range(len(content)):
	print(content[i],end =",")

