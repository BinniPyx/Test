import socket

host=socket.gethostbyname(socket.gethostname())
port=9090

clients=[]

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((host,port))

quit=False
print("Server Start")

while not quit:
    try:
        data, addr=s.recvfrom(1024)

        if addr not in clients:
            clients.append(addr)
            print(data.decode("utf-8"))
        for client in clients:
            print(data.decode("utf-8"))
            if addr!=client:
                s.sendto(data,client)

    except:
        print("\n Server Stopped")
        quit=True
s.close
