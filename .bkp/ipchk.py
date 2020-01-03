import subprocess
import os

f = open('ips')
s = f.readline()
while s :
	subprocess.call('curl ' + s.split('\n')[0] + ' 2> err > out', shell=True)
	try:
		f1 = open('err').read()
		if not 'Failed' in f1:
			print(s.split('\n')[0])
		os.remove('err');
	except:
		pass
	s = f.readline()
