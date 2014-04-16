import smtplib  
from email.Message import Message  
from time import sleep  
import socket
import time
from netifaces import interfaces, ifaddresses, AF_INET

smtpserver = ''  
username = ''  
password = ''  
from_addr = ''  
to_addr = ''  

message = Message()  
message['Subject'] = 'IP'
message['From'] = from_addr   
message['To'] = to_addr   

str_ip_addr = socket.gethostname() + '\n' +  time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()) + '\n'
for ifaceName in interfaces():
    addresses = [i['addr'] for i in ifaddresses(ifaceName).setdefault(AF_INET, [{'addr':'No IP addr'}] )]
    str_ip_addr += ifaceName + ': ' + ', '.join(addresses) + '\n'
message.set_payload(str_ip_addr)
msg = message.as_string()  

sm = smtplib.SMTP(smtpserver, port=587, timeout=20)  
#sm.set_debuglevel(1)
sm.ehlo()  
sm.starttls()
sm.ehlo()  
sm.login(username, password)  
sm.sendmail(from_addr, to_addr, msg)  
sm.quit()
