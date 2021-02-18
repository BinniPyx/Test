import threading
import socket

shutdown=False
join=False

def receving (name,sock):
    while 1:
        try:
            while True:
                data,addr=sock.recvfrom(1024)
                print(data.decode("utf-8"))
        except:
            pass

host=socket.gethostbyname(socket.gethostname())
port=0

server=("213.87.161.104",9090)



s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((host,port))
#s.setblocking(0)

alias=input("Name ")

rt=threading.Thread(target=receving, args=("RecvThread",s))
rt.start()

while shutdown==False:
    if join==False:
        s.sendto(("["+alias+"]=>join chat ").encode("utf-8"),server)
        join=True
    else:
         try:
             message=input()

             if message !="":
                 s.sendto(("["+alias+"]: "+message).encode("utf-8"),server)

         except:
             print("Error")
             s.sendto(("["+alias+"]<=left chat ").encode("utf-8"),server)
             shutdown=True


rt.join()
s.close()
