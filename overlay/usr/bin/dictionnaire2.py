#!/usr/bin/env python3

dic = {'gilles':12,'remi':21,'zoe':54,'mohamed':100,'annie':0,'edward':89};
dic2={};

# tri par clefs
for i in sorted(dic.keys()):
	print(i,":",dic[i]);
	
print("\n");

# tri par valeurs	
for j in sorted(dic.values()):
	for k in dic.keys():
		# elimination des doublons de clefs
		if j==dic[k]:
			dic2[k]=j;
			
# affichage par valeurs triées avec doublons éliminés
for i in dic2.keys():
	print(i,":",dic2[i]);
