import socket

HOST = "127.0.0.1"  #hostname ou IP address do servidor
PORT = 65432        #port utilizada pelo servidor

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:    #ipv4/tcp
    s.connect((HOST, PORT))
    s.sendall(b'Jungkook cozinheiro')
    print('Mandei um Jungkook cozinheiro')
    data = s.recv(1024).decode()
print(f"Recebi um {data}")
