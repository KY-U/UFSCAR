import socket

HOST = "127.0.0.1"  #endereço de interface de loopback padrão(localhost)
PORT = 65432        #ports sem privilégio são > 1023
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:    #ipv4/tcp
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"{addr} conectou")
        while True:
            data = conn.recv(1024)
            if not data:
                break
            resposta = str(data.decode()) + ' muito bom'
            conn.sendall(resposta.encode())
