#! /bin/sh
​
SCRIPT="mkdir .ssh; cat ~/id_rsa.pub >> ~/.ssh/authorized_keys; rm ~/id_rsa.pub; exit"
​
for ip in 10.0.9.11 10.0.17.125 10.0.17.126 10.0.17.144 10.0.17.130 10.0.12.237 10.0.9.107 10.0.17.129 10.0.12.127
do
	scp ~/.ssh/id_rsa.pub ibrahima@"$ip":~
	ssh -l ibrahima ${ip} "${SCRIPT}"
done

