import socket
import time

def test_speed():
    start_time = time.time()
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(('speedtest.tele2.net', 80))
    end_time = time.time()
    elapsed_time = end_time - start_time
    
    file_size_mb = 1
    download_speed_mbps = file_size_mb / elapsed_time
    
    with open("log.txt", "w") as file:
        file.write(str(download_speed_mbps)[:5])

if __name__ == "__main__":
    test_speed()
