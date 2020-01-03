import subprocess

for i in range(10, 14):
	for j in range(1, 256):
		p = subprocess.call('ping -c 1 10.10.' + str(i) + '.' + str(j) + ' > ip.txt', shell=True)
		f = open('ip.txt').read()
		if not "100% packet" in f:
			print('10.10.' + str(i) + '.' + str(j))
