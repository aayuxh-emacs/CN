import socket

N = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(("127.0.0.1", 8080))
s.listen(1)

print("Waiting for client...")

c, addr = s.accept()

msg = c.recv(N).decode()
print("Client:", msg)

reply = "Hello from server"
c.send(reply.encode())

c.close()
s.close()
