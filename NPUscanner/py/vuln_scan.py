import socket
import sys

# 获取命令行参数列表
args = sys.argv


def Get_version_of_openssh(ip):
    sock.connect((ip, 22))

    data = sock.recv(1024)  # 一次最多接收1024字节的数据
    if b"OpenSSH" in data:
        version_1 = data.split(b"-OpenSSH_")[0]
        if version_1 == b'SSH-2.0':
            version_2 = data.split(b"-OpenSSH_")[1][:3]
            print(version_2.decode())
        
    sock.close()  # 关闭套接字连接

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = args[1]

Get_version_of_openssh(ip)


