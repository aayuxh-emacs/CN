#CLIENT
import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 5002))

print("Select Mode:")
print("1. Mathematical Operations")
print("2. Chatbot Application")
choice = input("Enter your choice (1 or 2): ")

if choice == '1':
    client_socket.send("MATH".encode())

    while True:
        print("\n--- Math Menu ---")
        print("1. Addition")
        print("2. Subtraction")
        print("3. Multiplication")
        print("4. Division")
        print("5. Power")
        print("6. Exit")

        op = input("Choose operation (1-6): ")

        if op == '6':
            client_socket.send("EXIT".encode())
            break

        n1 = input("Enter first number: ")
        n2 = input("Enter second number: ")

        req = f"{op},{n1},{n2}"
        client_socket.send(req.encode())

        ans = client_socket.recv(1024).decode()
        print(f"\nResult from server: {ans}")

elif choice == '2':
    client_socket.send("CHAT".encode())
    print("\nChatbot started.")

    while True:
        reply = client_socket.recv(1024).decode()

        if 'quit' in reply.lower():
            final_output = reply.replace('\nquit', '').replace('quit', '')
            print(f"Chatbot: {final_output}")
            break

        print(f"Chatbot: {reply}")

        msg = input("You: ")
        client_socket.send(msg.encode())

client_socket.close()
