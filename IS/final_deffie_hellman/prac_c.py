import socket
import secrets

host = 'localhost'
port = 5000

client = socket.socket(socket.AF_INET , socket.SOCK_STREAM)

client.connect((host , port))

q=int(input("Enter a prime number (q): "))
a = int(input("Enter a primitive root of the prime number (a): "))


client.send(str(q).encode())
client.send(str(a).encode())
x_client = secrets.randbelow(q)
print("Private key of client is xClient = " , x_client)
y_client = pow(a , x_client , q)
print("Public key of client is yClient = " , y_client)
client.send(str(y_client).encode())
y_server = int(client.recv(1024).decode())
print("Public key of server is yServer = " , y_server)



shared_key = pow(y_server  , x_client  ,q )
print("Shared key is : " , shared_key)

client.close()





