import socket
import secrets



port = 5000
host = 'localhost'


server = socket.socket(socket.AF_INET , socket.SOCK_STREAM)

server.bind((host,port))
print("Listening on port : " , port)
server.listen(1)
client_socket , addr = server.accept()

q = int(client_socket.recv(1024).decode())
print("Value of q is : " , q)
a= int(client_socket.recv(1024).decode())
print("Primitive root of q is a  =  " , a)

x_server = secrets.randbelow(q)
y_server = pow(a , x_server , q )
print("Public key of server is Yserver = " , y_server)

client_socket.send(str(y_server).encode())

y_client = int(client_socket.recv(1024).decode())
print("Public key of client received is  = " , y_client)
shared_key = pow(y_client,  x_server , q)


print("Shared key generated is = " , shared_key)
client_socket.close()
server.close()
