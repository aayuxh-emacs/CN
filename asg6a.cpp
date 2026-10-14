#SERVER
import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 5002))

server_socket.listen(1)
print("Server is listening on port 5000...")

conn, addr = server_socket.accept()
print(f"Connected to client: {addr}")

mode = conn.recv(1024).decode()

if mode == 'MATH':
    print("Client selected Mathematical Operations mode.")
    while True:
        data = conn.recv(1024).decode()

        if not data or data == 'EXIT':
            break

        parts = data.split(',')
        op = parts[0]
        n1 = float(parts[1])
        n2 = float(parts[2])

        res = 0
        if op == '1':
            res = n1 + n2
        elif op == '2':
            res = n1 - n2
        elif op == '3':
            res = n1 * n2
        elif op == '4':
            if n2 == 0:
                res = "Error: Division by zero"
            else:
                res = n1 / n2
        elif op == '5':
            res = n1 ** n2

        conn.send(str(res).encode())

elif mode == 'CHAT':
    print("Client selected Chatbot mode.")

    conn.send("What is your name?".encode())
    name = conn.recv(1024).decode()

    conn.send("What is your college?".encode())
    college = conn.recv(1024).decode()

    conn.send("What is your degree?".encode())
    degree = conn.recv(1024).decode()

    final_msg = f"Here are your combined inputs -> Name: {name}, College: {college}, Degree: {degree}\nquit"
    conn.send(final_msg.encode())

conn.close()
server_socket.close()
